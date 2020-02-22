#!/usr/bin/env bash

set -eu
set -o pipefail

dotnet tool restore --verbosity quiet
dotnet paket restore --silent
dotnet fake run build.fsx "$@"
