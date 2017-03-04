#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->explorer = new fileExplorer();
    this->explorer->seed();
    this->root = explorer->getRaiz();
    this->selected = this->root;

    dibujar("",-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::graphicsView()
{/*
    QGraphicsView * view = ui->display_graphicsView;

    QGraphicsScene * scene = new QGraphicsScene(view);

    view->setScene(scene);

    QGraphicsRectItem * rect = new QGraphicsRectItem(-10,-10,0,0);

    scene->addItem(rect);

    QGraphicsTextItem * text = scene->addText("hola");*/
}
void MainWindow::dibujar(QString nombre,int tipo)
{
    Lista_Apuntador * lista = selected->archivos;
    ui->ruta_lbl->setText(QString::fromStdString(selected->getRuta()+"\\"+selected->getNombre()));
    bool inicio = true;
    tipo==-1 ? inicio = false : inicio=true;
    if(inicio)
        tipo==1 ? lista->agregar(new folder(nombre.toStdString(),root->getRuta())) : lista->agregar(new archivoTexto(nombre.toStdString(),root->getRuta()));
    cout<<endl<<endl<<"Lista de archivos-----------"<<endl;
    for (int x = 0; x<lista->getTamano(); x++)
    {
        archivo * temp = lista->obtener(x);
        cout<<temp->getTipo()<<"--"<<temp->getNombre()<<endl;
        if(temp->getTipo()=="Folder")
        {
            dibujar(selected,nombre,1,x,(x/8));
        }
        else
            dibujar(selected,nombre,0,x,(x/8));
    }
}

void MainWindow::dibujar(folder * subRaiz,QString nombre,int tipo,int xPos, int yPos)
{
    int xSize = 70;
    int ySize = 70;
    int xPosIni = 190 + (xPos*xSize);
    int yPosIni = 80 + (yPos*ySize);

    QPixmap pixmapFolder("C:\\Users\\renan\\Desktop\\FileSystemVisual\\FileSystem\\Resources\\Folder.png");
    QPixmap pixmapArchivo("C:\\Users\\renan\\Desktop\\FileSystemVisual\\FileSystem\\Resources\\File.png");

    QPushButton * boton = new QPushButton(this);
    boton->setGeometry(QRect(QPoint(xPosIni,yPosIni),QSize(xSize,ySize)));
    QIcon botonIcon((tipo==0 ? pixmapArchivo : pixmapFolder));
    boton->setIcon(botonIcon);
    boton->setIconSize(QSize(xSize-5,ySize-5));
    boton->show();

}

void MainWindow::on_actionNuevo_Archivo_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Nuevo Archivo"),tr("Nombre del archivo"), QLineEdit::Normal,"", &ok);
    if (ok && !text.isEmpty())
        dibujar(text,0);
}

void MainWindow::on_actionNuevo_Folder_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Nuevo Folder"),tr("Nombre del folder"), QLineEdit::Normal,"", &ok);
    if (ok && !text.isEmpty())
        dibujar(text,1);
}

void MainWindow::on_actionCopiar_triggered()
{

}

void MainWindow::on_actionPegar_triggered()
{

}

void MainWindow::on_actionSalir_triggered()
{
    QCoreApplication::quit();
}
