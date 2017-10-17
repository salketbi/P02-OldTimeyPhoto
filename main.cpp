#include <iostream>
#include "bitmap.h"
#include <vector>
#include <string>
using namespace std;
 int main ()
  {
   vector <vector <Pixel> > bitmap;
   Bitmap orig_image;
   Pixel px;
   bool condition;
   int rows;
   int cols;
   string file_name;
   do
   {

   cout<<"Input the file name for the image : ";
   cin>> file_name;

   orig_image.open(file_name);
   bool validBmp = orig_image.isImage();

   if (!validBmp)
   {
   condition = true;
   }

   else
   {

   condition = false;
   bitmap = orig_image.toPixelMatrix();
   rows = bitmap.size();
   cols = bitmap[0].size();
   cout<<"The file " << file_name <<" has been loaded. It is "<< cols <<" pixels wide and "<<rows<<" pixels high."<<endl;

   for(int i=0;i<bitmap.size();i++)
   {
   for(int j=0;j<bitmap[i].size();j++)
   {
   int gray;
   px = bitmap[i][j];
   gray = (px.red + px.green + px.blue)/3;
   px.red = gray;
   px.green = gray;
   px.blue = gray;
   bitmap[i][j]= px;

   }
   }

   orig_image.fromPixelMatrix(bitmap);

   orig_image.save("oldtimey.bmp");

   }
   }

   while (condition);
         return 0;
          }
