Write-Host "Building..."

$buildDir = "../build"
if (-not (Test-Path -Path $buildDir)) {
    New-Item -ItemType Directory -Path $buildDir
}

g++ ../src/main.cpp ../src/HashTable.cpp ../src/NaiveTable.cpp ../src/MultiplicationTable.cpp ../src/MidSquareTable.cpp -o $buildDir/main.exe

Write-Host "Build Complete"
