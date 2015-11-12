######################################################################
# Automatically generated by qmake (2.01a) mar nov 10 18:05:50 2015
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . Common Communication Exceptions GUI MathTools
INCLUDEPATH += . GUI Communication Common Exceptions MathTools
CONFIG += link_pkgconfig
PKGCONFIG += opencv eigen3

# Input
HEADERS += Common/neighbourhood.h \
           Common/neighbourhoodfactory.h \
           Communication/segmentationeventhandler.h \
           Communication/segmentationthread.h \
           Exceptions/exception.h \
           Exceptions/mathexception.h \
           Exceptions/userinputexception.h \
           GUI/displaywindow.h \
           GUI/mainwindow.h \
           MathTools/seededsegmentation.h
FORMS += GUI/mainwindow.ui
SOURCES += main.cpp \
           Common/neighbourhood.cpp \
           Common/neighbourhoodfactory.cpp \
           Communication/segmentationeventhandler.cpp \
           Communication/segmentationthread.cpp \
           Exceptions/exception.cpp \
           Exceptions/mathexception.cpp \
           Exceptions/userinputexception.cpp \
           GUI/displaywindow.cpp \
           GUI/mainwindow.cpp \
           MathTools/seededsegmentation.cpp