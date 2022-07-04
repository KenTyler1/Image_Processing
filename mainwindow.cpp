#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QPixmap"
#include "QLabel"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_chonanh_clicked()
{
    QString fname = QFileDialog::getOpenFileName();
    if(fname.isEmpty())
        return;
    ui->In_text->setText(fname);

    QPixmap pimax(fname);
//    QLabel *label = new QLabel();
//    label->setPixmap(pimax);
//    label->setWindowTitle(QFileInfo(fname).fileName());
//    label->show();
}

void MainWindow::on_btn_chinhsang_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int c = ui->In_dosang->text().toInt();
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray,gray,gray);
            image_in.setPixel(i,j,color_in);
            int out = gray + c;
            if(out>255)
                out = 255;
            else if(out<0)
                out = 0;
            QRgb color_out = qRgb(out,out,out);
            image_out.setPixel(i,j,color_out);
        }
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

void MainWindow::on_btn_ambanxam_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);

    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray,gray,gray);
            image_in.setPixel(i,j,color_in);
            int out = 255 - 1 - gray;
            QRgb color_out = qRgb(out,out,out);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

void MainWindow::on_btn_ambanmau_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);

    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QColor color = image_in.pixel(i,j);
            int ambanr = 255 - color.red();
            int ambang = 255 - color.green();
            int ambanb = 255 - color.blue();
            image_out.setPixel(i,j,qRgb(ambanr,ambang,ambanb));
        }
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

void MainWindow::on_btn_phannguong_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int c = ui->In_pn->text().toInt();

    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb color = image_in.pixel(i,j);
            int gray = qGray(color);
            if(gray>c)
              gray = 255;
            else
              gray = 0;
            QRgb color_out = qRgb(gray,gray,gray);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

}

void MainWindow::on_btn_cangtochucdo_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int c = ui->In_cangtochucdo->text().toFloat();
    for(int i = 0;i<image_in.width();i++){
        for(int j = 0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            image_in.setPixel(i,j,qRgb(gray,gray,gray));
            int color_out = gray*c;
            if(color_out>255)
                color_out=255;
            else if(color_out<0)
                color_out=0;
            image_out.setPixel(i,j,qRgb(color_out,color_out,color_out));
        }
    }

    //save ảnh
    QString selectedF;
    QString filename = QFileDialog::getSaveFileName(this,"Save image",QDir::currentPath(),
                                                    "BMP(*.bmp);;PNG(*.png);;JPEG(*.jpg);;All files(*.*)",
                                                    &selectedF);
    if(selectedF == "BMP(*.bmp)")
        image_out.save(filename,"BMP");
    else if(selectedF == "PNG(*.png)")
        image_out.save(filename,"PNG");
    else if(selectedF == "JPEG(*.jpg)")
        image_out.save(filename,"JPEG");
    else
        image_out.save(filename);


    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();


}

void MainWindow::on_btn_cangtochucdoanhmau_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int c = ui->In_cangtochucdo->text().toFloat();
    for(int i = 0;i<image_in.width();i++){
        for(int j = 0;j<image_in.height();j++){
            QColor color_in = image_in.pixel(i,j);
            int h,s,v;
            color_in.getHsv(&h,&s,&v);
            int v_out = v*c;
            if(v_out>255)
                v_out = 255;
            else if(v_out<0)
                v_out=0;
            QColor color_out = QColor::fromHsv(h,s,v_out);
            image_out.setPixel(i,j,color_out.rgb());
        }
    }
    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

void MainWindow::on_btn_vetochucdoxam_clicked()
{
    QImage image_in(ui->In_text->text());
    const int h = 128; //chiều cao tổ chức đồ
    QImage histogram(256,h,QImage::Format_RGB32);
    histogram.fill(Qt::white); //khởi tạo tổ chức đồ trắng
    int he[256];
    for(int i=0;i<256;i++){
        he[i]=0;
    }
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            he[gray]++;
        }
    }

    int max=0;
    for(int i = 0;i<256;i++){
        if(he[i]>max)
            max=he[i];
    }

    int line=0;
    for(int i=0;i<256;i++){
        line = h*he[i]/max;
        for(int j=h-1 ;j>h-1-line;j--){
            histogram.setPixel(i,j,qRgb(0,0,255));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(histogram));
    label_out->show();
}

