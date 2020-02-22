@echo off
dotnet tool restore --verbosity quiet
dotnet paket restore --silent
dotnet fake run build.fsx %*
