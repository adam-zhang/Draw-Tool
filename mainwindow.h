#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class XYGraphicsView;
class XYGraphicsScene;
class XYCanvasGraphicsItem;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		MainWindow(QWidget *parent = 0);
		~MainWindow();

		public slots:
			void setShape(QAction *act);
		void openPixmap(const QString &path = QString());
		void savePixmap();
		void settingPen();
		void onNewFile();
		void onOpenFile();
		void onExitApplication();
		void onSaveFile();

	protected:
		void closeEvent(QCloseEvent *event);
		bool eventFilter(QObject *watched, QEvent *event);

	private:
		void initToolBar();
		void initializeMenu();
		void makeFileMenu();
		void makeNewFileAction(QMenu*);
		void makeOpenFileAction(QMenu*);
		void makeExitAction(QMenu*);
		void makeEditMenu();
		void makePropertyAction(QMenu*);
		void makeSaveFileAction(QMenu*);
	private:
		XYGraphicsView *view_;
		XYGraphicsScene *scene_;
		XYCanvasGraphicsItem *canvas_;
		QString lastPixmapPath_;
};

#endif // MAINWINDOW_H
