#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFileDialog>
#include <QSet>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void TreeTraversal(const QDir &dir); // Read the directory tree
    void StatisticDirectory(); // Output statistics for the selected directory
    int SubdirectoriesNumber(const QDir &dir); // Calculate the number of directories in a directory

private:
    Ui::MainWindow *ui;
    QString pathDirectory;
    QFileInfoList listFile;
    QSet<QString> extension; // Put in Set a unique of expansion
    int subdirNumber;
    /* Statistics on extensions */
    int filesNumber;
    qint64 totalFileSize;
    qint64 averageFilesSize;
    /* Total statistics */
    int filesNumberDir;
    qint64 totalFileSizeDir;
    qint64 averageFilesSizeDir;
public slots:
    void slotSelectRoot();
    void slotStatisticDir();
};

#endif // MAINWINDOW_H
