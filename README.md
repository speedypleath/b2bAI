# b2bAI
b2bAI is an audio plugin used to generate MIDI sequences using genetic algorithms. 

## Dependencies

Tested on Debian 11 ARM

* CMake 3.23
* Make 4.3
* Python 3.10 (dev)

## Clang

### Linux
```bash
sudo apt-get install clang
```

### Mac
```bash
xcode-select -install
```

## Juce

### Linux
```
sudo apt-get install libasound2-dev libjack-jackd2-dev \
    ladspa-sdk \
    libcurl4-openssl-dev  \
    libfreetype6-dev \
    libx11-dev libxcomposite-dev libxcursor-dev libxcursor-dev libxext-dev libxinerama-dev libxrandr-dev libxrender-dev \
    libwebkit2gtk-4.0-dev \
    libglu1-mesa-dev mesa-common-dev
```

## Boost

### Mac \ Linux

```
wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.bz2
tar --bzip2 -xf boost_1_79_0.tar.bz2

rm boost_1_79_0.tar.bz2
cd boost_1_79_0

./bootstrap.sh --prefix=/usr/~ --with-toolset=clang --with-python-version=3.10
./b2
sudo ./b2 install
```

# Build
## CMake targets
```
make all
```

### Configure
```
make config
```

### Build library
```
make build-lib
```

### Build
```
make build
```

### Test
```
make test
```

### Clean
```
make clean
```
