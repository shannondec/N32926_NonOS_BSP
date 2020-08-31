/**************************************************************************//**
 * @file     writer.h
 * @brief    SdWriter header file.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#define MAJOR_VERSION_NUM   1
#define MINOR_VERSION_NUM   2

extern UINT g_Font_Height, g_Font_Width, g_Font_Step;

#define COLOR_RGB16_RED     0xF800
#define COLOR_RGB16_WHITE   0xFFFF
#define COLOR_RGB16_GREEN   0x07E0
#define COLOR_RGB16_BLACK   0x0000

#define NVT_SM_INFO_T FMI_SM_INFO_T

/* F/W update information */
typedef struct fw_update_info_t
{
    UINT16  imageNo;
    UINT16  imageFlag;
    UINT16  startBlock;
    UINT16  endBlock;
    UINT32  executeAddr;
    UINT32  fileLen;
    CHAR    imageName[32];
} FW_UPDATE_INFO_T;

typedef struct IBR_boot_struct_t
{
    UINT32  BootCodeMarker;
    UINT32  ExeAddr;
    UINT32  ImageSize;
    UINT32  Reserved;
} IBR_BOOT_STRUCT_T;

typedef struct INI_Info {
    char SDLoader[512];
    char Logo[512];
    char NVTLoader[512];
    int  SystemReservedMegaByte;
    int  SD1_1_SIZE;
    int  SD1_1_FAT;
    int  SD1_2_FAT;
    int  Target_SD_Port;
} INI_INFO_T;


//----- Boot Code Optional Setting
typedef struct IBR_boot_optional_pairs_struct_t
{
    UINT32  address;
    UINT32  value;
} IBR_BOOT_OPTIONAL_PAIRS_STRUCT_T;

#define IBR_BOOT_CODE_OPTIONAL_MARKER       0xAA55AA55
#define IBR_BOOT_CODE_OPTIONAL_MAX_NUMBER   63  // support maximum 63 pairs optional setting
typedef struct IBR_boot_optional_struct_t
{
    UINT32  OptionalMarker;
    UINT32  Counter;
    IBR_BOOT_OPTIONAL_PAIRS_STRUCT_T Pairs[IBR_BOOT_CODE_OPTIONAL_MAX_NUMBER];
} IBR_BOOT_OPTIONAL_STRUCT_T;


/* extern parameters */
extern UINT32 infoBuf;
extern UINT8 *pInfo;

void Draw_Font(UINT16 u16RGB,S_DEMO_FONT* ptFont,UINT32 u32x,UINT32 u32y,PCSTR  pszString);
void Draw_Status(UINT32 u32x,UINT32 u32y,int Status);
void Draw_Clear(int xStart, int yStart, int xEnd, int yEnd, UINT16 color);
void Draw_CurrentOperation(PCSTR pszString, int Retcode);
void Draw_FinalStatus(int bIsAbort);
void Draw_Init(void);
void Draw_Wait_Status(UINT32 u32x, UINT32 u32y);
void Draw_Clear_Wait_Status(UINT32 u32x, UINT32 u32y);

int ProcessINI(char *fileName);
int ProcessOptionalINI(char *fileName);
