set windows-shell := ["pwsh", "-NoLogo", "-Command"]

default:
    @just --list

conan:
    conan install . -pr debug --build=missing

config:
    cmake --preset conan-default

build: config
    cmake --build build --config Debug

test: build
    ctest --test-dir build -C Debug