void MainWindow::vetochucdo(QImage &image){
    QImage image_in = image;
    const int h = 128; //chiều cao tổ chức đồ
    QImage histogram(256,h,QImage::Format_RGB32);
    histogram.fill(Qt::white); //khởi tạo tổ chức đồ trắng
    int he[256];
    for(int i=0;i<256;i++){
        he[i]=0;
    }
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            he[gray]++;
        }
    }

    int max=0;
    for(int i = 0;i<256;i++){
        if(he[i]>max)
            max=he[i];
    }

    int line=0;
    for(int i=0;i<256;i++){
        line = h*he[i]/max;
        for(int j=h-1 ;j>h-1-line;j--){
            histogram.setPixel(i,j,qRgb(0,0,255));
        }
    }
    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(histogram));
    label_out->show();
}

void MainWindow::on_btn_tochucdoanhmau_clicked()
{
    QImage image_in(ui->In_text->text());
    const int h = 128; //chiều cao tổ chức đồ
    QImage histogram(256,h*3,QImage::Format_RGB32);
    histogram.fill(Qt::white); //khởi tạo tổ chức đồ trắng
    int hr[256],hg[256],hb[256];
    for(int i=0;i<256;i++){
        hr[i]=0;
        hg[i]=0;
        hb[i]=0;
    }
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QColor color = image_in.pixel(i,j);
            int red = color.red();
            int green = color.green();
            int blue = color.blue();
            hr[red]++;
            hg[green]++;
            hb[blue]++;
        }
    }

    int max=0;
    for(int i = 0;i<256;i++){
        if(hr[i]>max)
            max=hr[i];
        if(hg[i]>max)
            max=hg[i];
        if(hb[i]>max)
            max=hb[i];
    }

    int line=0;
    for(int i=0;i<256;i++){
        line = h*hr[i]/max;
        for(int j=h-1 ;j>h-line;j--){
            histogram.setPixel(i,j,qRgb(255,0,0));
        }

        line = h*hg[i]/max;
        for(int j=2*h-1 ;j>2*h-line;j--){
            histogram.setPixel(i,j,qRgb(0,255,0));
        }

        line = h*hb[i]/max;
        for(int j=3*h-1 ;j>3*h-line;j--){
            histogram.setPixel(i,j,qRgb(0,0,255));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(histogram));
    label_out->show();
}

void MainWindow::on_btn_biendoituyentinh_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int min = 255, max=0;
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            if(gray>=max)
                max=gray;
            if(gray<min)
                min=gray;
        }
    }
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            int color_out = ((gray-min)*255)/(max-min);
            image_in.setPixel(i,j,qRgb(gray,gray,gray));
            image_out.setPixel(i,j,qRgb(color_out,color_out,color_out));
        }
    }
    QLabel *lable_in = new QLabel();
    lable_in->setPixmap(QPixmap::fromImage(image_in));
    lable_in->show();
    vetochucdo(image_in);

    QLabel *lable = new QLabel();
    lable->setPixmap(QPixmap::fromImage(image_out));
    lable->show();
    vetochucdo(image_out);

}

