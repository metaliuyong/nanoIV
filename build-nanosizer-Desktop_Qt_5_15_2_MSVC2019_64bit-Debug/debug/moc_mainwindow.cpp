/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nanosizer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[130];
    char stringdata0[3194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "RequestCoProtocolPause"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 29), // "Enable_AddToSweepQueue_Button"
QT_MOC_LITERAL(4, 65, 19), // "EnableNeutralButton"
QT_MOC_LITERAL(5, 85, 12), // "QPushButton*"
QT_MOC_LITERAL(6, 98, 6), // "button"
QT_MOC_LITERAL(7, 105, 20), // "DisableNeutralButton"
QT_MOC_LITERAL(8, 126, 17), // "EnableGreenButton"
QT_MOC_LITERAL(9, 144, 18), // "DisableGreenButton"
QT_MOC_LITERAL(10, 163, 18), // "EnableYellowButton"
QT_MOC_LITERAL(11, 182, 19), // "DisableYellowButton"
QT_MOC_LITERAL(12, 202, 15), // "EnableRedButton"
QT_MOC_LITERAL(13, 218, 16), // "DisableRedButton"
QT_MOC_LITERAL(14, 235, 19), // "on_IV_Start_clicked"
QT_MOC_LITERAL(15, 255, 19), // "on_IV_Pause_clicked"
QT_MOC_LITERAL(16, 275, 21), // "on_IV_Unpause_clicked"
QT_MOC_LITERAL(17, 297, 18), // "on_IV_Stop_clicked"
QT_MOC_LITERAL(18, 316, 35), // "on_IV_SweepsCount_Field_textC..."
QT_MOC_LITERAL(19, 352, 32), // "on_IV_IncreaseSweepCount_clicked"
QT_MOC_LITERAL(20, 385, 32), // "on_IV_DecreaseSweepCount_clicked"
QT_MOC_LITERAL(21, 418, 36), // "on_IV_StartVoltage_Field_text..."
QT_MOC_LITERAL(22, 455, 34), // "on_IV_EndVoltage_Field_textCh..."
QT_MOC_LITERAL(23, 490, 40), // "on_IV_VoltageIncrement_Field_..."
QT_MOC_LITERAL(24, 531, 29), // "on_IV_Pause_Field_textChanged"
QT_MOC_LITERAL(25, 561, 29), // "on_IV_AddToSweepQueue_clicked"
QT_MOC_LITERAL(26, 591, 28), // "on_IV_LoadParameters_clicked"
QT_MOC_LITERAL(27, 620, 28), // "on_IV_SaveParameters_clicked"
QT_MOC_LITERAL(28, 649, 27), // "on_IV_SaveAllSweeps_clicked"
QT_MOC_LITERAL(29, 677, 32), // "on_IV_SaveSelectedSweeps_clicked"
QT_MOC_LITERAL(30, 710, 25), // "on_IV_SetSavePath_clicked"
QT_MOC_LITERAL(31, 736, 30), // "on_CurrentSample_Start_clicked"
QT_MOC_LITERAL(32, 767, 30), // "on_CurrentSample_Pause_clicked"
QT_MOC_LITERAL(33, 798, 32), // "on_CurrentSample_Unpause_clicked"
QT_MOC_LITERAL(34, 831, 29), // "on_CurrentSample_Stop_clicked"
QT_MOC_LITERAL(35, 861, 21), // "on_OpenDevice_clicked"
QT_MOC_LITERAL(36, 883, 27), // "on_IncrementVoltage_clicked"
QT_MOC_LITERAL(37, 911, 27), // "on_DecrementVoltage_clicked"
QT_MOC_LITERAL(38, 939, 21), // "on_GetVoltage_clicked"
QT_MOC_LITERAL(39, 961, 26), // "on_GetInstrumentID_clicked"
QT_MOC_LITERAL(40, 988, 21), // "on_ZCheck_Off_clicked"
QT_MOC_LITERAL(41, 1010, 20), // "on_ZCheck_On_clicked"
QT_MOC_LITERAL(42, 1031, 17), // "IV_UpdateProgress"
QT_MOC_LITERAL(43, 1049, 11), // "sweepnumber"
QT_MOC_LITERAL(44, 1061, 22), // "IV_UpdateProgressLabel"
QT_MOC_LITERAL(45, 1084, 27), // "IV_UpdateProgressHighlights"
QT_MOC_LITERAL(46, 1112, 23), // "IV_AddSweepToSweepTable"
QT_MOC_LITERAL(47, 1136, 7), // "IVSweep"
QT_MOC_LITERAL(48, 1144, 7), // "ivsweep"
QT_MOC_LITERAL(49, 1152, 28), // "IV_DeleteSweepFromSweepTable"
QT_MOC_LITERAL(50, 1181, 20), // "IV_SweepTableChanged"
QT_MOC_LITERAL(51, 1202, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(52, 1220, 4), // "item"
QT_MOC_LITERAL(53, 1225, 37), // "IV_AddSweepAverageToSweepAver..."
QT_MOC_LITERAL(54, 1263, 15), // "IVSweepAverage&"
QT_MOC_LITERAL(55, 1279, 14), // "ivsweepaverage"
QT_MOC_LITERAL(56, 1294, 42), // "IV_DeleteSweepAverageFromSwee..."
QT_MOC_LITERAL(57, 1337, 15), // "IVSweepAverage*"
QT_MOC_LITERAL(58, 1353, 27), // "IV_SweepAverageTableChanged"
QT_MOC_LITERAL(59, 1381, 23), // "on_IV_Autoscale_clicked"
QT_MOC_LITERAL(60, 1405, 29), // "on_IV_AddToSweepQueue_pressed"
QT_MOC_LITERAL(61, 1435, 30), // "on_IV_AddToSweepQueue_released"
QT_MOC_LITERAL(62, 1466, 28), // "on_IV_LoadParameters_pressed"
QT_MOC_LITERAL(63, 1495, 29), // "on_IV_LoadParameters_released"
QT_MOC_LITERAL(64, 1525, 28), // "on_IV_SaveParameters_pressed"
QT_MOC_LITERAL(65, 1554, 29), // "on_IV_SaveParameters_released"
QT_MOC_LITERAL(66, 1584, 25), // "on_IV_SetSavePath_pressed"
QT_MOC_LITERAL(67, 1610, 26), // "on_IV_SetSavePath_released"
QT_MOC_LITERAL(68, 1637, 27), // "on_IV_SaveAllSweeps_pressed"
QT_MOC_LITERAL(69, 1665, 28), // "on_IV_SaveAllSweeps_released"
QT_MOC_LITERAL(70, 1694, 32), // "on_IV_SaveSelectedSweeps_pressed"
QT_MOC_LITERAL(71, 1727, 33), // "on_IV_SaveSelectedSweeps_rele..."
QT_MOC_LITERAL(72, 1761, 19), // "on_IV_Start_pressed"
QT_MOC_LITERAL(73, 1781, 20), // "on_IV_Start_released"
QT_MOC_LITERAL(74, 1802, 19), // "on_IV_Pause_pressed"
QT_MOC_LITERAL(75, 1822, 20), // "on_IV_Pause_released"
QT_MOC_LITERAL(76, 1843, 18), // "on_IV_Stop_pressed"
QT_MOC_LITERAL(77, 1862, 19), // "on_IV_Stop_released"
QT_MOC_LITERAL(78, 1882, 22), // "on_IV_ZoomOutX_clicked"
QT_MOC_LITERAL(79, 1905, 21), // "on_IV_ZoomInX_clicked"
QT_MOC_LITERAL(80, 1927, 22), // "on_IV_ZoomOutY_clicked"
QT_MOC_LITERAL(81, 1950, 21), // "on_IV_ZoomInY_clicked"
QT_MOC_LITERAL(82, 1972, 21), // "on_IV_ZoomInX_pressed"
QT_MOC_LITERAL(83, 1994, 22), // "on_IV_ZoomInX_released"
QT_MOC_LITERAL(84, 2017, 22), // "on_IV_ZoomOutX_pressed"
QT_MOC_LITERAL(85, 2040, 23), // "on_IV_ZoomOutX_released"
QT_MOC_LITERAL(86, 2064, 21), // "on_IV_ZoomInY_pressed"
QT_MOC_LITERAL(87, 2086, 22), // "on_IV_ZoomInY_released"
QT_MOC_LITERAL(88, 2109, 22), // "on_IV_ZoomOutY_pressed"
QT_MOC_LITERAL(89, 2132, 23), // "on_IV_ZoomOutY_released"
QT_MOC_LITERAL(90, 2156, 30), // "on_CurrentSample_Start_pressed"
QT_MOC_LITERAL(91, 2187, 31), // "on_CurrentSample_Start_released"
QT_MOC_LITERAL(92, 2219, 30), // "on_CurrentSample_Pause_pressed"
QT_MOC_LITERAL(93, 2250, 31), // "on_CurrentSample_Pause_released"
QT_MOC_LITERAL(94, 2282, 29), // "on_CurrentSample_Stop_pressed"
QT_MOC_LITERAL(95, 2312, 30), // "on_CurrentSample_Stop_released"
QT_MOC_LITERAL(96, 2343, 20), // "on_ZCheck_On_pressed"
QT_MOC_LITERAL(97, 2364, 21), // "on_ZCheck_On_released"
QT_MOC_LITERAL(98, 2386, 21), // "on_ZCheck_Off_pressed"
QT_MOC_LITERAL(99, 2408, 22), // "on_ZCheck_Off_released"
QT_MOC_LITERAL(100, 2431, 27), // "on_IncrementVoltage_pressed"
QT_MOC_LITERAL(101, 2459, 28), // "on_IncrementVoltage_released"
QT_MOC_LITERAL(102, 2488, 27), // "on_DecrementVoltage_pressed"
QT_MOC_LITERAL(103, 2516, 28), // "on_DecrementVoltage_released"
QT_MOC_LITERAL(104, 2545, 21), // "on_GetVoltage_pressed"
QT_MOC_LITERAL(105, 2567, 22), // "on_GetVoltage_released"
QT_MOC_LITERAL(106, 2590, 26), // "on_GetInstrumentID_pressed"
QT_MOC_LITERAL(107, 2617, 27), // "on_GetInstrumentID_released"
QT_MOC_LITERAL(108, 2645, 21), // "on_OpenDevice_pressed"
QT_MOC_LITERAL(109, 2667, 22), // "on_OpenDevice_released"
QT_MOC_LITERAL(110, 2690, 20), // "on_VoltageOn_clicked"
QT_MOC_LITERAL(111, 2711, 21), // "on_VoltageOff_clicked"
QT_MOC_LITERAL(112, 2733, 20), // "on_VoltageOn_pressed"
QT_MOC_LITERAL(113, 2754, 21), // "on_VoltageOn_released"
QT_MOC_LITERAL(114, 2776, 21), // "on_VoltageOff_pressed"
QT_MOC_LITERAL(115, 2798, 22), // "on_VoltageOff_released"
QT_MOC_LITERAL(116, 2821, 13), // "SortSweepList"
QT_MOC_LITERAL(117, 2835, 21), // "std::vector<IVSweep*>"
QT_MOC_LITERAL(118, 2857, 22), // "std::vector<IVSweep*>&"
QT_MOC_LITERAL(119, 2880, 9), // "sweeplist"
QT_MOC_LITERAL(120, 2890, 15), // "PrintSaveMatrix"
QT_MOC_LITERAL(121, 2906, 38), // "std::vector<std::vector<std::..."
QT_MOC_LITERAL(122, 2945, 10), // "savematrix"
QT_MOC_LITERAL(123, 2956, 34), // "on_CurrentSample_Autoscale_cl..."
QT_MOC_LITERAL(124, 2991, 33), // "on_CurrentSample_ZoomOutY_cli..."
QT_MOC_LITERAL(125, 3025, 32), // "on_CurrentSample_ZoomInY_clicked"
QT_MOC_LITERAL(126, 3058, 33), // "on_CurrentSample_ZoomOutY_pre..."
QT_MOC_LITERAL(127, 3092, 34), // "on_CurrentSample_ZoomOutY_rel..."
QT_MOC_LITERAL(128, 3127, 32), // "on_CurrentSample_ZoomInY_pressed"
QT_MOC_LITERAL(129, 3160, 33) // "on_CurrentSample_ZoomInY_rele..."

    },
    "MainWindow\0RequestCoProtocolPause\0\0"
    "Enable_AddToSweepQueue_Button\0"
    "EnableNeutralButton\0QPushButton*\0"
    "button\0DisableNeutralButton\0"
    "EnableGreenButton\0DisableGreenButton\0"
    "EnableYellowButton\0DisableYellowButton\0"
    "EnableRedButton\0DisableRedButton\0"
    "on_IV_Start_clicked\0on_IV_Pause_clicked\0"
    "on_IV_Unpause_clicked\0on_IV_Stop_clicked\0"
    "on_IV_SweepsCount_Field_textChanged\0"
    "on_IV_IncreaseSweepCount_clicked\0"
    "on_IV_DecreaseSweepCount_clicked\0"
    "on_IV_StartVoltage_Field_textChanged\0"
    "on_IV_EndVoltage_Field_textChanged\0"
    "on_IV_VoltageIncrement_Field_textChanged\0"
    "on_IV_Pause_Field_textChanged\0"
    "on_IV_AddToSweepQueue_clicked\0"
    "on_IV_LoadParameters_clicked\0"
    "on_IV_SaveParameters_clicked\0"
    "on_IV_SaveAllSweeps_clicked\0"
    "on_IV_SaveSelectedSweeps_clicked\0"
    "on_IV_SetSavePath_clicked\0"
    "on_CurrentSample_Start_clicked\0"
    "on_CurrentSample_Pause_clicked\0"
    "on_CurrentSample_Unpause_clicked\0"
    "on_CurrentSample_Stop_clicked\0"
    "on_OpenDevice_clicked\0on_IncrementVoltage_clicked\0"
    "on_DecrementVoltage_clicked\0"
    "on_GetVoltage_clicked\0on_GetInstrumentID_clicked\0"
    "on_ZCheck_Off_clicked\0on_ZCheck_On_clicked\0"
    "IV_UpdateProgress\0sweepnumber\0"
    "IV_UpdateProgressLabel\0"
    "IV_UpdateProgressHighlights\0"
    "IV_AddSweepToSweepTable\0IVSweep\0ivsweep\0"
    "IV_DeleteSweepFromSweepTable\0"
    "IV_SweepTableChanged\0QTableWidgetItem*\0"
    "item\0IV_AddSweepAverageToSweepAverageTable\0"
    "IVSweepAverage&\0ivsweepaverage\0"
    "IV_DeleteSweepAverageFromSweepAverageTable\0"
    "IVSweepAverage*\0IV_SweepAverageTableChanged\0"
    "on_IV_Autoscale_clicked\0"
    "on_IV_AddToSweepQueue_pressed\0"
    "on_IV_AddToSweepQueue_released\0"
    "on_IV_LoadParameters_pressed\0"
    "on_IV_LoadParameters_released\0"
    "on_IV_SaveParameters_pressed\0"
    "on_IV_SaveParameters_released\0"
    "on_IV_SetSavePath_pressed\0"
    "on_IV_SetSavePath_released\0"
    "on_IV_SaveAllSweeps_pressed\0"
    "on_IV_SaveAllSweeps_released\0"
    "on_IV_SaveSelectedSweeps_pressed\0"
    "on_IV_SaveSelectedSweeps_released\0"
    "on_IV_Start_pressed\0on_IV_Start_released\0"
    "on_IV_Pause_pressed\0on_IV_Pause_released\0"
    "on_IV_Stop_pressed\0on_IV_Stop_released\0"
    "on_IV_ZoomOutX_clicked\0on_IV_ZoomInX_clicked\0"
    "on_IV_ZoomOutY_clicked\0on_IV_ZoomInY_clicked\0"
    "on_IV_ZoomInX_pressed\0on_IV_ZoomInX_released\0"
    "on_IV_ZoomOutX_pressed\0on_IV_ZoomOutX_released\0"
    "on_IV_ZoomInY_pressed\0on_IV_ZoomInY_released\0"
    "on_IV_ZoomOutY_pressed\0on_IV_ZoomOutY_released\0"
    "on_CurrentSample_Start_pressed\0"
    "on_CurrentSample_Start_released\0"
    "on_CurrentSample_Pause_pressed\0"
    "on_CurrentSample_Pause_released\0"
    "on_CurrentSample_Stop_pressed\0"
    "on_CurrentSample_Stop_released\0"
    "on_ZCheck_On_pressed\0on_ZCheck_On_released\0"
    "on_ZCheck_Off_pressed\0on_ZCheck_Off_released\0"
    "on_IncrementVoltage_pressed\0"
    "on_IncrementVoltage_released\0"
    "on_DecrementVoltage_pressed\0"
    "on_DecrementVoltage_released\0"
    "on_GetVoltage_pressed\0on_GetVoltage_released\0"
    "on_GetInstrumentID_pressed\0"
    "on_GetInstrumentID_released\0"
    "on_OpenDevice_pressed\0on_OpenDevice_released\0"
    "on_VoltageOn_clicked\0on_VoltageOff_clicked\0"
    "on_VoltageOn_pressed\0on_VoltageOn_released\0"
    "on_VoltageOff_pressed\0on_VoltageOff_released\0"
    "SortSweepList\0std::vector<IVSweep*>\0"
    "std::vector<IVSweep*>&\0sweeplist\0"
    "PrintSaveMatrix\0std::vector<std::vector<std::string> >\0"
    "savematrix\0on_CurrentSample_Autoscale_clicked\0"
    "on_CurrentSample_ZoomOutY_clicked\0"
    "on_CurrentSample_ZoomInY_clicked\0"
    "on_CurrentSample_ZoomOutY_pressed\0"
    "on_CurrentSample_ZoomOutY_released\0"
    "on_CurrentSample_ZoomInY_pressed\0"
    "on_CurrentSample_ZoomInY_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     113,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  579,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  580,    2, 0x08 /* Private */,
       4,    1,  581,    2, 0x08 /* Private */,
       7,    1,  584,    2, 0x08 /* Private */,
       8,    1,  587,    2, 0x08 /* Private */,
       9,    1,  590,    2, 0x08 /* Private */,
      10,    1,  593,    2, 0x08 /* Private */,
      11,    1,  596,    2, 0x08 /* Private */,
      12,    1,  599,    2, 0x08 /* Private */,
      13,    1,  602,    2, 0x08 /* Private */,
      14,    0,  605,    2, 0x08 /* Private */,
      15,    0,  606,    2, 0x08 /* Private */,
      16,    0,  607,    2, 0x08 /* Private */,
      17,    0,  608,    2, 0x08 /* Private */,
      18,    0,  609,    2, 0x08 /* Private */,
      19,    0,  610,    2, 0x08 /* Private */,
      20,    0,  611,    2, 0x08 /* Private */,
      21,    0,  612,    2, 0x08 /* Private */,
      22,    0,  613,    2, 0x08 /* Private */,
      23,    0,  614,    2, 0x08 /* Private */,
      24,    0,  615,    2, 0x08 /* Private */,
      25,    0,  616,    2, 0x08 /* Private */,
      26,    0,  617,    2, 0x08 /* Private */,
      27,    0,  618,    2, 0x08 /* Private */,
      28,    0,  619,    2, 0x08 /* Private */,
      29,    0,  620,    2, 0x08 /* Private */,
      30,    0,  621,    2, 0x08 /* Private */,
      31,    0,  622,    2, 0x08 /* Private */,
      32,    0,  623,    2, 0x08 /* Private */,
      33,    0,  624,    2, 0x08 /* Private */,
      34,    0,  625,    2, 0x08 /* Private */,
      35,    0,  626,    2, 0x08 /* Private */,
      36,    0,  627,    2, 0x08 /* Private */,
      37,    0,  628,    2, 0x08 /* Private */,
      38,    0,  629,    2, 0x08 /* Private */,
      39,    0,  630,    2, 0x08 /* Private */,
      40,    0,  631,    2, 0x08 /* Private */,
      41,    0,  632,    2, 0x08 /* Private */,
      42,    1,  633,    2, 0x08 /* Private */,
      44,    0,  636,    2, 0x08 /* Private */,
      45,    1,  637,    2, 0x08 /* Private */,
      46,    1,  640,    2, 0x08 /* Private */,
      49,    1,  643,    2, 0x08 /* Private */,
      50,    1,  646,    2, 0x08 /* Private */,
      53,    1,  649,    2, 0x08 /* Private */,
      56,    1,  652,    2, 0x08 /* Private */,
      58,    1,  655,    2, 0x08 /* Private */,
      59,    0,  658,    2, 0x08 /* Private */,
      60,    0,  659,    2, 0x08 /* Private */,
      61,    0,  660,    2, 0x08 /* Private */,
      62,    0,  661,    2, 0x08 /* Private */,
      63,    0,  662,    2, 0x08 /* Private */,
      64,    0,  663,    2, 0x08 /* Private */,
      65,    0,  664,    2, 0x08 /* Private */,
      66,    0,  665,    2, 0x08 /* Private */,
      67,    0,  666,    2, 0x08 /* Private */,
      68,    0,  667,    2, 0x08 /* Private */,
      69,    0,  668,    2, 0x08 /* Private */,
      70,    0,  669,    2, 0x08 /* Private */,
      71,    0,  670,    2, 0x08 /* Private */,
      72,    0,  671,    2, 0x08 /* Private */,
      73,    0,  672,    2, 0x08 /* Private */,
      74,    0,  673,    2, 0x08 /* Private */,
      75,    0,  674,    2, 0x08 /* Private */,
      76,    0,  675,    2, 0x08 /* Private */,
      77,    0,  676,    2, 0x08 /* Private */,
      78,    0,  677,    2, 0x08 /* Private */,
      79,    0,  678,    2, 0x08 /* Private */,
      80,    0,  679,    2, 0x08 /* Private */,
      81,    0,  680,    2, 0x08 /* Private */,
      82,    0,  681,    2, 0x08 /* Private */,
      83,    0,  682,    2, 0x08 /* Private */,
      84,    0,  683,    2, 0x08 /* Private */,
      85,    0,  684,    2, 0x08 /* Private */,
      86,    0,  685,    2, 0x08 /* Private */,
      87,    0,  686,    2, 0x08 /* Private */,
      88,    0,  687,    2, 0x08 /* Private */,
      89,    0,  688,    2, 0x08 /* Private */,
      90,    0,  689,    2, 0x08 /* Private */,
      91,    0,  690,    2, 0x08 /* Private */,
      92,    0,  691,    2, 0x08 /* Private */,
      93,    0,  692,    2, 0x08 /* Private */,
      94,    0,  693,    2, 0x08 /* Private */,
      95,    0,  694,    2, 0x08 /* Private */,
      96,    0,  695,    2, 0x08 /* Private */,
      97,    0,  696,    2, 0x08 /* Private */,
      98,    0,  697,    2, 0x08 /* Private */,
      99,    0,  698,    2, 0x08 /* Private */,
     100,    0,  699,    2, 0x08 /* Private */,
     101,    0,  700,    2, 0x08 /* Private */,
     102,    0,  701,    2, 0x08 /* Private */,
     103,    0,  702,    2, 0x08 /* Private */,
     104,    0,  703,    2, 0x08 /* Private */,
     105,    0,  704,    2, 0x08 /* Private */,
     106,    0,  705,    2, 0x08 /* Private */,
     107,    0,  706,    2, 0x08 /* Private */,
     108,    0,  707,    2, 0x08 /* Private */,
     109,    0,  708,    2, 0x08 /* Private */,
     110,    0,  709,    2, 0x08 /* Private */,
     111,    0,  710,    2, 0x08 /* Private */,
     112,    0,  711,    2, 0x08 /* Private */,
     113,    0,  712,    2, 0x08 /* Private */,
     114,    0,  713,    2, 0x08 /* Private */,
     115,    0,  714,    2, 0x08 /* Private */,
     116,    1,  715,    2, 0x08 /* Private */,
     120,    1,  718,    2, 0x08 /* Private */,
     123,    0,  721,    2, 0x08 /* Private */,
     124,    0,  722,    2, 0x08 /* Private */,
     125,    0,  723,    2, 0x08 /* Private */,
     126,    0,  724,    2, 0x08 /* Private */,
     127,    0,  725,    2, 0x08 /* Private */,
     128,    0,  726,    2, 0x08 /* Private */,
     129,    0,  727,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void, QMetaType::UInt,   43,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void, 0x80000000 | 54,   55,
    QMetaType::Void, 0x80000000 | 57,   55,
    QMetaType::Void, 0x80000000 | 51,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 117, 0x80000000 | 118,  119,
    QMetaType::Void, 0x80000000 | 121,  122,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestCoProtocolPause(); break;
        case 1: _t->Enable_AddToSweepQueue_Button(); break;
        case 2: _t->EnableNeutralButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 3: _t->DisableNeutralButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 4: _t->EnableGreenButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 5: _t->DisableGreenButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 6: _t->EnableYellowButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 7: _t->DisableYellowButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 8: _t->EnableRedButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 9: _t->DisableRedButton((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 10: _t->on_IV_Start_clicked(); break;
        case 11: _t->on_IV_Pause_clicked(); break;
        case 12: _t->on_IV_Unpause_clicked(); break;
        case 13: _t->on_IV_Stop_clicked(); break;
        case 14: _t->on_IV_SweepsCount_Field_textChanged(); break;
        case 15: _t->on_IV_IncreaseSweepCount_clicked(); break;
        case 16: _t->on_IV_DecreaseSweepCount_clicked(); break;
        case 17: _t->on_IV_StartVoltage_Field_textChanged(); break;
        case 18: _t->on_IV_EndVoltage_Field_textChanged(); break;
        case 19: _t->on_IV_VoltageIncrement_Field_textChanged(); break;
        case 20: _t->on_IV_Pause_Field_textChanged(); break;
        case 21: _t->on_IV_AddToSweepQueue_clicked(); break;
        case 22: _t->on_IV_LoadParameters_clicked(); break;
        case 23: _t->on_IV_SaveParameters_clicked(); break;
        case 24: _t->on_IV_SaveAllSweeps_clicked(); break;
        case 25: _t->on_IV_SaveSelectedSweeps_clicked(); break;
        case 26: _t->on_IV_SetSavePath_clicked(); break;
        case 27: _t->on_CurrentSample_Start_clicked(); break;
        case 28: _t->on_CurrentSample_Pause_clicked(); break;
        case 29: _t->on_CurrentSample_Unpause_clicked(); break;
        case 30: _t->on_CurrentSample_Stop_clicked(); break;
        case 31: _t->on_OpenDevice_clicked(); break;
        case 32: _t->on_IncrementVoltage_clicked(); break;
        case 33: _t->on_DecrementVoltage_clicked(); break;
        case 34: _t->on_GetVoltage_clicked(); break;
        case 35: _t->on_GetInstrumentID_clicked(); break;
        case 36: _t->on_ZCheck_Off_clicked(); break;
        case 37: _t->on_ZCheck_On_clicked(); break;
        case 38: _t->IV_UpdateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->IV_UpdateProgressLabel(); break;
        case 40: _t->IV_UpdateProgressHighlights((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->IV_AddSweepToSweepTable((*reinterpret_cast< const IVSweep(*)>(_a[1]))); break;
        case 42: _t->IV_DeleteSweepFromSweepTable((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 43: _t->IV_SweepTableChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 44: _t->IV_AddSweepAverageToSweepAverageTable((*reinterpret_cast< IVSweepAverage(*)>(_a[1]))); break;
        case 45: _t->IV_DeleteSweepAverageFromSweepAverageTable((*reinterpret_cast< IVSweepAverage*(*)>(_a[1]))); break;
        case 46: _t->IV_SweepAverageTableChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 47: _t->on_IV_Autoscale_clicked(); break;
        case 48: _t->on_IV_AddToSweepQueue_pressed(); break;
        case 49: _t->on_IV_AddToSweepQueue_released(); break;
        case 50: _t->on_IV_LoadParameters_pressed(); break;
        case 51: _t->on_IV_LoadParameters_released(); break;
        case 52: _t->on_IV_SaveParameters_pressed(); break;
        case 53: _t->on_IV_SaveParameters_released(); break;
        case 54: _t->on_IV_SetSavePath_pressed(); break;
        case 55: _t->on_IV_SetSavePath_released(); break;
        case 56: _t->on_IV_SaveAllSweeps_pressed(); break;
        case 57: _t->on_IV_SaveAllSweeps_released(); break;
        case 58: _t->on_IV_SaveSelectedSweeps_pressed(); break;
        case 59: _t->on_IV_SaveSelectedSweeps_released(); break;
        case 60: _t->on_IV_Start_pressed(); break;
        case 61: _t->on_IV_Start_released(); break;
        case 62: _t->on_IV_Pause_pressed(); break;
        case 63: _t->on_IV_Pause_released(); break;
        case 64: _t->on_IV_Stop_pressed(); break;
        case 65: _t->on_IV_Stop_released(); break;
        case 66: _t->on_IV_ZoomOutX_clicked(); break;
        case 67: _t->on_IV_ZoomInX_clicked(); break;
        case 68: _t->on_IV_ZoomOutY_clicked(); break;
        case 69: _t->on_IV_ZoomInY_clicked(); break;
        case 70: _t->on_IV_ZoomInX_pressed(); break;
        case 71: _t->on_IV_ZoomInX_released(); break;
        case 72: _t->on_IV_ZoomOutX_pressed(); break;
        case 73: _t->on_IV_ZoomOutX_released(); break;
        case 74: _t->on_IV_ZoomInY_pressed(); break;
        case 75: _t->on_IV_ZoomInY_released(); break;
        case 76: _t->on_IV_ZoomOutY_pressed(); break;
        case 77: _t->on_IV_ZoomOutY_released(); break;
        case 78: _t->on_CurrentSample_Start_pressed(); break;
        case 79: _t->on_CurrentSample_Start_released(); break;
        case 80: _t->on_CurrentSample_Pause_pressed(); break;
        case 81: _t->on_CurrentSample_Pause_released(); break;
        case 82: _t->on_CurrentSample_Stop_pressed(); break;
        case 83: _t->on_CurrentSample_Stop_released(); break;
        case 84: _t->on_ZCheck_On_pressed(); break;
        case 85: _t->on_ZCheck_On_released(); break;
        case 86: _t->on_ZCheck_Off_pressed(); break;
        case 87: _t->on_ZCheck_Off_released(); break;
        case 88: _t->on_IncrementVoltage_pressed(); break;
        case 89: _t->on_IncrementVoltage_released(); break;
        case 90: _t->on_DecrementVoltage_pressed(); break;
        case 91: _t->on_DecrementVoltage_released(); break;
        case 92: _t->on_GetVoltage_pressed(); break;
        case 93: _t->on_GetVoltage_released(); break;
        case 94: _t->on_GetInstrumentID_pressed(); break;
        case 95: _t->on_GetInstrumentID_released(); break;
        case 96: _t->on_OpenDevice_pressed(); break;
        case 97: _t->on_OpenDevice_released(); break;
        case 98: _t->on_VoltageOn_clicked(); break;
        case 99: _t->on_VoltageOff_clicked(); break;
        case 100: _t->on_VoltageOn_pressed(); break;
        case 101: _t->on_VoltageOn_released(); break;
        case 102: _t->on_VoltageOff_pressed(); break;
        case 103: _t->on_VoltageOff_released(); break;
        case 104: { std::vector<IVSweep*> _r = _t->SortSweepList((*reinterpret_cast< std::vector<IVSweep*>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::vector<IVSweep*>*>(_a[0]) = std::move(_r); }  break;
        case 105: _t->PrintSaveMatrix((*reinterpret_cast< std::vector<std::vector<std::string> >(*)>(_a[1]))); break;
        case 106: _t->on_CurrentSample_Autoscale_clicked(); break;
        case 107: _t->on_CurrentSample_ZoomOutY_clicked(); break;
        case 108: _t->on_CurrentSample_ZoomInY_clicked(); break;
        case 109: _t->on_CurrentSample_ZoomOutY_pressed(); break;
        case 110: _t->on_CurrentSample_ZoomOutY_released(); break;
        case 111: _t->on_CurrentSample_ZoomInY_pressed(); break;
        case 112: _t->on_CurrentSample_ZoomInY_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::RequestCoProtocolPause)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 113)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 113;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 113)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 113;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::RequestCoProtocolPause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
