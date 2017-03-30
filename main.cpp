//
// Copyright (C) 2017  Yen-Chin, Lee

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/photo.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <regex>

void showManyImages(char *title, cv::Mat img1, cv::Mat img2, cv::Mat img3, cv::Mat img4)
{
    cv::Mat window;
    cv::hconcat(img1, img2, window);
    cv::hconcat(window, img3, window);
    cv::hconcat(window, img4, window);
    cv::imshow(title, window);
}

cv::Mat clean_captcha(const char *file)
{
    // Load captcha captcha in grayscale
    cv::Mat captcha = cv::imread(file, CV_LOAD_IMAGE_GRAYSCALE);
    if (captcha.empty()) {
        std::cerr << "Error can't open image: " << file << std::endl;
        exit(-1);
    }

    // Convert the captcha to black and white.
    cv::Mat captcha_bw;
    cv::threshold(captcha, captcha_bw, 128, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    // Erode the image to remove dot noise and that wierd line. I use a 3x3
    // rectengal as the kernal.
    cv::Mat captcha_erode;
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::erode(captcha_bw, captcha_erode, element);

    // Some cosmetic
    cv::Mat captcha_denoise;
    cv::fastNlMeansDenoising(captcha_erode, captcha_denoise, 50);

    // display every step result
    showManyImages("captcha", captcha, captcha_bw, captcha_erode, captcha_denoise);

    return captcha_denoise;
}

std::string image_to_string(cv::Mat img)
{
    tesseract::TessBaseAPI tess;
    tess.Init(NULL, "eng", tesseract::OEM_DEFAULT);
    tess.SetImage((uchar*) img.data, img.cols, img.rows, 1, img.cols);

    // return match characters
    std::string s = tess.GetUTF8Text();
    std::smatch sm;
    std::regex regx("[0-9A-Z]+");
    std::regex_search(s, sm, regx);
    return sm.str();
}

void help(char *argv[])
{
    std::cout << "Usage:" << std::endl
              << "  " << argv[0] << " <captcha image> " << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        help(argv);
        return 0;
    }

    cv::Mat img = clean_captcha(argv[1]);
    std::cout << "Captcha: "<< image_to_string(img) << std::endl;
    // Wait for user input to stop image display
    cv::waitKey();

    return 0;
}
