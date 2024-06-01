/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/13/21
 */
// ExcelImports.cpp
//
// (C) Datasim Education BV 2005
//
// Import necessary typelib's for Excel

#ifndef ExcelImports_CPP
#define ExcelImports_CPP

#import "C:\Program Files\Microsoft Office\root\vfs\ProgramFilesCommonX86\Microsoft Shared\OFFICE16\MSO.DLL" \
rename("DocumentProperties", "DocumentPropertiesXL") rename("RGB", "RGBXL")
#import "C:\Program Files\Microsoft Office\root\vfs\ProgramFilesCommonX86\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB"
#import "C:\Program Files\Microsoft Office\root\Office16\EXCEL.EXE" no_auto_exclude\
rename("DialogBox", "DialogBoxXL") rename("RGB", "RGBXL") \
rename("DocumentProperties", "DocumentPropertiesXL") \
rename("ReplaceText", "ReplaceTextXL") \
rename("CopyFile", "CopyFileXL") no_dual_interfaces

#endif
