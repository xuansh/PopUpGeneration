#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include "popupgenerator.h"
#include <QIcon>

class SpaceKeyHandler : public QObject
{
    Q_OBJECT

public:
    SpaceKeyHandler(PopupGenerator* generator, QObject* parent = nullptr)
        : QObject(parent), m_generator(generator) {}

protected:
    bool eventFilter(QObject* obj, QEvent* event) override
    {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Space) {
                qDebug() << "空格键按下，正在关闭程序...";
                QApplication::closeAllWindows();
                QApplication::quit();
                return true;
            }
        }
        return false;
    }

private:
    PopupGenerator* m_generator;
};

int main(int argc, char* argv[])
{
    QString applicationDirPath = QCoreApplication::applicationDirPath();
    QString iconDirPath = applicationDirPath + "/logo.ico";
    QApplication app(argc, argv);

    PopupGenerator generator;
    SpaceKeyHandler handler(&generator);

    // 安装全局事件过滤器
    app.installEventFilter(&handler);
    app.setWindowIcon(QIcon(":/logo.ico"));
    qDebug() << "iconDirPath" << iconDirPath;

    generator.startGenerating();

    qDebug() << "💕 表白程序已启动！ 💕";
    qDebug() << "按空格键可以关闭所有弹窗并退出程序";

    return app.exec();
}

#include "main.moc"
