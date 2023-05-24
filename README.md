## Progress Log

### Task 0 | Initial test (without any modifications)

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/7c3bb79d-7c1f-4bd6-b53a-a41e2903e862)<br>
$+3, -13$

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/bda44abc-f10e-4be9-8fb8-7d8c9fa77b0f)

Running the `tryit.py` generated 5 files 
4 identical(`dog_no_red.jpg, dog_saturated.jpg, doglight_fixed.jpg, overflow.jpg`) and `graybar.jpg`

![doglight_fixed](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/be1e98b1-20dd-4596-a37f-1cd0b3767bff)

<hr>

### Task 1 | `get_pixel` and `set_pixel` | No-red test

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/3aac6f6e-96cd-4e38-b2ed-15a3745ed54b)<br>
$+5, -11$

Regenerating the files

(No Red channel)<br>
![dog_no_red](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/c29705d3-076d-4fa1-9fb1-82ccd9b2ed91)

(No Green Channel)<br>
![dog_no_red](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/902aeb83-b114-47fe-8138-8dcd87384cd8)

(Also implemented the `clamp` padding strategy, but couldn't test it out, yet)
<hr>

### Task 2 | Copying Image

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/1bea72a4-4948-41f1-8d5a-f1ee56ebc030)<br>
$+8, -8$

<hr>

### Task 3 | RGB to Grayscale

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/76ad228a-7a4e-42b7-bb3b-e32e681663f4)<br>
$+10, -6$

Color bar $\to$ Gray bar

![colorbar](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/dd5f5d04-835e-4025-ad74-2f6089df0eb2)
![graybar](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/4923f847-6aaa-4c9a-bc41-74078132319c)

<hr>

### Task 4 | Shifting

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/0dbf3c01-f708-4b6e-a4ba-27886c334db5)<br>
$+12, -4$

dog_saturated (HSV left)

![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/1b0edab0-0c05-4e9e-beda-03ea390647ba)

doglight_fixed (Clamping left)

![doglight_fixed](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/72f3e9f4-da17-4e01-b361-6ca052a538ed)

overflow (done)

![overflow](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/2e2e860e-e57f-4c5f-ad5e-6913b38bc721)

<hr>

### Task 5 | Clamping

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/457c7b32-722f-4217-85b2-199755d52e11)<br>
$+12, -4$

doglight_fixed (now)

![doglight_fixed](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/806a0b00-92fe-4eaa-a851-53e0ea01e897)

<hr>

### Task 6 | RGB to HSV

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/e196a110-5c1b-4f7a-b1d0-4ec51af28cbd)<br>
$+14, -2$

(Also partially fixed the `get_pixel` errors caused due to incorrect clamp padding code)

new `dog_saturated.jpg`<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/fd4bd0fc-2027-427f-8a7a-9702d7366c3a)

<hr>

### Task 7 | HSV to RGB

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/0a9b4bfc-c266-4aa3-b17a-eef9ff0cb121)<br>
$+14, -2$

converted image<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/92b00648-d69f-4a3a-bf30-e922a9dc7d5c)

second try<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/1af0b14c-e961-42b2-8f0b-4036984248d7)

third try(much better)<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/40a6c499-0731-451c-9604-7af23517214b)

try 4<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/6c0bfb94-6e47-4e02-8020-d7907cacf328)

<hr>

### Task 8 | Scaling a channel

Added the following lines in respective files

`void scale_image(image im, int c, float v);` in `image.h`
```C
void scale_image(image im, int c, float v)
{
    for (int i = 0; i < im.w * im.h; i++)
    {
        im.data[i + im.w * im.h * c] *= v; // Multiplying since we are scaling
    }
}
```
(in `process_image.c`)

```Py
scale_image = lib.scale_image
scale_image.argtypes = [IMAGE, c_int, c_float]
```
(in `uwimg.py`)

final image<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/246f9fd2-1b9f-4793-a90e-c9659106f14c)

<hr>

### Task 5.1 Clamping
(update)

fixed Clamping code completely
![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/234cdbb0-a8a0-490b-b8d6-805cbcdc4a18)
$+15, -1$

<hr>

### Task 6.1 RGB to HSV

(Update)
Ours is very close to the one obtained by matlab<br>
![dog_hsv_ml](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/47d8b08a-91b1-4874-855a-d6447c872975)

<hr>

### Task 7.1 HSV to RGB

(Update)
Fixed code (usiing the algorithm described in [Smith, A. R. “Color Gamut Transform Pairs”. SIGGRAPH 78 Conference Proceedings. 1978, pp. 12–19](/color78.pdf)

![image](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/6f1d53cd-ffcc-468d-8408-de14aed0aee8)<br>
$+16, 0$ Yay!

Final Try!<br>
![dog_saturated](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/cb5de956-5838-487e-9562-505ed6d77f48)

<hr>

### Task 9 | RGB to XYZ to LUV to (HCL?) to LUV to XYZ to RGB

Sources:<br>
1. https://www.cs.rit.edu/~ncs/color/t_convert.html
2. https://en.wikipedia.org/wiki/CIELUV#Cylindrical_representation_(CIELCh)

<hr>

### Update

(updated the header files)
(also added outputs of RGB -> XYZ -> LUV -> XYZ -> RGB conversions)
(HCL, gamma skipped)

|  RGB2XYZ  | XYZ2LUV  | LUV2XYZ  |   XYZ2RGB  |
| ---       |   ---    | ---      | ---        |
|![rgb2xyz](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/4fc17ce2-469b-4aeb-b828-1dfd135f7b60) |  ![xyz2luv](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/de32e167-ca0a-4a29-82c8-6a0e74f36f06)|  ![luv2xyz](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/2596aa7e-2bcb-4ede-ac9b-b2c03aac260c)|  ![xyz2rgb](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/e472f4ba-4605-4511-8d84-d1b7af688064)|
  
And our scaled dog too!<br>
![dog_scaled](https://github.com/cv-in-c/homework-1--play-with-pixels-and-colours-npxx/assets/96121824/6582109d-c6ca-47a6-90df-948856073b44)
