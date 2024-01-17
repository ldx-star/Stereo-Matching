//
// Created by liangdaxin on 23-6-19.
//
#include "SGM.h"
#include <string>

int main(){
    std::string left_img_path = "../src/img1.png";
    std::string right_img_path = "../src/img2.png";

    cv::Mat left_img = cv::imread(left_img_path,0);
    cv::Mat right_img = cv::imread(right_img_path,0);
    if(left_img.data == nullptr || right_img.data == nullptr){
        std::cout<<"图片读取错误"<<std::endl;
        return -1;
    }
    if(left_img.rows != right_img.rows || right_img.cols != left_img.cols){
        std::cout<<"图片大小不一致"<<std::endl;
        return -1;
    }

    const uint32 width = static_cast<uint32>(left_img.cols);
    const uint32 height = static_cast<uint32>(left_img.rows);

    //SGM匹配参数设计
    SGM::SGMOption option;
    option.censusSize = SGM::Census5x5;
    option.min_disparity = 0;
    option.max_disparity = 64;

    //创建SGM匹配实例
    SGM sgm;
    sgm.Initialize(width,height,option);
    cv::Mat disp_img;
    sgm.Match(left_img,right_img,disp_img);

    //显示视差图

    sgm.Show_disparity();


    return 0;
}