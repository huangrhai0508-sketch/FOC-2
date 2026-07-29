<#
.SYNOPSIS
    Closed-loop verification: tests MATLAB COM -> script -> execution -> output chain.
#>

$ErrorActionPreference = "Stop"
$bridgeDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$pyScript = Join-Path $bridgeDir "matlab_com.py"

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  MATLAB COM Closed-Loop Verification" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

$tests = @(
    @{Name="Basic arithmetic"; Cmd="a = 2+3; disp(a)"},
    @{Name="Matrix operation"; Cmd="A = [1 2; 3 4]; detA = det(A); disp(['det(A)=' num2str(detA)])"},
    @{Name="Simulink check"; Cmd="tf = license('test','Simulink'); disp(['Simulink license: ' num2str(tf)])"},
    @{Name="Control Toolbox"; Cmd="tf_ctrl = license('test','Control_Toolbox'); disp(['Control: ' num2str(tf_ctrl)])"},
    @{Name="Transfer function"; Cmd="s = tf('s'); G = 1/(s^2 + 2*s + 1); [num,den] = tfdata(G,'v'); disp(['TF: ' mat2str(num) ' / ' mat2str(den)])"}
)

$passed = 0
$failed = 0

foreach ($test in $tests) {
    Write-Host "[TEST] $($test.Name)..." -NoNewline
    $result = python $pyScript $test.Cmd 2>&1
    try {
        $json = $result | ConvertFrom-Json
        if ($json.success) {
            Write-Host " PASS" -ForegroundColor Green
            Write-Host "       $($json.output.Trim())" -ForegroundColor DarkGray
            $passed++
        } else {
            Write-Host " FAIL" -ForegroundColor Red
            Write-Host "       $($json.output)" -ForegroundColor Red
            $failed++
        }
    } catch {
        Write-Host " FAIL (parse)" -ForegroundColor Red
        $failed++
    }
}

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Results: $passed passed, $failed failed" -ForegroundColor $(if ($failed -eq 0) {"Green"} else {"Red"})
Write-Host "========================================" -ForegroundColor Cyan
