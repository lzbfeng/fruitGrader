@echo off  
  
wmic environment where "name='path' and username='<system>'" set VariableValue="%path%;%~dp0bin\dll"

regsvr32   Activex�ؼ�\FruitReco.ocx