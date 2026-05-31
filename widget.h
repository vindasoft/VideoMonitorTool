#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraDevice>
#include <QMediaCaptureSession>
#include <QVideoWidget>
#include <QImageCapture>
#include <QList>
#include <QMediaRecorder>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onCameraChanged(int index);
    void onStorageModeChanged(int index);
    void onCameraResolutionChanged(int index);

private:
    void initializeCamera(int index); // 初始化相机
    void initializeRecordStorageMode(int index); // 初始化录像内容存储模式
    void removeRepeatedCameraFormats(); // 去除重复的相机格式（分辨率、帧率等）
    void setCameraResolution(const QSize &resolution); // 设置相机的分辨率
    void onStartRecord();  // 点击开始录像按钮后触发的函数
    QString generateRecordingFilePath(const QString &baseDir, const QString &mode); // 创建存放录制文件的路径

    Ui::Widget *ui;
    QCamera *camera = nullptr; // 相机
    QList<QCameraDevice> cameras; // 相机列表
    QMediaCaptureSession *captureSession = nullptr;
    QVideoWidget *viewfinder = nullptr;  // 取景器
    QImageCapture *imageCapture = nullptr; // 图像捕获
    QList<QCameraFormat> mFormats; // 初始化存储相机格式对象列表
    QList<QString> storageModes = {}; // 初始化录像内容的存储模式列表

    QMediaRecorder *mediaRecorder = nullptr; // 录像器
    QString currentRecordFilePath;   // 当前录像文件路径
};
#endif // WIDGET_H
