<#
.SYNOPSIS
    Watches the projects folder for file changes and auto-commits to git.
.DESCRIPTION
    Monitors D:\FOC 2\projects\ for any file changes (create, modify, delete).
    When a change is detected, it stages the file, commits with a timestamp message,
    and the post-commit hook automatically pushes to GitHub.
#>

$watchPath = "D:\FOC 2\projects"
$repoPath = "D:\FOC 2"

Write-Host "[Watcher] Monitoring $watchPath for changes..." -ForegroundColor Cyan
Write-Host "[Watcher] Press Ctrl+C to stop." -ForegroundColor Cyan

$watcher = New-Object System.IO.FileSystemWatcher
$watcher.Path = $watchPath
$watcher.IncludeSubdirectories = $true
$watcher.EnableRaisingEvents = $true
$watcher.NotifyFilter = [System.IO.NotifyFilters]::FileName -bor
                        [System.IO.NotifyFilters]::LastWrite -bor
                        [System.IO.NotifyFilters]::DirectoryName

$action = {
    $path = $Event.SourceEventArgs.FullPath
    $changeType = $Event.SourceEventArgs.ChangeType
    $name = $Event.SourceEventArgs.Name
    
    # Skip temp files and git internals
    if ($name -match '\.tmp$|\.temp$|~$|\.git') { return }
    
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    Write-Host "[$timestamp] $changeType : $name" -ForegroundColor Yellow
    
    # Debounce: wait 1 second for write to finish
    Start-Sleep -Milliseconds 1000
    
    # Stage the file and commit
    Set-Location $repoPath
    git add -A 2>&1 | Out-Null
    $commitMsg = "auto: $changeType $name at $timestamp"
    git commit -m $commitMsg 2>&1 | Out-Null
    
    Write-Host "[$timestamp] Committed: $name" -ForegroundColor Green
}

$handlers = @(
    Register-ObjectEvent $watcher "Created" -Action $action
    Register-ObjectEvent $watcher "Changed" -Action $action
    Register-ObjectEvent $watcher "Deleted" -Action $action
    Register-ObjectEvent $watcher "Renamed" -Action $action
)

try {
    while ($true) { Start-Sleep -Seconds 1 }
}
finally {
    $handlers | ForEach-Object { Unregister-Event $_.Name }
    $watcher.Dispose()
    Write-Host "[Watcher] Stopped." -ForegroundColor Cyan
}
