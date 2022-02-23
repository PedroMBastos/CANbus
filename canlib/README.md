# Altran CAN Lib

This is Altran's implementation of an CAN socket user interface for C.
This project is still heavly based on the CAN Festival project https://github.com/ljessendk/CanFestival.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

## Prerequisites

Any Linux distribution;
the following packages installed: build-essentials, Autoconf, CMake, and GCC;


### Install CAN Utils
```
git clone https://github.com/linux-can/can-utils.git
cd can-utils
./autogen.sh
./configure
make
sudo make install
```

### Set VCAN Interface

```
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
```

### Build the lib and examples

```
mkdir build
cd build
cmake ..
make
```

After this, you can have access to the example in output/bin and the lib in output/lib


## Running the tests



## Authors

* **Bruno Laranjo** - *Initial work* - [PurpleBooth](brunolaranjo.santos@altran.com)

## License

This project is to be used internaly inside Altran for the moment.

## Acknowledgments

* Meetup Team
* Altran
* Edwards Project
