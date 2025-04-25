Write-Host "Running..."

$buildDir = "../build"
$exeFile = "../build/main.exe"

if (-not(Test-Path -Path $buildDir) -or -not(Test-Path -Path $exeFile)) {
    Write-Host "Error: Build Does Not Exist..."
    & "./build.ps1"
    Write-Host "Running..."
}

Invoke-Expression $exeFile
