<#
.SYNOPSIS
    Creates a new project file with standardized naming: [ProjectNo]_[Date].ext
.PARAMETER ProjectNo
    Project number, e.g. "PRJ-001"
.PARAMETER Extension
    File extension, defaults to "md"
.EXAMPLE
    .\new-project.ps1 PRJ-001 md
    # Creates: D:\FOC 2\projects\PRJ-001_2026-07-29.md
#>

param(
    [Parameter(Mandatory=$true)]
    [string]$ProjectNo,
    [string]$Extension = "md"
)

$date = Get-Date -Format "yyyy-MM-dd"
$fileName = "${ProjectNo}_${date}.${Extension}"
$filePath = Join-Path "D:\FOC 2\projects" $fileName

if (Test-Path $filePath) {
    Write-Host "[Warning] $filePath already exists. Opening existing file." -ForegroundColor Yellow
} else {
    $content = @"
# $ProjectNo - $date

## Summary

<!-- Project details go here -->

## Changes

- $(Get-Date -Format "yyyy-MM-dd HH:mm:ss"): File created

"@
    $content | Out-File -FilePath $filePath -Encoding UTF8
    Write-Host "[Created] $filePath" -ForegroundColor Green
}

# Stage and commit
Set-Location "D:\FOC 2"
git add $filePath 2>&1 | Out-Null
$commitMsg = "New project file: $fileName"
git commit -m $commitMsg 2>&1 | Out-Null

Write-Host "[Committed] $commitMsg" -ForegroundColor Cyan
Write-Host "File ready: $filePath" -ForegroundColor Green
