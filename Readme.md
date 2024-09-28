# pico_lvgl_ili9341_GUI_guider_display

### 概要(Abstract):

这是一个基于**lvgl version 8.3.10**版本的pico显示屏的项目，显示屏型号为**240*320**的**TFT SPI**显示屏，驱动芯片为**ili9341**控制器。通过添加**NXP**公司的**GUI_guider**自动生成的.c文件，实现屏幕上显示**hello_world**的字样。目前仅实现了测试中的显示功能，尚且未实现输入功能。其余功能可以参考本工程进行扩展。**GUI_guider**工程界面和实物效果图如下所示：

This is a **raspberry-pi-pico(RP2040)** project based on the project named **lvgl version 8.3.10**. The project needs a TFT SPI **screen** based on the **ili9341** as the output dispaly equipment. The screen's size is **240** pixels width and **320** pixels height. By adding the files produced by the **GUI_guider** software, which is developed by the **NXP** company, the project realizes the **"hello world"** output fuction. Only display function is realized.The touch function is not realized. If you want to go further, you can simply add more function based on this project. The image of the project in the **GUI_guider** and the image of the real products are as follows:

![](./image/gui.png)

![](./image/real_product.png)

------

### 准备:

- **ili9341** **240*320 TFT SPI** 屏幕，有触摸功能和没有触摸功能都可以。
- **ubuntu** 我的版本是 **22.04.3** 我认为通过**Linux**平台均可以组建。
- **GUI-Guider version 1.8.0** 通过**NXP**公司的官网可以下载。
- **Raspberry-pi-pico** 

### paperation:

- **ili9341** **240*320 TFT SPI screen** It doesn't matter that it contains the funcion of touching.
- **ubuntu** The version I used is version **22.04.03**. I think it can be built by ant plantform of **Linux**.
- **GUI-Guider version 1.8.0** you can download it thourgh the website of **NXP**.
- **Raspberry-pi-pico** 

![](./image/screen.png)

------

### 引脚连接(pin connection):

| Pin       | SPI         |
| --------- | ----------- |
| 6         | SCK/CLK     |
| 7         | MOSI/SDI/TX |
| 4         | MISO/SDO    |
| 13        | CS          |
| 14        | RST         |
| 15        | DC          |
| VCC(3.3V) | LED         |

------

### 组建：

#### 准备组建环境(prepare the environment of building):

假定你的系统已经安装好了**pico-sdk**的编译环境，理论上如果是windows，安装好了pico-sdk的组建环境也能够组建该工程。如果尚未配置好环境，请参阅树莓派官方的**getting-started-with-pico-C++**文章进行组建，下面是基于这篇文章的组建命令:

It assumes that you have already bulit the environment of building **pico-sdk**. I think if you have successfully built it on the plantform of windows, you can also buit this project. If not build, please read the article named **getting-started-with-pico-C++** relesed by the Raspberry Pi. The shell codes to build the environment of the pico-sdk are as follows:

1. ##### 获取pico-sdk和示例 Get the SDK and examples

   ```sh
   cd ~/
   mkdir pico
   cd pico
   git clone https://github.com/raspberrypi/pico-sdk.git --branch master
   cd pico-sdk
   git submodule update --init
   cd ..
   git clone https://github.com/raspberrypi/pico-examples.git --branch master
   ```

2. ##### 安装编译交叉链 Install the Toolchain

   ```sh
   sudo apt update
   sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
   ```

3. ##### 更新SDK Updating the SDK

   ```sh
   cd pico-sdk
   git pull
   git submodule update
   ```

### 	克隆仓库(git clone):

```sh
git clone -b masterhttps://github.com/zengshuaixiong/pico_lvgl_ili9341_GUI_guider_display.git
```

或者(or):

```sh
git clone https://github.com/zengshuaixiong/pico_lvgl_ili9341_GUI_guider_display.git
```

fetch the git submodules:

```sh
cd pico_lvgl_ili9341_GUI_guider_display
git submodule init
git submodule update
```

### 	组建(building):

```sh
mkdir build
cd build
export PICO_SDK_PATH=../../pico-sdk
cmake ..
make
```

说明:pico-sdk的路径需要自己设置，上述命令建立在工程与pico-sdk在同一目录下。

Addition: The path of pico-sdk needs to be reset. If you want to use the shell code, you need to put the project's path into the direction near by the folder of pico-sdk.

------

### 最后(Conclusion):

你应该可以得到对应的.UF2文件，下载到pico里面。

Then you can get the file of UF2, download it into the pico.

------

### 特别鸣谢(Special Thanks):

特别感谢我参考的基于pico的ili9341的工程，在此基础上我成功完成了此项目。链接如下：[rprouse/ILI9341_PICO_DisplayExample：将 ILI9341 SPI TFT 显示器与 Raspberry Pi Pico 一起使用的示例代码](https://github.com/rprouse/ILI9341_PICO_DisplayExample)

Special thanks to the reference of PICO DisplayExample. I got success based on it. Here is the link:[rprouse/ILI9341_PICO_DisplayExample](https://github.com/rprouse/ILI9341_PICO_DisplayExample)