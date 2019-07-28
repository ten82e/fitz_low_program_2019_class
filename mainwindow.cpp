#include "mainwindow.h"
#include "ui_mainwindow.h"


std::chrono::system_clock::time_point  start,mid, end; // 型は auto で可
int lrflag=0;
int sflag=0;
char str[256];
int c=0;



/*void MainWindow::QHoverEvent(QMouseEvent *e){

    ui->ncount->setText( QString::fromLocal8Bit("0"));
}
*/

/*void MainWindow::leaveEvent(QEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // handle left mouse button here
    } else {
        // pass on other buttons to base class
        QCheckBox::mousePressEvent(event);
    }
}*/



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->carea->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // This function repeatedly call for those QObjects
    // which have installed eventFilter (Step 2)

    if (obj == ui->carea) {
        if (event->type() == QEvent::Enter)
        {
           mid = std::chrono::system_clock::now();
        // Whatever you want to do when mouse goes over targetPushButton
        }
        return true;
    }else {
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_posis_clicked()
{
    srand((unsigned int)time(NULL));
    sleep(1);
    int count=(rand()%5)*10000;
    while(count>0){
        count--;
    }
    int flag=rand()%2;
    //ui->posis->setMouseTracking(true);
    if(flag==0){
        lrflag=1;
        QPalette palette = ui->Ldisp->palette();
        palette.setColor(QPalette::Base, Qt::red);
        ui->Ldisp->setPalette(palette);
        start = std::chrono::system_clock::now();
    }
    else{
        lrflag=2;
        QPalette palette = ui->Rdisp->palette();
        palette.setColor(QPalette::Base, Qt::red);
        ui->Rdisp->setPalette(palette);
        start = std::chrono::system_clock::now();
    }
}

void MainWindow::on_RB_clicked()
{
    end = std::chrono::system_clock::now();
    if(lrflag==2){
        double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-mid).count();
        sprintf(str, "%lf",elapsed);
    }
    ui->rresult->append( QString::fromLocal8Bit(str) );
    if(lrflag==2){
        double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(mid-start).count();
        sprintf(str, "%lf",elapsed);
    }
    lrflag=0;
    ui->r2result->append( QString::fromLocal8Bit(str) );
    QPalette palette = ui->Rdisp->palette();
    palette.setColor(QPalette::Base, Qt::white);
    ui->Rdisp->setPalette(palette);
    c++;
    sprintf(str, "%d",c);
    ui->ncount->setText( QString::fromLocal8Bit(str));
    //ui->posis->setMouseTracking(false);
}


void MainWindow::on_LB_clicked()
{
    end = std::chrono::system_clock::now();
    if(lrflag==1){
        double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end-mid).count();
        sprintf(str, "%lf",elapsed);
    }
    ui->lresult->append( QString::fromLocal8Bit(str) );
    if(lrflag==1){
        double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(mid-start).count();
        sprintf(str, "%lf",elapsed);
    }
    ui->l2result->append( QString::fromLocal8Bit(str) );
    QPalette palette = ui->Ldisp->palette();
    palette.setColor(QPalette::Base, Qt::white);
    ui->Ldisp->setPalette(palette);
    lrflag=0;
    c++;
    sprintf(str, "%d",c);
    ui->ncount->setText( QString::fromLocal8Bit(str));
    //ui->posis->setMouseTracking(false);
}

void MainWindow::on_pushButton_clicked()
{
    sflag=1;
    ui->LB->resize(32,128);
    ui->RB->resize(32,128);
}

void MainWindow::on_pushButton_2_clicked()
{
    sflag=2;
    ui->LB->resize(64,128);
    ui->RB->resize(64,128);
}


void MainWindow::on_pushButton_3_clicked()
{
    sflag=3;
    ui->LB->resize(128,128);
    ui->RB->resize(128,128);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(sflag==1){
    ui->LB->move(700-128-32/2,400);
    ui->RB->move(700+128-32/2,400);
    }else if(sflag==2){
        ui->LB->move(700-128-64/2,400);
        ui->RB->move(700+128-64/2,400);
    }else if(sflag==3){
    ui->LB->move(700-128-128/2,400);
     ui->RB->move(700+128-128/2,400);
    }ui->RB->move(700+128,400);
}
void MainWindow::on_pushButton_5_clicked()
{
    if(sflag==1){
    ui->LB->move(700-256-32/2,400);
    ui->RB->move(700+256-32/2,400);
    }else if(sflag==2){
        ui->LB->move(700-256-64/2,400);
        ui->RB->move(700+256-64/2,400);
    }else if(sflag==3){
    ui->LB->move(700-256-128/2,400);
    ui->RB->move(700+256-128/2,400);
    }ui->RB->move(700+256,400);
}
void MainWindow::on_pushButton_6_clicked()
{
    if(sflag==1){
    ui->LB->move(700-512-32/2,400);
    ui->RB->move(700+512-32/2,400);
    }else if(sflag==2){
        ui->LB->move(700-512-64/2,400);
        ui->RB->move(700+512-64/2,400);
    }else if(sflag==3){
    ui->LB->move(700-512-128/2,400);
    ui->RB->move(700+512-128/2,400);
    }ui->RB->move(700+512,400);

}



void MainWindow::on_pushButton_7_clicked()
{
    c=0;
    lrflag=0;
    sflag=0;
    ui->l2result->setText(QString::fromLocal8Bit("") );
    ui->r2result->setText(QString::fromLocal8Bit("") );
    ui->lresult->setText(QString::fromLocal8Bit("") );
    ui->rresult->setText(QString::fromLocal8Bit("") );
    ui->ncount->setText( QString::fromLocal8Bit("0"));
}



