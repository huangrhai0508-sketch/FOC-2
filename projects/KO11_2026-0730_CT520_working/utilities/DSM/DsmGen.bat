echo off
DsmGen.exe INV_Diag_conf.XML DSMAuto
copy dsmifc.c DSMAuto/dsmifc.c
copy dsmifc.h DSMAuto/dsmifc.h
del INV_Diag_conf.xml