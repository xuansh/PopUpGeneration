#include "popup.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QTimer>

Popup::Popup(const QString& message, const QColor& color, QWidget *parent)
    : QWidget(parent)
{
    applicationDirPath = QCoreApplication::applicationDirPath();

    loadCustomFont();

    setupUI(message, color);

    // 添加淡入动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(800);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    // 8秒后自动关闭
    //QTimer::singleShot(8000, this, &Popup::close);
}

void Popup::setupUI(const QString& message, const QColor& color)
{
    // 设置窗口属性
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool | Qt::FramelessWindowHint);
    setFixedSize(370, 230);

    // 创建标签
    QLabel *label = new QLabel(message, this);
    label->setFont(m_customFont);
    label->setStyleSheet(""
                         "font-weight: bold; "
                         "background: transparent;"
                       //  "border: none;"              // 无边框
                         "padding: 0px;"              // 无内边距
                         "margin: 0px;"
                         "");
    label->setAlignment(Qt::AlignCenter);

    // // 创建关闭按钮
    // QPushButton *closeButton = new QPushButton("×", this);
    // closeButton->setFixedSize(30, 30);
    // closeButton->setStyleSheet("QPushButton {"
    //                            "background-color: rgba(255,255,255,0.7);"
    //                            "border-radius: 15px;"
    //                            "font-size: 16px;"
    //                            "font-weight: bold;"
    //                            "color: #ff4444;"
    //                            "}"
    //                            "QPushButton:hover {"
    //                            "background-color: rgba(255,255,255,0.9);"
    //                            "}");
    // connect(closeButton, &QPushButton::clicked, this, &Popup::close);

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 顶部布局（关闭按钮）
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addStretch();
    //topLayout->addWidget(closeButton);
    topLayout->setContentsMargins(0, 0, 5, 0);

    // 添加到主布局
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(label);
    mainLayout->setAlignment(Qt::AlignCenter);

    // 设置背景颜色和样式
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, color);
    setPalette(palette);


    // 设置圆角边框

}

void Popup::loadCustomFont()
{
    QString fontDirPath = applicationDirPath + "/fonts/XiangJiaoXingXingLingGanTi-2.ttf";
    int fontId = QFontDatabase::addApplicationFont(fontDirPath);
    if (fontId != -1) {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        if (!fontFamilies.isEmpty()) {
            m_customFont.setFamily(fontFamilies.at(0));
        }
    } else {
        // 方法2: 如果文件加载失败，使用系统字体作为备选
        m_customFont.setFamily("Microsoft YaHei");
    }

    m_customFont.setPointSize(35);
    m_customFont.setBold(true);
}
