# PopUpGeneration
通过C++和QT实现弹窗表白
## 环境
1. QT Creator 17.0.2
2. Inno Setup Complier(用于程序打包成setup程序)

## 📝 字体版权说明

**注意**：本项目包含的字体文件仅限**个人非商业使用**。如需商用，请：
- 购买官方商业授权
- 替换为开源字体（如思源字体、得意黑等）
- 使用系统自带字体

严禁未经授权用于商业用途，违者责任自负。

***

### popup.h & popup.cpp
<b>这两个文件用于设置单个弹窗的属性</b><br><br>
popup.cpp 25行 可以设置弹窗的生命周期
```cpp
// 8秒后自动关闭
//QTimer::singleShot(8000, this, &Popup::close);
```
### popupgenerate.h & popupgenerate.cpp
通过改popgenerate.cpp文件里的提示词来修改弹窗随机出现的文案
```cpp
void PopupGenerator::initializeMessages()
{
    m_messages = {
        "",
        "",
        ""
    };
}//文案自己写哦 自己对象自己写
```

popgenerate.cpp文件里这个函数调每个弹窗生成间隔时间
```cpp
void PopupGenerator::startGenerating()
{
    m_timer->start(100); // 每100毫秒生成一个弹窗
}
```

popgenerate.h 第24行 可以修改生成弹窗总数
```cpp
const int m_maxCount = 100;
```