void MainWindow::on_btn_canbangtochucdo_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);

    float hn[255],c[255],h[255],tong=0,chia=0;

    for(int i=0;i<=255;i++){
        h[i]=0;
        hn[i]=0;
        c[i]=0;
    }
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            h[gray]++;
        }
    }

    for(int i=0;i<=255;i++){
        tong = tong + h[i];
    }

    for(int i=0;i<=255;i++){
        hn[i]=h[i]/tong;
    }

    for(int i=0;i<=255;i++){
        for(int j=0;j<=i;j++){
            c[i]=c[i]+hn[j];
        }
    }

    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            int color_out = c[gray]*255;
            image_in.setPixel(i,j,qRgb(gray,gray,gray));
            image_out.setPixel(i,j,qRgb(color_out,color_out,color_out));
        }
    }
   QLabel *lablein = new QLabel();
   lablein->setPixmap(QPixmap::fromImage(image_in));
   lablein->show();
   vetochucdo(image_in);
   QLabel *lable = new QLabel();
   lable->setPixmap(QPixmap::fromImage(image_out));
   lable->show();
   vetochucdo(image_out);
}

void MainWindow::on_btn_loctrungbinh_clicked()
{
    QImage image_in(ui->In_text->text());
    int size = ui->In_kichthuoc->text().toInt();
    int margin = (size-1)/2;
    QImage image_out(image_in.width()-margin,image_in.height()-margin,QImage::Format_RGB32);
    int sumR,sumG,sumB;
    int cells = size*size;

    for(int x=margin;x<image_in.width()-margin;x++){
        for(int y=margin;y<image_in.height()-margin;y++){
            sumR=sumG=sumB=0;
            for(int i=-margin;i<=margin;i++){
                for(int j=-margin;j<=margin;j++){
                    QColor color = image_in.pixel(x+i,y+j);
                    sumR += color.red();
                    sumG += color.green();
                    sumB += color.blue();
                }
            }
            image_out.setPixel(x,y,qRgb(sumR/cells,sumG/cells,sumB/cells));
        }
    }
    QLabel *lable_in = new QLabel();
    lable_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    lable_in->show();

    QLabel *lable = new QLabel();
    lable->setPixmap(QPixmap::fromImage(image_out.scaled(1024,768)));
    lable->show();
}

void MainWindow::on_btn_loctrungvi_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int size = ui->In_kichthuoc->text().toInt();
    int cells = size*size;
    int tam = (size-1)/2;

    for(int x=tam;x<=image_in.width()-tam;x++){
        for(int y=tam;y<=image_in.height()-tam;y++){
            int h[cells];
            int k=0;
            for(int i=-tam;i<=tam;i++){
                for(int j=-tam;j<=tam;j++){
                    QRgb rgb = image_in.pixel(x+i,y+j);
                    int gray = qGray(rgb);
                    h[k]=gray;
                    k++;
                }
            }
            qSort(h,h+cells);
            int color_out = h[(cells-1)/2];
            image_out.setPixel(x,y,qRgb(color_out,color_out,color_out));
        }
    }
    QLabel *lable_in = new QLabel();
    lable_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    lable_in->show();

    QLabel *lable = new QLabel();
    lable->setPixmap(QPixmap::fromImage(image_out.scaled(1024,768)));
    lable->show();
}
//Thêm nhiễu ảnh xám
int MainWindow::random(int n){
    return rand()%n;
}

QImage MainWindow::taonois(QImage &image,float tile){
    QImage image_out=image;
    int sodiemanhNois = image.width()*image.height()*tile;

    for(int i=0;i<=sodiemanhNois;i++){
        int x = random(image.width());
        int y = random(image.height());
        int a = random(2);
        if(a==0)
            image_out.setPixel(x,y,qRgb(0,0,0));
        else
            image_out.setPixel(x,y,qRgb(255,255,255));
    }
    return image_out;
}

void MainWindow::on_btn_themnhieu_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_gray(image_in.width(),image_in.height(),QImage::Format_RGB32);
    float level = ui->In_tile->text().toInt();
    float tile = level/100;

    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            image_gray.setPixel(i,j,qRgb(gray,gray,gray));
        }
    }
    QImage image_out = taonois(image_gray,tile);

    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image_gray));
    label->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();

}
//Thêm nhiễu ảnh màu
QImage MainWindow::taonoismau(QImage &image,float tile){
    QImage image_out = image;
    int soluongnois = image.width()*image.height()*tile;
    for(int i=0;i<=soluongnois;i++){
        int x = random(image.width());
        int y = random(image.height());
        int a = random(3);
        if(a==0)
            image_out.setPixel(x,y,qRgb(255,0,0));
        else if(a==1)
            image_out.setPixel(x,y,qRgb(0,255,0));
        else
            image_out.setPixel(x,y,qRgb(0,0,255));
    }
    return image_out;
}


