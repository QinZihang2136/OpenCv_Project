#include<opencv2/opencv.hpp>
#include<opencv2/xfeatures2d.hpp>
#include<iostream>

using namespace cv;
using namespace std ;
using namespace cv::xfeatures2d;
Point point1,point2;
bool leftd = false;
bool leftu = true;
Mat roi;
Mat src,gray,dst;
Rect box;
float range[] = { 0, 256 };
const float * histRanges = range;
Mat hist;
void callback(int event, int x,int y, int flags, void* param);
int histSize;
int main(int argc, char *argv[])
{
    namedWindow("GG",WINDOW_AUTOSIZE);
    setMouseCallback("GG",callback);
    //src =imread("/home/qinzihang/OpenCV_Picture/detect/test.png");
    src =imread("/home/qinzihang/OpenCV_Picture/detect/1.png");
    GaussianBlur(src,dst,Size(5,5),11);
    threshold(dst, dst, 30, 255, CV_THRESH_BINARY);
    //cvtColor(dst,dst,COLOR_BGR2GRAY);


    imshow("GG",dst);

    waitKey(0);
//    VideoCapture cap(0);

//       while(1)
//       {
//           cap >>src;
//           imshow("GG",src);
//           waitKey(1);
//        }

}
void callback(int event, int x,int y, int flags, void* param)
{
    bool mark = false;

    if(event == CV_EVENT_LBUTTONDOWN)
    {
        cout<< "left button is down" << endl;
         point1= Point(x,y);
         cout << "point1 is " << point1;
         leftd =true;
         leftu = false;

    }

    if(event == CV_EVENT_LBUTTONUP && leftd == true)
    {
        point2 = Point(x,y);
        cout << "point2 is " << point2 << endl;
        box =Rect(point1,point2);
        leftd = false;
        leftu = true;
        mark = true;
    }
    if(mark == true)
    {
        cout << " BOX is " << box << endl;
        roi = dst(box);
        imshow("END",roi);
    }
}
