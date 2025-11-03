#include "popupgenerator.h"
#include "popup.h"
#include <QRandomGenerator>
#include <QApplication>
#include <QScreen>

PopupGenerator::PopupGenerator(QObject *parent)
    : QObject(parent)
    , m_count(0)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &PopupGenerator::showPopup);

    initializeMessages();
    initializeColors();
}

void PopupGenerator::initializeMessages()
{
    m_messages = {
        " ",
        " ",
        " "
    };
}

void PopupGenerator::initializeColors()
{
    m_warmColors = {
        // 浅色系
        QColor(255, 192, 203),  // #FFC0CB 浅粉红
        QColor(255, 182, 193),  // #FFB6C1 浅珊瑚粉
        QColor(255, 228, 181),  // 复古奶油黄
        QColor(255, 218, 185),  // 复古暖杏色
        QColor(250, 235, 215),  // 复古象牙白
        QColor(244, 164, 96),   // 复古暖橘黄
        QColor(240, 128, 128),  // 复古浅珊瑚红
        QColor(238, 130, 238),  // 复古洋红紫
        QColor(230, 230, 250),  // #E6E6FA 淡紫蓝
        QColor(224, 130, 162),  // 复古柔粉
        QColor(221, 160, 221),  // 复古淡紫灰
        QColor(235, 201, 117),   // 复古鎏金色
        QColor(216, 191, 216),  // #D8BFD8 淡紫
        QColor(219, 112, 147),  // #DB7093 深粉红
        QColor(205, 133, 63),   // 复古古铜色
        QColor(205, 92, 92),    // 复古玫瑰红
        QColor(197, 120, 180),  // 复古薰衣草紫
        QColor(188, 143, 143),  // 复古棕灰色

        // 深色系
        QColor(184, 103, 89),   // 怀旧暖棕
        QColor(153, 76, 0),     // 复古焦糖棕
        QColor(148, 0, 211),    // 复古深紫晶
        QColor(139, 69, 19),    // 复古巧克力棕
        QColor(138, 43, 226),   // 复古深紫罗兰
        QColor(128, 0, 128),    // 复古深紫玫
    };
}

void PopupGenerator::startGenerating()
{
    m_timer->start(100); // 每100毫秒生成一个弹窗
}

void PopupGenerator::showPopup()
{
    if (m_count < m_maxCount) {
        // 获取随机消息和颜色
        QString message = m_messages.at(QRandomGenerator::global()->bounded(m_messages.size()));
        if(m_count == 100 ) {
            QString message = "关闭弹窗请按空格";
        }
        int colorIndex = QRandomGenerator::global()->bounded(m_warmColors.size());
        QColor bgColor = m_warmColors.at(colorIndex);

        // 创建弹窗
        Popup *popup = new Popup(message, bgColor);

        if (colorIndex >= 18 && colorIndex <= 23) {
            popup->setStyleSheet("color: #f9ae85");
        } else {
            popup->setStyleSheet("color: #5D2A0F");
        }

        // 获取屏幕尺寸 - Qt6 方式
        QScreen *primaryScreen = QApplication::primaryScreen();
        QRect screenGeometry = primaryScreen->availableGeometry();

        // 随机位置
        int x = QRandomGenerator::global()->bounded(0, screenGeometry.width());
        int y = QRandomGenerator::global()->bounded(0, screenGeometry.height());

        popup->move(x, y);

        popup->show();

        m_count++;
    } else {
        m_timer->stop();
    }
}