void MainWindow::on_btn_themnhieuanhmau_clicked()
{
    QImage image_in(ui->In_text->text());
//    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
//    float tile = (ui->In_tile->text().toInt())/100;
    float level = ui->In_tile->text().toInt();
    float tile = level/100;
    QImage image_out = taonoismau(image_in,tile);

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image_out));
    label->show();

}
//Gradient xám
void MainWindow::on_btn_gradient_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_gx(image_in.width(),image_in.height(),QImage::Format_RGB32);
    QImage image_gy(image_in.width(),image_in.height(),QImage::Format_RGB32);

    for (int i=0;i<=image_in.width()-1;i++){
        for(int j=0;j<=image_in.height()-1;j++){
            QRgb color = image_in.pixel(i,j);
            int gray = qGray(color);

            QRgb color_in = qRgb(gray,gray,gray);
            image_in.setPixel(i,j,color_in);

            QRgb color2 = image_in.pixel(i+1,j);
            int gray2 = qGray(color2);
            int newcolor = abs(gray-gray2);
            image_gx.setPixel(i,j,qRgb(newcolor,newcolor,newcolor));
        }
    }
    for (int i=0;i<=image_in.width()-1;i++){
        for(int j=0;j<=image_in.height()-1;j++){
            QRgb color = image_in.pixel(i,j);
            int gray = qGray(color);

            QRgb color_in = qRgb(gray,gray,gray);
            image_in.setPixel(i,j,color_in);

            QRgb color2 = image_in.pixel(i,j+1);
            int gray2 = qGray(color2);
            int newcolor = abs(gray-gray2);
            image_gy.setPixel(i,j,qRgb(newcolor,newcolor,newcolor));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->show();

    QLabel *label_gx = new QLabel();
    label_gx->setPixmap(QPixmap::fromImage(image_gx.scaled(1024,768)));
    label_gx->show();

    QLabel *label_gy = new QLabel();
    label_gy->setPixmap(QPixmap::fromImage(image_gy.scaled(1024,768)));
    label_gy->show();
}
//Gradient màu:
void MainWindow::on_btn_gradientmau_clicked()
{




}
//Robert
void MainWindow::on_btn_robert_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_gx(image_in.width(),image_in.height(),QImage::Format_RGB32);
    QImage image_gy(image_in.width(),image_in.height(),QImage::Format_RGB32);
    for(int i=0;i<image_in.width();i++){
        for(int j=0;j<image_in.height();j++){
            QRgb color1 = image_in.pixel(i,j);
            int gray1 = qGray(color1);

            QRgb color2 = image_in.pixel(i+1,j);
            int gray2 = qGray(color2);

            QRgb color3 = image_in.pixel(i,j+1);
            int gray3 = qGray(color3);

            QRgb color4 = image_in.pixel(i+1,j+1);
            int gray4 = qGray(color4);

            int colorgx = abs(gray1-gray4);
            int colorgy = abs(gray2-gray3);

            image_gx.setPixel(i,j,qRgb(colorgx,colorgx,colorgx));
            image_gy.setPixel(i,j,qRgb(colorgy,colorgy,colorgy));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->show();

    QLabel *label_gx = new QLabel();
    label_gx->setPixmap(QPixmap::fromImage(image_gx.scaled(1024,768)));
    label_gx->show();

    QLabel *label_gy = new QLabel();
    label_gy->setPixmap(QPixmap::fromImage(image_gy.scaled(1024,768)));
    label_gy->show();
}
//Sobel
void MainWindow::on_btn_sobel_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out1(image_in.width(),image_in.height(),QImage::Format_RGB32);
    QImage image_out2(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int size = 3;
    int margin = size/2;

    int mask[size][size];
    mask[0][0]=-1; mask[0][1]=0; mask[0][2]=1;
    mask[1][0]=-2; mask[1][1]=0; mask[1][2]=2;
    mask[2][0]=-1; mask[2][1]=0; mask[2][2]=1;

    int mask2[size][size];
    mask2[0][0]=-1; mask2[0][1]=-2; mask2[0][2]=-1;
    mask2[1][0]=0; mask2[1][1]=0; mask2[1][2]=0;
    mask2[2][0]=1; mask2[2][1]=2; mask2[2][2]=1;
    int sum1,sum2;


    for(int x=margin;x<image_in.width()-margin;x++){
        for(int y=margin;y<image_in.height()-margin;y++){
            sum1=sum2=0;
            for(int i=-margin;i<=margin;i++){
                for(int j=-margin;j<=margin;j++){
                    QRgb color = image_in.pixel(x+i,y+j);
                    int gray = qGray(color);
                    sum1 += gray*mask[i+margin][j+margin];
                    sum2 += gray*mask2[i+margin][j+margin];
                }
            }
            image_out1.setPixel(x,y,qRgb(abs(sum1),abs(sum1),abs(sum1)));
            image_out2.setPixel(x,y,qRgb(abs(sum2),abs(sum2),abs(sum2)));
        }
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->show();

    QLabel *label_out1 = new QLabel();
    label_out1->setPixmap(QPixmap::fromImage(image_out1.scaled(1024,768)));
    label_out1->show();

    QLabel *label_out2 = new QLabel();
    label_out2->setPixmap(QPixmap::fromImage(image_out2.scaled(1024,768)));
    label_out2->show();
}
//Prewitt
void MainWindow::on_btn_prewitt_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out1(image_in.width(),image_in.height(),QImage::Format_RGB32);
    QImage image_out2(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int size = 3;
    int margin = size/2;

    int mask[size][size];
    mask[0][0]=-1; mask[0][1]=0; mask[0][2]=1;
    mask[1][0]=-1; mask[1][1]=0; mask[1][2]=1;
    mask[2][0]=-1; mask[2][1]=0; mask[2][2]=1;

    int mask2[size][size];
    mask2[0][0]=-1; mask2[0][1]=-1; mask2[0][2]=-1;
    mask2[1][0]=0; mask2[1][1]=0; mask2[1][2]=0;
    mask2[2][0]=1; mask2[2][1]=1; mask2[2][2]=1;
    int sum1,sum2;


    for(int x=margin;x<image_in.width()-margin;x++){
        for(int y=margin;y<image_in.height()-margin;y++){
            sum1=sum2=0;
            for(int i=-margin;i<=margin;i++){
                for(int j=-margin;j<=margin;j++){
                    QRgb color = image_in.pixel(x+i,y+j);
                    int gray = qGray(color);
                    sum1 += gray*mask[i+margin][j+margin];
                    sum2 += gray*mask2[i+margin][j+margin];
                }
            }
            image_out1.setPixel(x,y,qRgb(abs(sum1),abs(sum1),abs(sum1)));
            image_out2.setPixel(x,y,qRgb(abs(sum2),abs(sum2),abs(sum2)));
        }
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->show();

    QLabel *label_out1 = new QLabel();
    label_out1->setPixmap(QPixmap::fromImage(image_out1.scaled(1024,768)));
    label_out1->show();

    QLabel *label_out2 = new QLabel();
    label_out2->setPixmap(QPixmap::fromImage(image_out2.scaled(1024,768)));
    label_out2->show();
}
//Laplace
void MainWindow::on_btn_laplace_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out1(image_in.width(),image_in.height(),QImage::Format_RGB32);
    QImage image_out2(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int size = 3;
    int margin = size/2;

    int mask[size][size];
    mask[0][0]=0; mask[0][1]=1; mask[0][2]=0;
    mask[1][0]=1; mask[1][1]=-4; mask[1][2]=1;
    mask[2][0]=0; mask[2][1]=1; mask[2][2]=0;

    int mask2[size][size];
    mask2[0][0]=1; mask2[0][1]=1; mask2[0][2]=1;
    mask2[1][0]=1; mask2[1][1]=-8; mask2[1][2]=1;
    mask2[2][0]=1; mask2[2][1]=1; mask2[2][2]=1;
    int sum1,sum2;


    for(int x=margin;x<image_in.width()-margin;x++){
        for(int y=margin;y<image_in.height()-margin;y++){
            sum1=sum2=0;
            for(int i=-margin;i<=margin;i++){
                for(int j=-margin;j<=margin;j++){
                    QRgb color = image_in.pixel(x+i,y+j);
                    int gray = qGray(color);
                    sum1 += gray*mask[i+margin][j+margin];
                    sum2 += gray*mask2[i+margin][j+margin];
                }
            }
            image_out1.setPixel(x,y,qRgb(abs(sum1),abs(sum1),abs(sum1)));
            image_out2.setPixel(x,y,qRgb(abs(sum2),abs(sum2),abs(sum2)));
        }
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->show();

    QLabel *label_out1 = new QLabel();
    label_out1->setPixmap(QPixmap::fromImage(image_out1.scaled(1024,768)));
    label_out1->show();

    QLabel *label_out2 = new QLabel();
    label_out2->setPixmap(QPixmap::fromImage(image_out2.scaled(1024,768)));
    label_out2->show();
}
//Gauss + Laplace
void MainWindow::on_btn_gausslaplace_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out1(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int size = 5;
    int margin = size/2;

    int mask[size][size];
    mask[0][0]=0; mask[0][1]=0; mask[0][2]=-1; mask[0][3]=0; mask[0][4]=0;
    mask[1][0]=0; mask[1][1]=-1; mask[1][2]=-2; mask[1][3]=-1; mask[1][4]=0;
    mask[2][0]=-1; mask[2][1]=-2; mask[2][2]=16; mask[2][3]=-2; mask[2][4]=-1;
    mask[3][0]=0; mask[3][1]=-1; mask[3][2]=-2; mask[3][3]=-1; mask[3][4]=0;
    mask[4][0]=0; mask[4][1]=0; mask[4][2]=-1; mask[4][3]=0; mask[4][4]=0;
    int sum1;


    for(int x=margin;x<image_in.width()-margin;x++){
        for(int y=margin;y<image_in.height()-margin;y++){
            sum1=0;
            for(int i=-margin;i<=margin;i++){
                for(int j=-margin;j<=margin;j++){
                    QRgb color = image_in.pixel(x+i,y+j);
                    int gray = qGray(color);
                    sum1 += gray*mask[i+margin][j+margin];
                }
            }
            image_out1.setPixel(x,y,qRgb(abs(sum1),abs(sum1),abs(sum1)));
        }
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->show();

    QLabel *label_out1 = new QLabel();
    label_out1->setPixmap(QPixmap::fromImage(image_out1.scaled(1024,768)));
    label_out1->show();
}

void MainWindow::on_btn_tuantu_clicked()
{
    QImage image_in(ui->In_text->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_RGB32);
    int c = 127;
    int newc = c;
    do{
        int G1 = 0;
        int count1 = 0;
        int G2 = 0;
        int count2 = 0;
        c = newc;
        for(int i =0 ; i <image_in.width();i++){
            for(int j = 0; j< image_in.height();j++){
                QRgb rgb = image_in.pixel(i,j);
                int gray = qGray(rgb);
                QRgb color_in = qRgb(gray,gray,gray);
                image_in.setPixel(i,j,color_in);
                if(gray<c){
                    G1 = G1 + gray;
                    count1++;
                }
                else if(gray<=c){
                    G2 = G2 + gray;
                    count2++;
                }
            }
        }
        int M1 = G1/count1;
        int M2 = G2/count2;
        newc = (M1 + M2)/2;
    }while(abs(newc - c) != 0);
}

