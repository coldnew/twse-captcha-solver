# twse-captcha-solver
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/coldnew/twse-captcha-solver/master/LICENSE)

A simple captcha solver for Taiwan Stock Exchange's [website](http://bsr.twse.com.tw/bshtm/). The algorithm is based on [hhschu](https://github.com/hhschu/Captcha_OCR)'s python method.

This project is written in C++, if you want java version, you can take a look at [coldnew/twse-captcha-solver-java](https://github.com/coldnew/twse-captcha-solver-java).

## Requirement

To build this application, you need to install following libraries:

- [OpenCV](https://opencv.org) 2.x
- [Tesseract](https://github.com/tesseract-ocr/tesseract)

If you use Gentoo Linux, just use following command to install required packages:

```sh
emerge media-libs/opencv app-text/tesseract
```

## Building

By default, this application will display the image processing result via opencv's highui function, you can disable this feature by add **-DEANBLE_HIGUI=OFF** in your cmake build.

If you just want to get the captcha result and don't want do see any GUI display, just use following command to build this application:

```sh
mkdir build && cd $_
cmake -DEANBLE_HIGUI=OFF ..
make -j9
```

## Usage

You need to download the captcha image manually from [website](http://bsr.twse.com.tw/bshtm/), execute the tool in command line:

```sh
./twse-captcha-solver xxx.png
```

## Screenshot

![Screenshot](https://github.com/coldnew/twse-captcha-solver/raw/master/screenshot.png)

## Note

This application **ONLY** work on captcha like this:

![Sample](https://github.com/coldnew/twse-captcha-solver/raw/master/sample.png)

## License

Copyright © 2017 Yen-Chin, Lee <<coldnew.tw@gmail.com>>

Distributed under the [MIT License](http://opensource.org/licenses/MIT).
