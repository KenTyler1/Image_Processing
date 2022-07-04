#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btn_chonanh_clicked();

    void on_btn_chinhsang_clicked();

    void on_btn_ambanxam_clicked();

    void on_btn_ambanmau_clicked();

    void on_btn_phannguong_clicked();

    void on_btn_cangtochucdo_clicked();

    void on_btn_cangtochucdoanhmau_clicked();

    void on_btn_vetochucdoxam_clicked();

    void on_btn_tochucdoanhmau_clicked();

    void on_btn_biendoituyentinh_clicked();

    void on_btn_canbangtochucdo_clicked();

//    QImage image;
    void vetochucdo(QImage &image);
    int random(int n);
    QImage taonois(QImage &image,float tile);
    QImage taonoismau(QImage &image,float tile);

    void on_btn_loctrungbinh_clicked();

    void on_btn_loctrungvi_clicked();

    void on_btn_themnhieu_clicked();

    void on_btn_themnhieuanhmau_clicked();

    void on_btn_gradient_clicked();

    void on_btn_gradientmau_clicked();

    void on_btn_robert_clicked();

    void on_btn_sobel_clicked();

    void on_btn_prewitt_clicked();

    void on_btn_laplace_clicked();

    void on_btn_gausslaplace_clicked();

    void on_btn_tuantu_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
