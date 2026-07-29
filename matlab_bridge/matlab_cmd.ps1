<#
.SYNOPSIS
    Send a command to MATLAB via COM bridge and return the output.
.DESCRIPTION
    Wraps matlab_com.py for easy PowerShell use.
    Keeps MATLAB running between calls for performance.
.EXAMPLE
    .\matlab_cmd.ps1 "a = 1+2; disp(a)"
    .\matlab_cmd.ps1 "sim('my_model')"
    .\matlab_cmd.ps1 --close
#>

param(
    [Parameter(ValueFromRemainingArguments=$true)]
    [string[]]$CommandParts
)

$command = $CommandParts -join " "
$bridgeDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$pyScript = Join-Path $bridgeDir "matlab_com.py"

if (-not $command) {
    Write-Host "Usage: .\matlab_cmd.ps1 <MATLAB command>" -ForegroundColor Yellow
    Write-Host "       .\matlab_cmd.ps1 --close" -ForegroundColor Yellow
    exit 1
}

$result = python $pyScript $command 2>&1
try {
    $json = $result | ConvertFrom-Json
    if ($json.success) {
        Write-Host $json.output
    } else {
        Write-Host "ERROR: $($json.output)" -ForegroundColor Red
    }
} catch {
    Write-Host $result
}
