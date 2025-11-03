#ifndef POPUPGENERATOR_H
#define POPUPGENERATOR_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QColor>
#include <QString>

class PopupGenerator : public QObject
{
    Q_OBJECT

public:
    explicit PopupGenerator(QObject *parent = nullptr);
    void startGenerating();

private slots:
    void showPopup();

private:
    QTimer *m_timer;
    int m_count;
    const int m_maxCount = 100;

    // 消息列表
    QVector<QString> m_messages;

    // 颜色列表
    QVector<QColor> m_warmColors;

    void initializeMessages();
    void initializeColors();
};

#endif // POPUPGENERATOR_H
