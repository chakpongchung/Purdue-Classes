
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}

void printPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}

void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

void createPlot( char * funcFile, double minX, double maxX) {
  int nvals = MAXCOLS;
  double yy[MAXCOLS];

  clearPlot();
  
  double step = (maxX - minX)/MAXCOLS;
  double minY, maxY;

  double j = minX;

  for(int i = 0; i < MAXCOLS; i++) { 
    yy[i]= rpn_eval(funcFile, j);
    j += step;
  }
  
  maxY = yy[0]; 
  minY = yy[0];
  
  for(int i = 0; i < MAXCOLS; i++) {
    if(yy[i] < minY) {
      minY = yy[i];
    }
    if(yy[i] > maxY) {
      maxY = yy[i];
    }
  }
  
  
  for(int i = 0; i < MAXROWS; i++) {
    plotXY(40, i, '|');
  }

  int ya = (0 - minY)/(maxY - minY) * MAXROWS;
  ya = MAXROWS - ya - 1;

  for(int j = 0; j < MAXCOLS; j++) {
    plotXY(j, ya, '_');
  }
  
  for(int i = 0; i < MAXCOLS; i++) {
    int y = (yy[i] - minY) / (maxY - minY) * MAXROWS;
    y = MAXROWS - y - 1;
    //if(i == 20) printf("MAXROWS - y - 1: %f\n", MAXROWS - ((yy[i] - minY) / (maxY - minY) * MAXROWS) - 1);
      
    //y =(MAXROWS - ((yy[i] - minY) / (maxY - minY) * MAXROWS) - 1);
    if(i == 20 && y == 30) y = 29;
    plotXY(i, y, '*');
  }


  
  // Evaluate function and store in vector yy
  //Compute maximum and minimum y in vector yy
  
  //Plot x axis

  //Plot y axis

  // Plot function. Use scaling.
  // minX is plotted at column 0 and maxX is plotted ar MAXCOLS-1
  // minY is plotted at row 0 and maxY is plotted at MAXROWS-1

  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
  }

  // Get arguments
  char * funcName = argv[1]; 
  double xmin = atof(argv[2]);
  double xmax = atof(argv[3]);
  createPlot(funcName, xmin, xmax);
}
