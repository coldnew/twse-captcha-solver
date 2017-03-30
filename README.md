# twse-captcha-solver
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/coldnew/twse-captcha-solver/master/LICENSE)

A simple captcha solver for Taiwan Stock Exchange's [website](http://bsr.twse.com.tw/bshtm/). The algorithm is based on [hhschu](https://github.com/hhschu/Captcha_OCR)'s python method.

## Requirement

To build this application, you need to install following libraries:

- [OpenCV 2.x](https://opencv.org)
- [tesseract](https://github.com/tesseract-ocr/tesseract)

If you use Gentoo Linux, just use following command to install required packages:

```sh
emerge media-libs/opencv app-text/tesseract
```

## Usage

You need to download the captcha image manually from [website](http://bsr.twse.com.tw/bshtm/), execute the tool in command line:

```sh
./twse-captcha-solver xxx.png
```

## Screenshot

![Screenshot](https://github.com/coldnew/twse-captcha-solver/raw/master/screenshot.png)

## License

Copyright © 2017 Yen-Chin, Lee <<coldnew.tw@gmail.com>>

Distributed under the [MIT License](http://opensource.org/licenses/MIT).