#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), filesNumber(0), totalFileSize(0), averageFilesSize(0), subdirNumber(0),
    filesNumberDir(0), totalFileSizeDir(0), averageFilesSizeDir(0)
{
    ui->setupUi(this);

    pathDirectory = QDir::current().absolutePath(); // Set the path to the directory
    connect(ui->pbEnterDirectory, SIGNAL(clicked(bool)), SLOT(slotSelectRoot()));
    connect(ui->pbStatisticDirectory, SIGNAL(clicked(bool)), SLOT(slotStatisticDir()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotSelectRoot()
{
    /* Slot select the root directory */
    QString str = QFileDialog::getExistingDirectory(0, "Select the root directory", pathDirectory);
    listFile.clear();
    ui->teDirectoryListing->clear();
    ui->teCatalogStatistic->clear();
    pathDirectory = str;
    subdirNumber = SubdirectoriesNumber(QDir(str));
    TreeTraversal(QDir(str));
}

void MainWindow::slotStatisticDir()
{
    StatisticDirectory();
}

int MainWindow::SubdirectoriesNumber(const QDir &dir)
{
    /* Calculate the number of directories in a directory */
    QStringList listDir = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    return listDir.size();
}

void MainWindow::TreeTraversal(const QDir &dir)
{
    QApplication::processEvents(); // The screen does not hang
    /* Traversing directories without "." and ".." */
    QStringList listDir = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QString subDir, listDir)
    {
        ui->teDirectoryListing->append(dir.absoluteFilePath(subDir));
        TreeTraversal(QDir(dir.absoluteFilePath(subDir)));
    }
    listFile += dir.entryInfoList(QDir::Files); // Save all files (recursively)
    foreach(QFileInfo file, listFile)
    {
        if(file.suffix() == "")
        {
            extension.insert("No expansion"); // If no expansion in the file
        }
        else
        {
            extension.insert(file.suffix());
        }
    }
}

void MainWindow::StatisticDirectory()
{
    QApplication::processEvents(); // The screen does not hang
    QString str; // The auxiliary variable
    ui->teCatalogStatistic->append("Current directory - " + pathDirectory + "\n");
    /* Statistics for extensions and total statistics */
    foreach(const QString &strExtension, extension)
    {
        foreach(QFileInfo file, listFile)
        {
            if(file.suffix() == strExtension || file.suffix().isEmpty())
            {
                totalFileSize += file.size();
                ++filesNumber;
            }
        }
        totalFileSizeDir += totalFileSize;
        filesNumberDir += filesNumber;
        if(totalFileSize == 0)
        {
            averageFilesSize = 0;
        }
        else
        {
            averageFilesSize = totalFileSize / filesNumber;
        }
        ui->teCatalogStatistic->append("Number of files with extension \"" + strExtension + "\" - " +
                               str.setNum(filesNumber) + ", total size - " +
                               str.setNum(totalFileSize) + ", the average size of files - " +
                               str.setNum(averageFilesSize) + "\n");

        totalFileSize = 0;
        filesNumber = 0;
        averageFilesSize = 0;
    }
    extension.clear();

    if(totalFileSizeDir == 0)
    {
        averageFilesSizeDir = 0;
    }
    else
    {
        averageFilesSizeDir = totalFileSizeDir / filesNumberDir;
    }
    ui->teCatalogStatistic->append("\nTotal number of files - " + str.setNum(filesNumberDir) +
                           ", total size - " + str.setNum(totalFileSizeDir) +
                           ", the average size of files - " + str.setNum(averageFilesSizeDir) + "\n");
    filesNumberDir = 0;
    totalFileSizeDir = 0;
    averageFilesSizeDir = 0;

    ui->teCatalogStatistic->append("Number of subdirectories in the folder \"" + pathDirectory +
                           "\" - " + str.setNum(subdirNumber));
}
