/*!
 * @file mfci_io_70.h
 * @brief Упакованные входные и выходные данные МФЦИ и БГС для проектов СОИ-70М и СОИ-70М-506
 * @author Илья Кулаков
 * @copyright АО ОКБ "Электроавтоматика", НИЦ-1
 * @details
 * #### Номер ВИДК
 *    нет
 * #### Комментарии
 *    Таблица подадресов:
 *    Вх  МКИО-3.1 п/а 01-03   - 25 Гц   - передается постоянно (сигнализация)
 *    Вх  МКИО-3.1 п/а 04      - 25 Гц   - КПИ, ПНП, ПЛАН, КАРТ, СУО, ГРУП, ДВ/С, ДВ, УПР
 *    Вх  МКИО-3.1 п/а 05      - 25 Гц   - ДВ/С, ДВ, КПИ
 *    Вх  МКИО-3.1 п/а 06      - 25 Гц   - ДВ/С, ДВ
 *    Вх  МКИО-3.1 п/а 07-09   - 12.5 Гц - ДВ/С, ДВ
 *    Вх  МКИО-3.1 п/а 10      - 12.5 Гц - КПИ, ПНП, ПЛАН, КАРТ, СУО, ГРУП, ДВ/С, ДВ
 *    Вх  МКИО-3.1 п/а 11      - 12.5 Гц - передается постоянно (ПУИ/МУП)
 *    Вх  МКИО-3.1 п/а 12      - 12.5 Гц - КПИ, ПНП, ПЛАН, КАРТ, СУО, УПР
 *    Вх  МКИО-3.1 п/а 13      - 12.5 Гц - КПИ, ПНП, ПЛАН, КАРТ, СУО
 *    Вх  МКИО-3.1 п/а 14      - 12.5 Гц - КПИ, ПНП, РЛС, ГРУП
 *    Вх  МКИО-3.1 п/а 15      - 12.5 Гц - ГРУП
 *    Вх  МКИО-3.1 п/а 16-18   - 12.5 Гц - РЭП
 *    Вх  МКИО-3.1 п/а 19      - 6.25 Гц - СЭС
 *    Вх  МКИО-3.1 п/а 20      - 6.25 Гц - СЭС, СКВ
 *    Вх  МКИО-3.1 п/а 21      - 6.25 Гц - КПИ, УПР, ДВ/С, ТОПЛ
 *    Вх  МКИО-3.1 п/а 22      - 6.25 Гц - УПР, ТОПЛ
 *    Вх  МКИО-3.1 п/а 23      - 6.25 Гц - ТОПЛ, ВСУ
 *    Вх  МКИО-3.1 п/а 24      - 6.25 Гц - ВСУ, СКВ, ГС
 *    Вх  МКИО-3.1 п/а 25      - 1 Гц    - передается постоянно (слова УПР)
 *    Вх  МКИО-3.1 п/а 26-28   - 1 Гц    - СВР/БАСК/БЛОКИ/КС/СЗИ/ТАР
 *    Вх  МКИО-3.1 п/а 29-30   - 6.25 Гц - передается постоянно (план полета)
 *    Вх  МКИО-3.1 п/а 1-3 адр - 1 Гц    - данные из МФЦИ в БГС
 *    Вых МКИО-3.1 п/а 01      - 12.5 Гц - состояние и управляющие сигналы
 *    Вых МКИО-3.1 п/а 02-03   - 12.5 Гц - версии и контрольные суммы ПО
 *    Вых МКИО-3.1 п/а 05      - 12.5 Гц - курсор МУП
 *    Вх  МКИО-3.2 п/а 01-20   - 12.5 Гц - СУО (из ФПО БП)
 *    Вх  МКИО-3.2 п/а 21-23   - 12.5 Гц - СУО (из МФЦИ в БГС)
 *    Вх  МКИО-3.2 п/а 24      - 6.25 Гц - ФОВБ
 *    Вх  МКИО-3.2 п/а 25      - 1 Гц    - СЗИ
 *    Вх  МКИО-3.2 п/а 26      - 12.5 Гц - ИИПЭ
 *    Вх  МКИО-3.2 п/а 27-29   - 6.25 Гц - АСУ
 *    Вх  МКИО-3.2 п/а 30      - 1 Гц    - АСУ-МФПУ и 19ДА
 *    Вых МКИО-3.2 п/а 01      - 12.5 Гц - состояние и управляющие сигналы
 *    Вых МКИО-3.2 п/а 04      - 12.5 Гц - АСУ
 *    Вых МКИО-3.2 п/а 06-07   - 12.5 Гц - АСУ-МФПУ
 *    Вых МКИО-3.2 п/а 08      - 12.5 Гц - ТИ и курсор СУО-504/506
 *    Номер ревизии ПФ кадра МФЦИ "СУО 504/506": 8
 * #### Дата последнего изменения файла
 *    26 августа 2022 г.
 */
// clang-format off
#pragma once
#if defined(SOI45) || defined(SOI70)
#include <ctypes.h>
#else
#include "addefs.h"
#endif

//! Ревизия заголовочника mfci_io_70.h
#define MFCI_IO_REVISION 12318

#define MFCI_COUNT              11     //!< Количество МФЦИ
#define DV_COUNT                4      //!< Количество двигателей
#define BGS_CPU_COUNT           2      //!< Количество ЦПУ БГС
#define CRC_PO_MAX_COUNT        60     //!< Максимальное число компонентов ПО в устройстве
#define CRC_PO_PER_MESSAGE_IN   45     //!< Количество данных о компонентах ПО, передаваемых в одном сообщении SpaceWire на вход МГ-100 БГС
#define CRC_PO_PER_MESSAGE_OUT  7      //!< Количество данных о компонентах ПО, передаваемых в одном сообщении SpaceWire с выхода МГ-100 БГС
#define CRC_SA_COUNT            3      //!< Количество подадресов, выделенных для передачи данных о компонентах ПО
#define ASU_SA_COUNT            3      //!< Количество подадресов, выделенных для передачи сегментов команды АСУ
#define ASU_SEGMENT_SIZE_MAX    48     //!< Максимальный размер сегмента команды АСУ в байтах
#define ASU_SEGMENT_WORDS_COUNT 24     //!< Количество слов данных, выделенных для передачи сегмента команды АСУ
#define ASU_COMMAND_SIZE_MAX    12288  //!< Максимальный размер команды АСУ
#define UPR_FLAG_WORD_MASK_1    0xffc0 //!< Маска синхронизируемых признаков слова 1 сигналов УПР (upr_flag_word_common_1_b_t)
#define UPR_FLAG_WORD_MASK_2    0xffff //!< Маска синхронизируемых признаков слова 2 сигналов УПР (upr_flag_word_common_2_b_t)

#ifdef MFPU_TO_MFCI_MSG1_SIZE
#undef MFPU_TO_MFCI_MSG1_SIZE
#endif
#define MFPU_TO_MFCI_MSG1_SIZE 8 //!< Количество слов данных, передаваемых из штурманских МФПУ в штурманские МФЦИ по МКИО-1.1/3.1 (данные редактируемого объекта плана полета)

#ifdef MFPU_TO_MFCI_MSG2_SIZE
#undef MFPU_TO_MFCI_MSG2_SIZE
#endif
#define MFPU_TO_MFCI_MSG2_SIZE 28 //!< Количество слов данных, передаваемых из управляющего МФПУ в МФЦИ по МКИО-1.2/3.2 (данные АСУ)

//! Кадр МФЦИ
typedef enum mfci_format_t {
   MFCI_FORMAT_ND,         //!< Кадр не определен
   MFCI_FORMAT_KPI,        //!< Кадр "КПИ"
   MFCI_FORMAT_UUAP,       //!< Кадр "УУАП"
   MFCI_FORMAT_PNP,        //!< Кадр "ПНП"
   MFCI_FORMAT_PLAN,       //!< Кадр "ПЛАН"
   MFCI_FORMAT_KART,       //!< Кадр "КАРТА"
   MFCI_FORMAT_KART_NSTR,  //!< Кадр "КАРТА:НСТР"
   MFCI_FORMAT_GRUP,       //!< Кадр "ГРУП"
   MFCI_FORMAT_RLS,        //!< Кадр "РЛС"
   MFCI_FORMAT_OAPS,       //!< Кадр "ОЭПС"
   MFCI_FORMAT_KVR,        //!< Кадр "КВР"
   MFCI_FORMAT_ASU,        //!< Кадр "АСУ"
   MFCI_FORMAT_RAP,        //!< Кадр "РЭП"
   MFCI_FORMAT_SVR,        //!< Кадр "СВР"
   MFCI_FORMAT_DVS,        //!< Кадр "ДВ/С"
   MFCI_FORMAT_DV,         //!< Кадр "ДВ"
   MFCI_FORMAT_19DA,       //!< Кадр "19ДА"
   MFCI_FORMAT_TOPL,       //!< Кадр "ТОПЛ"
   MFCI_FORMAT_SKV,        //!< Кадр "СКВ"
   MFCI_FORMAT_SAS,        //!< Кадр "СЭС"
   MFCI_FORMAT_UPR,        //!< Кадр "УПР"
   MFCI_FORMAT_GS,         //!< Кадр "ГС"
   MFCI_FORMAT_VSU,        //!< Кадр "ВСУ"
   MFCI_FORMAT_SOST,       //!< Кадр "СОСТ"
   MFCI_FORMAT_RLA,        //!< Кадр "РЛЭ"
   MFCI_FORMAT_KKD,        //!< Кадр "ККД"
   MFCI_FORMAT_BASK,       //!< Кадр "БАСК"
   MFCI_FORMAT_MSRP,       //!< Кадр "МСРП"
   MFCI_FORMAT_BLOCKS,     //!< Кадр "БЛОКИ" - Корневая страница/Общий перечень отказов/страница системы
   MFCI_FORMAT_BLOCKS_CRC, //!< Кадр "БЛОКИ" - Контрольные суммы
   MFCI_FORMAT_BLOCKS_SZI, //!< Кадр "БЛОКИ" - СЗИ
   MFCI_FORMAT_TAR,        //!< Кадр "ТАР"
   MFCI_FORMAT_SUO,        //!< Кадр "СУО"
   MFCI_FORMAT_SUO_IIPA,   //!< Кадр "СУО-ИИПЭ"
   MFCI_FORMATS_COUNT      //!< Количество кадров МФЦИ
} mfci_format_t;

//! Масштаб МФЦИ
typedef enum mfci_scale_t {
   MFCI_SCALE_20,    //!< Масштаб МФЦИ М:20 км
   MFCI_SCALE_40,    //!< Масштаб МФЦИ М:40 км
   MFCI_SCALE_80,    //!< Масштаб МФЦИ М:80 км
   MFCI_SCALE_160,   //!< Масштаб МФЦИ М:160 км
   MFCI_SCALE_320,   //!< Масштаб МФЦИ М:320 км
   MFCI_SCALE_640,   //!< Масштаб МФЦИ М:640 км
   MFCI_SCALE_1280,  //!< Масштаб МФЦИ М:1280 км
   MFCI_SCALE_2560,  //!< Масштаб МФЦИ М:2560 км
   MFCI_SCALE_5120,  //!< Масштаб МФЦИ М:5120 км
   MFCI_SCALES_COUNT //!< Количество вариантов масштаба МФЦИ
} mfci_scale_t;

//! Масштаб МФЦИ для отображения информации о полете самолетов в группе
typedef enum mfci_group_scale_t {
   MFCI_GROUP_SCALE_500,   //!< Масштаб МФЦИ М:500 м
   MFCI_GROUP_SCALE_1,     //!< Масштаб МФЦИ М:1 км
   MFCI_GROUP_SCALE_5,     //!< Масштаб МФЦИ М:5 км
   MFCI_GROUP_SCALE_10,    //!< Масштаб МФЦИ М:10 км
   MFCI_GROUP_SCALE_20,    //!< Масштаб МФЦИ М:20 км
   MFCI_GROUP_SCALE_40,    //!< Масштаб МФЦИ М:40 км
   MFCI_GROUP_SCALES_COUNT //!< Количество вариантов масштаба МФЦИ для отображения информации о полете самолетов в группе
} mfci_group_scale_t;

//! Контролируемая система кадра "БЛОКИ"
typedef enum mfci_blocks_system_t {
   MFCI_BLOCKS_SYSTEM_BIS_1,   //!< Контролируемая система БИС 1
   MFCI_BLOCKS_SYSTEM_BIS_2,   //!< Контролируемая система БИС 2
   MFCI_BLOCKS_SYSTEM_BCVM_1,  //!< Контролируемая система БЦВМ 1
   MFCI_BLOCKS_SYSTEM_BCVM_2,  //!< Контролируемая система БЦВМ 2
   MFCI_BLOCKS_SYSTEM_BVD_1,   //!< Контролируемая система БВД 1
   MFCI_BLOCKS_SYSTEM_BVD_2,   //!< Контролируемая система БВД 2
   MFCI_BLOCKS_SYSTEM_UKS_1,   //!< Контролируемая система УКС 1
   MFCI_BLOCKS_SYSTEM_UKS_2,   //!< Контролируемая система УКС 2
   MFCI_BLOCKS_SYSTEM_UKS_3,   //!< Контролируемая система УКС 3
   MFCI_BLOCKS_SYSTEM_UKS_4,   //!< Контролируемая система УКС 4
   MFCI_BLOCKS_SYSTEM_MFPU_1,  //!< Контролируемая система МФПУ 1
   MFCI_BLOCKS_SYSTEM_MFPU_2,  //!< Контролируемая система МФПУ 2
   MFCI_BLOCKS_SYSTEM_MFPU_3,  //!< Контролируемая система МФПУ 3
   MFCI_BLOCKS_SYSTEM_BGS_1,   //!< Контролируемая система БГС 1
   MFCI_BLOCKS_SYSTEM_BGS_2,   //!< Контролируемая система БГС 2
   MFCI_BLOCKS_SYSTEM_MFCI_1,  //!< Контролируемая система МФЦИ 1
   MFCI_BLOCKS_SYSTEM_MFCI_2,  //!< Контролируемая система МФЦИ 2
   MFCI_BLOCKS_SYSTEM_MFCI_3,  //!< Контролируемая система МФЦИ 3
   MFCI_BLOCKS_SYSTEM_MFCI_4,  //!< Контролируемая система МФЦИ 4
   MFCI_BLOCKS_SYSTEM_MFCI_5,  //!< Контролируемая система МФЦИ 5
   MFCI_BLOCKS_SYSTEM_MFCI_6,  //!< Контролируемая система МФЦИ 6
   MFCI_BLOCKS_SYSTEM_MFCI_7,  //!< Контролируемая система МФЦИ 7
   MFCI_BLOCKS_SYSTEM_MFCI_8,  //!< Контролируемая система МФЦИ 8
   MFCI_BLOCKS_SYSTEM_MFCI_9,  //!< Контролируемая система МФЦИ 9
   MFCI_BLOCKS_SYSTEM_MFCI_10, //!< Контролируемая система МФЦИ 10
   MFCI_BLOCKS_SYSTEM_MFCI_11, //!< Контролируемая система МФЦИ 11
   MFCI_BLOCKS_SYSTEM_PUI_1,   //!< Контролируемая система ПУИ 1
   MFCI_BLOCKS_SYSTEM_PUI_2,   //!< Контролируемая система ПУИ 2
   MFCI_BLOCKS_SYSTEM_MUP_1,   //!< Контролируемая система МУП 1
   MFCI_BLOCKS_SYSTEM_MUP_2,   //!< Контролируемая система МУП 2
   MFCI_BLOCKS_SYSTEM_KVI_1,   //!< Контролируемая система КВИ 1
   MFCI_BLOCKS_SYSTEM_KVI_2,   //!< Контролируемая система КВИ 2
   MFCI_BLOCKS_SYSTEM_1P8M_1,  //!< Контролируемая система 1П8М 1
   MFCI_BLOCKS_SYSTEM_1P8M_2,  //!< Контролируемая система 1П8М 2
   MFCI_BLOCKS_SYSTEM_1P2M_1,  //!< Контролируемая система 1П2М 1
   MFCI_BLOCKS_SYSTEM_1P2M_2,  //!< Контролируемая система 1П2М 2
   MFCI_BLOCKS_SYSTEMS_COUNT   //!< Количество контролируемых систем кадра "БЛОКИ"
} mfci_blocks_system_t;

//! Режим работы кадра "БЛОКИ"
typedef enum mfci_blocks_mode_t {
   MFCI_BLOCKS_MODE_FORMAT,          //!< Режим работы кадра "БЛОКИ" - основной кадр
   MFCI_BLOCKS_MODE_CRC,             //!< Режим работы кадра "БЛОКИ" - контрольные суммы
   MFCI_BLOCKS_MODE_FAILURES,        //!< Режим работы кадра "БЛОКИ" - сводный перечень отказов
   MFCI_BLOCKS_MODE_REQUEST,         //!< Режим работы кадра "БЛОКИ" - запрос
   MFCI_BLOCKS_MODE_SZI,             //!< Режим работы кадра "БЛОКИ" - события СЗИ
   MFCI_BLOCKS_MODE_BUTTONS_TEST,    //!< Режим работы кадра "БЛОКИ" - тест кнопок
   MFCI_BLOCKS_MODE_BRIGHTNESS_TEST, //!< Режим работы кадра "БЛОКИ" - тест яркости
   MFCI_BLOCKS_MODE_CONTRAST_TEST,   //!< Режим работы кадра "БЛОКИ" - тест контрастности
   MFCI_BLOCKS_MODE_COUNT            //!< Количество состояний кадра "БЛОКИ"
} mfci_blocks_mode_t;

//! Идентификатор тарируемого параметра УКС
typedef enum uks_tar_parameter_t {
   UKS_TAR_SUR_STAB,            //!< [СУР-А004] Положение стабилизатора
   UKS_TAR_SUR_FIN,             //!< [СУР-А003] Положение киля
   UKS_TAR_SUR_FLAPERON_LEFT,   //!< [СУР-А020] Положение левого флаперона
   UKS_TAR_SUR_FLAPERON_RIGHT,  //!< [СУР-А021] Положение правого флаперона
   UKS_TAR_SUR_INTERCEPTOR_R12, //!< [СУР-А006] Положение секции I и II правых интерцепторов
   UKS_TAR_SUR_INTERCEPTOR_R34, //!< [СУР-А007] Положение секции III и IV правых интерцепторов
   UKS_TAR_SUR_INTERCEPTOR_R56, //!< [СУР-А008] Положение секции V и VI правых интерцепторов
   UKS_TAR_SUR_INTERCEPTOR_L12, //!< [СУР-А009] Положение секции I и II левых интерцепторов
   UKS_TAR_SUR_INTERCEPTOR_L34, //!< [СУР-А010] Положение секции III и IV левых интерцепторов
   UKS_TAR_SUR_INTERCEPTOR_L56, //!< [СУР-А011] Положение секции V и VI левых интерцепторов
   UKS_TAR_PARAMETERS_COUNT     //!< Количество тарируемых параметров УКС
} uks_tar_parameter_t;

//! Команда для ФПО БП-504/506 от МФЦИ
typedef enum iupk_aur_command_t {
   MFCI_AUR_CMD_ISP,  //!< Нажатие "ИСП" на обрамлении МФЦИ на странице 2 кадра СУО-504/506
   MFCI_AUR_CMD_TRK,  //!< Нажатие "ТРК" на обрамлении МФЦИ на странице 2 кадра СУО-504/506
   MFCI_AUR_CMD_RASCH //!< Нажатие "РАСЧ" на обрамлении МФЦИ на странице 3 кадра СУО-504/506
} iupk_aur_command_t;

#ifndef SUO_VARIANTS
#define SUO_VARIANTS
//! Вариант подвеса СУО
typedef enum suo_variant_t {
   SUO_VARIANT_UNDEF, //!< Вариант подвеса СУО не определен
   SUO_VARIANT_132,   //!< Вариант подвеса СУО - Изделие 132
   SUO_VARIANT_K029,  //!< Вариант подвеса СУО - К029
   SUO_VARIANT_NASP,  //!< Вариант подвеса СУО - НАСП
   SUO_VARIANT_50X,   //!< Вариант подвеса СУО - Изделие типов 5040/506
   SUO_VARIANTS_COUNT //!< Количество вариантов подвеса СУО
} suo_variant_t;
#endif

//! Идентификатор подадреса данных кадра СУО-504/506
typedef enum mfci_in_suo_50x_sa_type_t {
   MFCI_IN_SUO_50X_SA_PATH = 1,         //!< Подадрес с данными исполняемой траектории
   MFCI_IN_SUO_50X_SA_PROPOSED_PATH,    //!< Подадрес с данными предлагаемой траектории
   MFCI_IN_SUO_50X_SA_TRK_AP,           //!< Подадрес с данными траектории в режиме автономного полета
   MFCI_IN_SUO_50X_SA_RVP_INIT,         //!< Подадрес с данными инициализации РВП
   MFCI_IN_SUO_50X_SA_RVP_POINTS,       //!< Подадрес с данными точек РВП
   MFCI_IN_SUO_50X_SA_RVP_POLYGONS,     //!< Подадрес с данными описаний полигонов РВП
   MFCI_IN_SUO_50X_SA_OSP_OUTER_POINTS, //!< Подадрес с данными точек контура ОСП ОСП
   MFCI_IN_SUO_50X_SA_OSP_INNER_POINTS, //!< Подадрес с данными точек рубежа начала пусков ОСП
   MFCI_IN_SUO_50X_SA_AREAS_POINTS,     //!< Подадрес с данными точек запретных и опасных зон
   MFCI_IN_SUO_50X_SA_AREAS,            //!< Подадрес с данными описаний полигонов запретных и опасных зон
   MFCI_IN_SUO_50X_SA_PAGE_3_INIT,      //!< Подадрес с данными инциализации страницы 3 кадра СУО-504/506
   MFCI_IN_SUO_50X_SA_TYPES_COUNT       //!< Количество вариантов подадресов данных кадра СУО-504/506
} mfci_in_suo_50x_sa_type_t;

//! Cлово с двумя текстовыми символами
typedef struct mfci_text_word_b_t {
   uint16_t symbol_1 : 8; //!< Символ 1 (кодировка Win-1251) //(min:0 max:255)
   uint16_t symbol_2 : 8; //!< Символ 2 (кодировка Win-1251) //(min:0 max:255)
} mfci_text_word_b_t;

//! Слово 1-2 c кадрами МФЦИ
typedef struct mfci_formats_word_1_b_t {
   uint32_t format_1   : 6; //!< Кадр МФЦИ 1 (mfci_format_t) //(min:0 max:33)
   uint32_t format_2   : 6; //!< Кадр МФЦИ 2 (mfci_format_t) //(min:0 max:33)
   uint32_t format_3_1 : 6; //!< Левый кадр МФЦИ 3 (mfci_format_t) //(min:0 max:33)
   uint32_t format_3_2 : 6; //!< Правый кадр МФЦИ 3 (mfci_format_t) //(min:0 max:33)
   uint32_t format_4   : 6; //!< Кадр МФЦИ 4 (mfci_format_t) //(min:0 max:33)
   uint32_t            : 2; //!< Резерв
} mfci_formats_word_1_b_t;

//! Слово 3-4 c кадрами МФЦИ
typedef struct mfci_formats_word_2_b_t {
   uint32_t format_5   : 6; //!< Кадр МФЦИ 5 (mfci_format_t) //(min:0 max:33)
   uint32_t format_6_1 : 6; //!< Левый кадр МФЦИ 6 (mfci_format_t) //(min:0 max:33)
   uint32_t format_6_2 : 6; //!< Правый кадр МФЦИ 6 (mfci_format_t) //(min:0 max:33)
   uint32_t format_7   : 6; //!< Кадр МФЦИ 7 (mfci_format_t) //(min:0 max:33)
   uint32_t format_8   : 6; //!< Кадр МФЦИ 8 (mfci_format_t) //(min:0 max:33)
   uint32_t            : 2; //!< Резерв
} mfci_formats_word_2_b_t;

//! Слово 5-6 c кадрами МФЦИ
typedef struct mfci_formats_word_3_b_t {
   uint32_t format_9    : 6; //!< Кадр МФЦИ 9 (mfci_format_t) //(min:0 max:33)
   uint32_t format_10_1 : 6; //!< Левый кадр МФЦИ 10 (mfci_format_t) //(min:0 max:33)
   uint32_t format_10_2 : 6; //!< Правый кадр МФЦИ 10 (mfci_format_t) //(min:0 max:33)
   uint32_t format_11   : 6; //!< Кадр МФЦИ 11 (mfci_format_t) //(min:0 max:33)
   uint32_t             : 8; //!< Резерв
} mfci_formats_word_3_b_t;

//! Слово даты
typedef struct mfci_date_b_t {
   uint16_t day  : 5; //!< День //(min:1 max:31)
   uint16_t month: 4; //!< Месяц //(min:1 max:12)
   uint16_t year : 7; //!< Год (две последние цифры) //(min:0 max:99)
} mfci_date_b_t;

//! Старшее слово времени
typedef struct mfci_time_high_b_t {
   uint16_t hour   : 5; //!< Час //(min:0 max:23)
   uint16_t minute : 6; //!< Минута //(min:0 max:59)
   uint16_t        : 5; //!< Резерв
} mfci_time_high_b_t;

//! Младшее слово времени
typedef struct mfci_time_low_b_t {
   uint16_t second : 6;  //!< Секунда //(min:0 max:59)
   uint16_t        : 10; //!< Резерв
} mfci_time_low_b_t;

//! Слово версии
typedef struct mfci_version_b_t {
   uint16_t version    : 8; //!< Номер версии //(min:1 max:99)
   uint16_t subversion : 8; //!< Номер подверсии //(min:1 max:99)
} mfci_version_b_t;

//! Слово 1 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_1_b_t {
   uint16_t dv1_turb_overheating : 1; //!< [ДВ1-Д007] ДВ1 ОПОРА ПЕРЕГРЕВ (ДВ/С)
   uint16_t dv2_turb_overheating : 1; //!< [ДВ2-Д007] ДВ2 ОПОРА ПЕРЕГРЕВ (ДВ/С)
   uint16_t dv3_turb_overheating : 1; //!< [ДВ3-Д007] ДВ3 ОПОРА ПЕРЕГРЕВ (ДВ/С)
   uint16_t dv4_turb_overheating : 1; //!< [ДВ4-Д007] ДВ4 ОПОРА ПЕРЕГРЕВ (ДВ/С)
   uint16_t dv1_cooling_failure  : 1; //!< [ДВ1-Д008] ДВ1 ОХЛАЖД ОТКАЗ (ДВ/С)
   uint16_t dv2_cooling_failure  : 1; //!< [ДВ2-Д008] ДВ2 ОХЛАЖД ОТКАЗ (ДВ/С)
   uint16_t dv3_cooling_failure  : 1; //!< [ДВ3-Д008] ДВ3 ОХЛАЖД ОТКАЗ (ДВ/С)
   uint16_t dv4_cooling_failure  : 1; //!< [ДВ4-Д008] ДВ4 ОХЛАЖД ОТКАЗ (ДВ/С)
   uint16_t dv1_swarf            : 1; //!< [ДВ1-Д015] ДВ1 СТРУЖКА В МАСЛЕ (ДВ/С)
   uint16_t dv2_swarf            : 1; //!< [ДВ2-Д015] ДВ2 СТРУЖКА В МАСЛЕ (ДВ/С)
   uint16_t dv3_swarf            : 1; //!< [ДВ3-Д015] ДВ3 СТРУЖКА В МАСЛЕ (ДВ/С)
   uint16_t dv4_swarf            : 1; //!< [ДВ4-Д015] ДВ4 СТРУЖКА В МАСЛЕ (ДВ/С)
   uint16_t dv1_oil_low          : 1; //!< [ДВ1-Д017] ДВ1 МАСЛА МАЛО (ДВ/С)
   uint16_t dv2_oil_low          : 1; //!< [ДВ2-Д017] ДВ2 МАСЛА МАЛО (ДВ/С)
   uint16_t dv3_oil_low          : 1; //!< [ДВ3-Д017] ДВ3 МАСЛА МАЛО (ДВ/С)
   uint16_t dv4_oil_low          : 1; //!< [ДВ4-Д017] ДВ4 МАСЛА МАЛО (ДВ/С)
} mfci_signals_word_1_b_t;

//! Слово 2 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_2_b_t {
   uint16_t dv1_oil_high            : 1; //!< [ДВ1-Д018] ДВ1 МАСЛА МНОГО (ДВ/С)
   uint16_t dv2_oil_high            : 1; //!< [ДВ2-Д018] ДВ2 МАСЛА МНОГО (ДВ/С)
   uint16_t dv3_oil_high            : 1; //!< [ДВ3-Д018] ДВ3 МАСЛА МНОГО (ДВ/С)
   uint16_t dv4_oil_high            : 1; //!< [ДВ4-Д018] ДВ4 МАСЛА МНОГО (ДВ/С)
   uint16_t dv1_oil_pressure_in_low : 1; //!< [ДВ1-Д019] ДВ1 ДАВЛ МАСЛА МАЛО (ДВ/С)
   uint16_t dv2_oil_pressure_in_low : 1; //!< [ДВ2-Д019] ДВ2 ДАВЛ МАСЛА МАЛО (ДВ/С)
   uint16_t dv3_oil_pressure_in_low : 1; //!< [ДВ3-Д019] ДВ3 ДАВЛ МАСЛА МАЛО (ДВ/С)
   uint16_t dv4_oil_pressure_in_low : 1; //!< [ДВ4-Д019] ДВ4 ДАВЛ МАСЛА МАЛО (ДВ/С)
   uint16_t dv1_surge               : 1; //!< [ДВ1-Д020] ДВ1 ПОМПАЖ (ДВ/С)
   uint16_t dv2_surge               : 1; //!< [ДВ2-Д020] ДВ2 ПОМПАЖ (ДВ/С)
   uint16_t dv3_surge               : 1; //!< [ДВ3-Д020] ДВ3 ПОМПАЖ (ДВ/С)
   uint16_t dv4_surge               : 1; //!< [ДВ4-Д020] ДВ4 ПОМПАЖ (ДВ/С)
   uint16_t dv1_fuel_pressure_low   : 1; //!< [ДВ1-Д021] ДВ1 ДАВЛ ТОПЛ МАЛО (ДВ/С)
   uint16_t dv2_fuel_pressure_low   : 1; //!< [ДВ2-Д021] ДВ2 ДАВЛ ТОПЛ МАЛО (ДВ/С)
   uint16_t dv3_fuel_pressure_low   : 1; //!< [ДВ3-Д021] ДВ3 ДАВЛ ТОПЛ МАЛО (ДВ/С)
   uint16_t dv4_fuel_pressure_low   : 1; //!< [ДВ4-Д021] ДВ4 ДАВЛ ТОПЛ МАЛО (ДВ/С)
} mfci_signals_word_2_b_t;

//! Слово 3 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_3_b_t {
   uint16_t dv1_esud_healthy   : 1; //!< [ДВ1-Д023] ДВ1 ЭСУД ИСПРАВНА (ДВ/С)
   uint16_t dv2_esud_healthy   : 1; //!< [ДВ2-Д023] ДВ2 ЭСУД ИСПРАВНА (ДВ/С)
   uint16_t dv3_esud_healthy   : 1; //!< [ДВ3-Д023] ДВ3 ЭСУД ИСПРАВНА (ДВ/С)
   uint16_t dv4_esud_healthy   : 1; //!< [ДВ4-Д023] ДВ4 ЭСУД ИСПРАВНА (ДВ/С)
   uint16_t dv1_clogging       : 1; //!< [ДВ1-Д028] ДВ1 ТОПЛ ФИЛЬТР ЗАСОРЕН (ДВ/С)
   uint16_t dv2_clogging       : 1; //!< [ДВ2-Д028] ДВ2 ТОПЛ ФИЛЬТР ЗАСОРЕН (ДВ/С)
   uint16_t dv3_clogging       : 1; //!< [ДВ3-Д028] ДВ3 ТОПЛ ФИЛЬТР ЗАСОРЕН (ДВ/С)
   uint16_t dv4_clogging       : 1; //!< [ДВ4-Д028] ДВ4 ТОПЛ ФИЛЬТР ЗАСОРЕН (ДВ/С)
   uint16_t dv1_oil_temp_high  : 1; //!< [ДВ1-Д029] ДВ1 ТЕМПЕР МАСЛА ВХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv2_oil_temp_high  : 1; //!< [ДВ2-Д029] ДВ2 ТЕМПЕР МАСЛА ВХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv3_oil_temp_high  : 1; //!< [ДВ3-Д029] ДВ3 ТЕМПЕР МАСЛА ВХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv4_oil_temp_high  : 1; //!< [ДВ4-Д029] ДВ4 ТЕМПЕР МАСЛА ВХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv1_vibration_high : 1; //!< [ДВ1-Д030] ДВ1 ВИБР ОПАСНАЯ (ДВ/С)
   uint16_t dv2_vibration_high : 1; //!< [ДВ2-Д030] ДВ2 ВИБР ОПАСНАЯ (ДВ/С)
   uint16_t dv3_vibration_high : 1; //!< [ДВ3-Д030] ДВ3 ВИБР ОПАСНАЯ (ДВ/С)
   uint16_t dv4_vibration_high : 1; //!< [ДВ4-Д030] ДВ4 ВИБР ОПАСНАЯ (ДВ/С)
} mfci_signals_word_3_b_t;

//! Слово 4 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_4_b_t {
   uint16_t dv1_vna_failure              : 1; //!< [ДВ1-Д031] ДВ1 ОБОГРЕВ ВНА ОТКАЗ (ДВ/С)
   uint16_t dv2_vna_failure              : 1; //!< [ДВ2-Д031] ДВ2 ОБОГРЕВ ВНА ОТКАЗ (ДВ/С)
   uint16_t dv3_vna_failure              : 1; //!< [ДВ3-Д031] ДВ3 ОБОГРЕВ ВНА ОТКАЗ (ДВ/С)
   uint16_t dv4_vna_failure              : 1; //!< [ДВ4-Д031] ДВ4 ОБОГРЕВ ВНА ОТКАЗ (ДВ/С)
   uint16_t dv1_bearing_temperature_high : 1; //!< [ДВ1-Д032] ДВ1 ТЕМПЕР ПОДШ ВЕЛИКА (ДВ/С)
   uint16_t dv2_bearing_temperature_high : 1; //!< [ДВ2-Д032] ДВ2 ТЕМПЕР ПОДШ ВЕЛИКА (ДВ/С)
   uint16_t dv3_bearing_temperature_high : 1; //!< [ДВ3-Д032] ДВ3 ТЕМПЕР ПОДШ ВЕЛИКА (ДВ/С)
   uint16_t dv4_bearing_temperature_high : 1; //!< [ДВ4-Д032] ДВ4 ТЕМПЕР ПОДШ ВЕЛИКА (ДВ/С)
   uint16_t dv1_no_correction            : 1; //!< [ДВ1-Д033] ДВ1 НЕТ КОРРЕКЦИИ ОТ (ДВ/С)
   uint16_t dv2_no_correction            : 1; //!< [ДВ2-Д033] ДВ2 НЕТ КОРРЕКЦИИ ОТ (ДВ/С)
   uint16_t dv3_no_correction            : 1; //!< [ДВ3-Д033] ДВ3 НЕТ КОРРЕКЦИИ ОТ (ДВ/С)
   uint16_t dv4_no_correction            : 1; //!< [ДВ4-Д033] ДВ4 НЕТ КОРРЕКЦИИ ОТ (ДВ/С)
   uint16_t dv1_intake_healthy           : 1; //!< [ДВ1-Д034] ДВ1 АУ ВЗ ИСПРАВНА (ДВ/С)
   uint16_t dv2_intake_healthy           : 1; //!< [ДВ2-Д034] ДВ2 АУ ВЗ ИСПРАВНА (ДВ/С)
   uint16_t dv3_intake_healthy           : 1; //!< [ДВ3-Д034] ДВ3 АУ ВЗ ИСПРАВНА (ДВ/С)
   uint16_t dv4_intake_healthy           : 1; //!< [ДВ4-Д034] ДВ4 АУ ВЗ ИСПРАВНА (ДВ/С)
} mfci_signals_word_4_b_t;

//! Слово 5 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_5_b_t {
   uint16_t dv1_intake_test           : 1; //!< [ДВ1-Д035] ДВ1 АУ ВЗ КОНТРОЛЬ (ДВ/С)
   uint16_t dv2_intake_test           : 1; //!< [ДВ2-Д035] ДВ2 АУ ВЗ КОНТРОЛЬ (ДВ/С)
   uint16_t dv3_intake_test           : 1; //!< [ДВ3-Д035] ДВ3 АУ ВЗ КОНТРОЛЬ (ДВ/С)
   uint16_t dv4_intake_test           : 1; //!< [ДВ4-Д035] ДВ4 АУ ВЗ КОНТРОЛЬ (ДВ/С)
   uint16_t dv1_throttle_afterburning : 1; //!< [ДВ1-Д036] ДВ1 ДРОССЕЛИР С ФОРСАЖЕМ (ДВ/С)
   uint16_t dv2_throttle_afterburning : 1; //!< [ДВ2-Д036] ДВ2 ДРОССЕЛИР С ФОРСАЖЕМ (ДВ/С)
   uint16_t dv3_throttle_afterburning : 1; //!< [ДВ3-Д036] ДВ3 ДРОССЕЛИР С ФОРСАЖЕМ (ДВ/С)
   uint16_t dv4_throttle_afterburning : 1; //!< [ДВ4-Д036] ДВ4 ДРОССЕЛИР С ФОРСАЖЕМ (ДВ/С)
   uint16_t dv1_turn_off              : 1; //!< [ДВ1-Д037] ДВ1 ВЫКЛЮЧИ (ДВ/С)
   uint16_t dv2_turn_off              : 1; //!< [ДВ2-Д037] ДВ2 ВЫКЛЮЧИ (ДВ/С)
   uint16_t dv3_turn_off              : 1; //!< [ДВ3-Д037] ДВ3 ВЫКЛЮЧИ (ДВ/С)
   uint16_t dv4_turn_off              : 1; //!< [ДВ4-Д037] ДВ4 ВЫКЛЮЧИ (ДВ/С)
   uint16_t dv1_intake_failure        : 1; //!< [ДВ1-Д039] ДВ1 АУ ВЗ НЕИСПР (ДВ/С)
   uint16_t dv2_intake_failure        : 1; //!< [ДВ2-Д039] ДВ2 АУ ВЗ НЕИСПР (ДВ/С)
   uint16_t dv3_intake_failure        : 1; //!< [ДВ3-Д039] ДВ3 АУ ВЗ НЕИСПР (ДВ/С)
   uint16_t dv4_intake_failure        : 1; //!< [ДВ4-Д039] ДВ4 АУ ВЗ НЕИСПР (ДВ/С)
} mfci_signals_word_5_b_t;

//! Слово 6 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_6_b_t {
   uint16_t dv1_wedge_failure            : 1; //!< [ДВ1-Д040] ДВ1 АУ КЛИНОМ ОТКАЗ (ДВ/С)
   uint16_t dv2_wedge_failure            : 1; //!< [ДВ2-Д040] ДВ2 АУ КЛИНОМ ОТКАЗ (ДВ/С)
   uint16_t dv3_wedge_failure            : 1; //!< [ДВ3-Д040] ДВ3 АУ КЛИНОМ ОТКАЗ (ДВ/С)
   uint16_t dv4_wedge_failure            : 1; //!< [ДВ4-Д040] ДВ4 АУ КЛИНОМ ОТКАЗ (ДВ/С)
   uint16_t dv1_valve_failure            : 1; //!< [ДВ1-Д041] ДВ1 АУ СТВОРОК ОТКАЗ (ДВ/С)
   uint16_t dv2_valve_failure            : 1; //!< [ДВ2-Д041] ДВ2 АУ СТВОРОК ОТКАЗ (ДВ/С)
   uint16_t dv3_valve_failure            : 1; //!< [ДВ3-Д041] ДВ3 АУ СТВОРОК ОТКАЗ (ДВ/С)
   uint16_t dv4_valve_failure            : 1; //!< [ДВ4-Д041] ДВ4 АУ СТВОРОК ОТКАЗ (ДВ/С)
   uint16_t dv1_n_sd_high                : 1; //!< [ДВ1-Д042] ДВ1 ОБОРОТЫ СД ОПАСНЫЕ (ДВ/С)
   uint16_t dv2_n_sd_high                : 1; //!< [ДВ2-Д042] ДВ2 ОБОРОТЫ СД ОПАСНЫЕ (ДВ/С)
   uint16_t dv3_n_sd_high                : 1; //!< [ДВ3-Д042] ДВ3 ОБОРОТЫ СД ОПАСНЫЕ (ДВ/С)
   uint16_t dv4_n_sd_high                : 1; //!< [ДВ4-Д042] ДВ4 ОБОРОТЫ СД ОПАСНЫЕ (ДВ/С)
   uint16_t dv1_oil_temperature_out_high : 1; //!< [ДВ1-Д044] ДВ1 ТЕМПЕР МАСЛА ВЫХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv2_oil_temperature_out_high : 1; //!< [ДВ2-Д044] ДВ2 ТЕМПЕР МАСЛА ВЫХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv3_oil_temperature_out_high : 1; //!< [ДВ3-Д044] ДВ3 ТЕМПЕР МАСЛА ВЫХОДА ВЕЛИКА (ДВ/С)
   uint16_t dv4_oil_temperature_out_high : 1; //!< [ДВ4-Д044] ДВ4 ТЕМПЕР МАСЛА ВЫХОДА ВЕЛИКА (ДВ/С)
} mfci_signals_word_6_b_t;

//! Слово 7 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_7_b_t {
   uint16_t dv1_no_afterburning       : 1; //!< [ДВ1-Д045] ДВ1 НЕТ ФОРСАЖА/ ПОВТОРИ ФОРСАЖ (ДВ/С)
   uint16_t dv2_no_afterburning       : 1; //!< [ДВ2-Д045] ДВ2 НЕТ ФОРСАЖА/ ПОВТОРИ ФОРСАЖ (ДВ/С)
   uint16_t dv3_no_afterburning       : 1; //!< [ДВ3-Д045] ДВ3 НЕТ ФОРСАЖА/ ПОВТОРИ ФОРСАЖ (ДВ/С)
   uint16_t dv4_no_afterburning       : 1; //!< [ДВ4-Д045] ДВ4 НЕТ ФОРСАЖА/ ПОВТОРИ ФОРСАЖ (ДВ/С)
   uint16_t dv1_oil_pressure_gp22_low : 1; //!< [ДВ1-Д046] ДВ1 ДАВЛ МАСЛА ГП МАЛО (ДВ/С)
   uint16_t dv2_oil_pressure_gp22_low : 1; //!< [ДВ2-Д046] ДВ2 ДАВЛ МАСЛА ГП МАЛО (ДВ/С)
   uint16_t dv3_oil_pressure_gp22_low : 1; //!< [ДВ3-Д046] ДВ3 ДАВЛ МАСЛА ГП МАЛО (ДВ/С)
   uint16_t dv4_oil_pressure_gp22_low : 1; //!< [ДВ4-Д046] ДВ4 ДАВЛ МАСЛА ГП МАЛО (ДВ/С)
   uint16_t dv1_hydraulic_lock        : 1; //!< [ДВ1-Д047] ДВ1 ГИДРОУПОР ВКЛЮЧЕН (ДВ/С)
   uint16_t dv2_hydraulic_lock        : 1; //!< [ДВ2-Д047] ДВ2 ГИДРОУПОР ВКЛЮЧЕН (ДВ/С)
   uint16_t dv3_hydraulic_lock        : 1; //!< [ДВ3-Д047] ДВ3 ГИДРОУПОР ВКЛЮЧЕН (ДВ/С)
   uint16_t dv4_hydraulic_lock        : 1; //!< [ДВ4-Д047] ДВ4 ГИДРОУПОР ВКЛЮЧЕН (ДВ/С)
   uint16_t dv1_oil_pressure_gsbk_low : 1; //!< [ДВ1-Д049] ДВ1 ДАВЛ МАСЛА ГСБК МАЛО (ДВ/С)
   uint16_t dv2_oil_pressure_gsbk_low : 1; //!< [ДВ2-Д049] ДВ2 ДАВЛ МАСЛА ГСБК МАЛО (ДВ/С)
   uint16_t dv3_oil_pressure_gsbk_low : 1; //!< [ДВ3-Д049] ДВ3 ДАВЛ МАСЛА ГСБК МАЛО (ДВ/С)
   uint16_t dv4_oil_pressure_gsbk_low : 1; //!< [ДВ4-Д049] ДВ4 ДАВЛ МАСЛА ГСБК МАЛО (ДВ/С)
} mfci_signals_word_7_b_t;

//! Слово 8 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_8_b_t {
   uint16_t dv1_fuel_temperature_tmt_high : 1; //!< [ДВ1-Д055] ДВ1 ТЕМПЕР ТОПЛ ВЕЛИКА (ДВ/С)
   uint16_t dv2_fuel_temperature_tmt_high : 1; //!< [ДВ2-Д055] ДВ2 ТЕМПЕР ТОПЛ ВЕЛИКА (ДВ/С)
   uint16_t dv3_fuel_temperature_tmt_high : 1; //!< [ДВ3-Д055] ДВ3 ТЕМПЕР ТОПЛ ВЕЛИКА (ДВ/С)
   uint16_t dv4_fuel_temperature_tmt_high : 1; //!< [ДВ4-Д055] ДВ4 ТЕМПЕР ТОПЛ ВЕЛИКА (ДВ/С)
   uint16_t dv1_starter_high              : 1; //!< [ДВ1-Д056] ДВ1 ОБОРОТЫ СТАРТЕРА ОПАСНЫЕ (ДВ/С)
   uint16_t dv2_starter_high              : 1; //!< [ДВ2-Д056] ДВ2 ОБОРОТЫ СТАРТЕРА ОПАСНЫЕ (ДВ/С)
   uint16_t dv3_starter_high              : 1; //!< [ДВ3-Д056] ДВ3 ОБОРОТЫ СТАРТЕРА ОПАСНЫЕ (ДВ/С)
   uint16_t dv4_starter_high              : 1; //!< [ДВ4-Д056] ДВ4 ОБОРОТЫ СТАРТЕРА ОПАСНЫЕ (ДВ/С)
   uint16_t dv1_vpt_pressure_low          : 1; //!< [ДВ1-Д057] ДВ1 ДАВЛ ВПТ МАЛО (ДВ/С)
   uint16_t dv2_vpt_pressure_low          : 1; //!< [ДВ2-Д057] ДВ2 ДАВЛ ВПТ МАЛО (ДВ/С)
   uint16_t dv3_vpt_pressure_low          : 1; //!< [ДВ3-Д057] ДВ3 ДАВЛ ВПТ МАЛО (ДВ/С)
   uint16_t dv4_vpt_pressure_low          : 1; //!< [ДВ4-Д057] ДВ4 ДАВЛ ВПТ МАЛО (ДВ/С)
   uint16_t dv1_breather_pressure_high    : 1; //!< [ДВ1-Д058] ДВ1 ДАВЛ СУФЛИР ПОВЫШЕН (ДВ/С)
   uint16_t dv2_breather_pressure_high    : 1; //!< [ДВ2-Д058] ДВ2 ДАВЛ СУФЛИР ПОВЫШЕН (ДВ/С)
   uint16_t dv3_breather_pressure_high    : 1; //!< [ДВ3-Д058] ДВ3 ДАВЛ СУФЛИР ПОВЫШЕН (ДВ/С)
   uint16_t dv4_breather_pressure_high    : 1; //!< [ДВ4-Д058] ДВ4 ДАВЛ СУФЛИР ПОВЫШЕН (ДВ/С)
} mfci_signals_word_8_b_t;

//! Слово 9 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_9_b_t {
   uint16_t dv1_start_failure_on_land    : 1; //!< [ДВ1-Д061] ДВ1 ЭСУД НЕИСПР (ЗАП ЗЕМ ОТКАЗ, СОСТ)
   uint16_t dv2_start_failure_on_land    : 1; //!< [ДВ2-Д061] ДВ2 ЭСУД НЕИСПР (ЗАП ЗЕМ ОТКАЗ, СОСТ)
   uint16_t dv3_start_failure_on_land    : 1; //!< [ДВ3-Д061] ДВ3 ЭСУД НЕИСПР (ЗАП ЗЕМ ОТКАЗ, СОСТ)
   uint16_t dv4_start_failure_on_land    : 1; //!< [ДВ4-Д061] ДВ4 ЭСУД НЕИСПР (ЗАП ЗЕМ ОТКАЗ, СОСТ)
   uint16_t dv1_start_failure_in_air     : 1; //!< [ДВ1-Д062] ДВ1 ЭСУД НЕИСПР (ЗАП ВОЗД ОТКАЗ, СОСТ)
   uint16_t dv2_start_failure_in_air     : 1; //!< [ДВ2-Д062] ДВ2 ЭСУД НЕИСПР (ЗАП ВОЗД ОТКАЗ, СОСТ)
   uint16_t dv3_start_failure_in_air     : 1; //!< [ДВ3-Д062] ДВ3 ЭСУД НЕИСПР (ЗАП ВОЗД ОТКАЗ, СОСТ)
   uint16_t dv4_start_failure_in_air     : 1; //!< [ДВ4-Д062] ДВ4 ЭСУД НЕИСПР (ЗАП ВОЗД ОТКАЗ, СОСТ)
   uint16_t dv1_gas_temp_control_failure : 1; //!< [ДВ1-Д063] ДВ1 ЭСУД НЕИСПР (ОГРАН ТГ ОТКАЗ, СОСТ)
   uint16_t dv2_gas_temp_control_failure : 1; //!< [ДВ2-Д063] ДВ2 ЭСУД НЕИСПР (ОГРАН ТГ ОТКАЗ, СОСТ)
   uint16_t dv3_gas_temp_control_failure : 1; //!< [ДВ3-Д063] ДВ3 ЭСУД НЕИСПР (ОГРАН ТГ ОТКАЗ, СОСТ)
   uint16_t dv4_gas_temp_control_failure : 1; //!< [ДВ4-Д063] ДВ4 ЭСУД НЕИСПР (ОГРАН ТГ ОТКАЗ, СОСТ)
   uint16_t dv1_n2_control_failure       : 1; //!< [ДВ1-Д064] ДВ1 ЭСУД НЕИСПР (ОГРАН ВД ОТКАЗ, СОСТ)
   uint16_t dv2_n2_control_failure       : 1; //!< [ДВ2-Д064] ДВ2 ЭСУД НЕИСПР (ОГРАН ВД ОТКАЗ, СОСТ)
   uint16_t dv3_n2_control_failure       : 1; //!< [ДВ3-Д064] ДВ3 ЭСУД НЕИСПР (ОГРАН ВД ОТКАЗ, СОСТ)
   uint16_t dv4_n2_control_failure       : 1; //!< [ДВ4-Д064] ДВ4 ЭСУД НЕИСПР (ОГРАН ВД ОТКАЗ, СОСТ)
} mfci_signals_word_9_b_t;

//! Слово 10 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_10_b_t {
   uint16_t dv1_n1_control_failure           : 1; //!< [ДВ1-Д065] ДВ1 ЭСУД НЕИСПР (УПРАВЛ НД ОТКАЗ, СОСТ)
   uint16_t dv2_n1_control_failure           : 1; //!< [ДВ2-Д065] ДВ2 ЭСУД НЕИСПР (УПРАВЛ НД ОТКАЗ, СОСТ)
   uint16_t dv3_n1_control_failure           : 1; //!< [ДВ3-Д065] ДВ3 ЭСУД НЕИСПР (УПРАВЛ НД ОТКАЗ, СОСТ)
   uint16_t dv4_n1_control_failure           : 1; //!< [ДВ4-Д065] ДВ4 ЭСУД НЕИСПР (УПРАВЛ НД ОТКАЗ, СОСТ)
   uint16_t dv1_afterburning_control_failure : 1; //!< [ДВ1-Д066] ДВ1 ЭСУД НЕИСПР (УПР ФОРСАЖЕМ ОТКАЗ, СОСТ)
   uint16_t dv2_afterburning_control_failure : 1; //!< [ДВ2-Д066] ДВ2 ЭСУД НЕИСПР (УПР ФОРСАЖЕМ ОТКАЗ, СОСТ)
   uint16_t dv3_afterburning_control_failure : 1; //!< [ДВ3-Д066] ДВ3 ЭСУД НЕИСПР (УПР ФОРСАЖЕМ ОТКАЗ, СОСТ)
   uint16_t dv4_afterburning_control_failure : 1; //!< [ДВ4-Д066] ДВ4 ЭСУД НЕИСПР (УПР ФОРСАЖЕМ ОТКАЗ, СОСТ)
   uint16_t dv1_antisurge_control_failure    : 1; //!< [ДВ1-Д067] ДВ1 ЭСУД НЕИСПР (ППЗ ОТКАЗ, СОСТ)
   uint16_t dv2_antisurge_control_failure    : 1; //!< [ДВ2-Д067] ДВ2 ЭСУД НЕИСПР (ППЗ ОТКАЗ, СОСТ)
   uint16_t dv3_antisurge_control_failure    : 1; //!< [ДВ3-Д067] ДВ3 ЭСУД НЕИСПР (ППЗ ОТКАЗ, СОСТ)
   uint16_t dv4_antisurge_control_failure    : 1; //!< [ДВ4-Д067] ДВ4 ЭСУД НЕИСПР (ППЗ ОТКАЗ, СОСТ)
   uint16_t dv1_cooling_control_failure      : 1; //!< [ДВ1-Д068] ДВ1 УПР ОХЛ ТУРБИНЫ ОТКАЗ (СОСТ)
   uint16_t dv2_cooling_control_failure      : 1; //!< [ДВ2-Д068] ДВ2 УПР ОХЛ ТУРБИНЫ ОТКАЗ (СОСТ)
   uint16_t dv3_cooling_control_failure      : 1; //!< [ДВ3-Д068] ДВ3 УПР ОХЛ ТУРБИНЫ ОТКАЗ (СОСТ)
   uint16_t dv4_cooling_control_failure      : 1; //!< [ДВ4-Д068] ДВ4 УПР ОХЛ ТУРБИНЫ ОТКАЗ (СОСТ)
} mfci_signals_word_10_b_t;

//! Слово 11 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_11_b_t {
   uint16_t dv1_lock_control_failure       : 1; //!< [ДВ1-Д069] ДВ1 ЭСУД НЕИСПР (УПР ГИДРОУПОР ОТКАЗ, СОСТ)
   uint16_t dv2_lock_control_failure       : 1; //!< [ДВ2-Д069] ДВ2 ЭСУД НЕИСПР (УПР ГИДРОУПОР ОТКАЗ, СОСТ)
   uint16_t dv3_lock_control_failure       : 1; //!< [ДВ3-Д069] ДВ3 ЭСУД НЕИСПР (УПР ГИДРОУПОР ОТКАЗ, СОСТ)
   uint16_t dv4_lock_control_failure       : 1; //!< [ДВ4-Д069] ДВ4 ЭСУД НЕИСПР (УПР ГИДРОУПОР ОТКАЗ, СОСТ)
   uint16_t dv1_kpv_control_failure        : 1; //!< [ДВ1-Д070] ДВ1 УПР КПВ СД ОТКАЗ (СОСТ)
   uint16_t dv2_kpv_control_failure        : 1; //!< [ДВ2-Д070] ДВ2 УПР КПВ СД ОТКАЗ (СОСТ)
   uint16_t dv3_kpv_control_failure        : 1; //!< [ДВ3-Д070] ДВ3 УПР КПВ СД ОТКАЗ (СОСТ)
   uint16_t dv4_kpv_control_failure        : 1; //!< [ДВ4-Д070] ДВ4 УПР КПВ СД ОТКАЗ (СОСТ)
   uint16_t dv1_nozzle_control_failure     : 1; //!< [ДВ1-Д071] ДВ1 ЭСУД НЕИСПР (УПР СОПЛОМ ОТКАЗ, СОСТ)
   uint16_t dv2_nozzle_control_failure     : 1; //!< [ДВ2-Д071] ДВ2 ЭСУД НЕИСПР (УПР СОПЛОМ ОТКАЗ, СОСТ)
   uint16_t dv3_nozzle_control_failure     : 1; //!< [ДВ3-Д071] ДВ3 ЭСУД НЕИСПР (УПР СОПЛОМ ОТКАЗ, СОСТ)
   uint16_t dv4_nozzle_control_failure     : 1; //!< [ДВ4-Д071] ДВ4 ЭСУД НЕИСПР (УПР СОПЛОМ ОТКАЗ, СОСТ)
   uint16_t dv1_start_failed_main_switcher : 1; //!< [ДВ1-Д072] ДВ1 ЗАПУСК ПРЕКРАЩЕН (НЕТ ГЛАВНЫЙ ВЫКЛ, ДВ/С)
   uint16_t dv2_start_failed_main_switcher : 1; //!< [ДВ2-Д072] ДВ2 ЗАПУСК ПРЕКРАЩЕН (НЕТ ГЛАВНЫЙ ВЫКЛ, ДВ/С)
   uint16_t dv3_start_failed_main_switcher : 1; //!< [ДВ3-Д072] ДВ3 ЗАПУСК ПРЕКРАЩЕН (НЕТ ГЛАВНЫЙ ВЫКЛ, ДВ/С)
   uint16_t dv4_start_failed_main_switcher : 1; //!< [ДВ4-Д072] ДВ4 ЗАПУСК ПРЕКРАЩЕН (НЕТ ГЛАВНЫЙ ВЫКЛ, ДВ/С)
} mfci_signals_word_11_b_t;

//! Слово 12 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_12_b_t {
   uint16_t dv1_start_failed_starter       : 1; //!< [ДВ1-Д073] ДВ1 ЗАПУСК ПРЕКРАЩЕН (ОБОРОТЫ СТАРТЕРА ПРЕДЕЛ, ДВ/С)
   uint16_t dv2_start_failed_starter       : 1; //!< [ДВ2-Д073] ДВ2 ЗАПУСК ПРЕКРАЩЕН (ОБОРОТЫ СТАРТЕРА ПРЕДЕЛ, ДВ/С)
   uint16_t dv3_start_failed_starter       : 1; //!< [ДВ3-Д073] ДВ3 ЗАПУСК ПРЕКРАЩЕН (ОБОРОТЫ СТАРТЕРА ПРЕДЕЛ, ДВ/С)
   uint16_t dv4_start_failed_starter       : 1; //!< [ДВ4-Д073] ДВ4 ЗАПУСК ПРЕКРАЩЕН (ОБОРОТЫ СТАРТЕРА ПРЕДЕЛ, ДВ/С)
   uint16_t dv1_start_failed_stop_switcher : 1; //!< [ДВ1-Д074] ДВ1 ЗАПУСК ПРЕКРАЩЕН (СТОП-КРАН НЕ ОТКРЫТ, ДВ/С)
   uint16_t dv2_start_failed_stop_switcher : 1; //!< [ДВ2-Д074] ДВ2 ЗАПУСК ПРЕКРАЩЕН (СТОП-КРАН НЕ ОТКРЫТ, ДВ/С)
   uint16_t dv3_start_failed_stop_switcher : 1; //!< [ДВ3-Д074] ДВ3 ЗАПУСК ПРЕКРАЩЕН (СТОП-КРАН НЕ ОТКРЫТ, ДВ/С)
   uint16_t dv4_start_failed_stop_switcher : 1; //!< [ДВ4-Д074] ДВ4 ЗАПУСК ПРЕКРАЩЕН (СТОП-КРАН НЕ ОТКРЫТ, ДВ/С)
   uint16_t dv1_start_failed_kpv           : 1; //!< [ДВ1-Д075] ДВ1 ЗАПУСК ПРЕКРАЩЕН (КПВ ВД НЕ ОТКР, ДВ/С)
   uint16_t dv2_start_failed_kpv           : 1; //!< [ДВ2-Д075] ДВ2 ЗАПУСК ПРЕКРАЩЕН (КПВ ВД НЕ ОТКР, ДВ/С)
   uint16_t dv3_start_failed_kpv           : 1; //!< [ДВ3-Д075] ДВ3 ЗАПУСК ПРЕКРАЩЕН (КПВ ВД НЕ ОТКР, ДВ/С)
   uint16_t dv4_start_failed_kpv           : 1; //!< [ДВ4-Д075] ДВ4 ЗАПУСК ПРЕКРАЩЕН (КПВ ВД НЕ ОТКР, ДВ/С)
   uint16_t dv1_start_failed_supply_115    : 1; //!< [ДВ1-Д076] ДВ1 ЗАПУСК ПРЕКРАЩЕН (115В НЕ В НОРМЕ, ДВ/С)
   uint16_t dv2_start_failed_supply_115    : 1; //!< [ДВ2-Д076] ДВ2 ЗАПУСК ПРЕКРАЩЕН (115В НЕ В НОРМЕ, ДВ/С)
   uint16_t dv3_start_failed_supply_115    : 1; //!< [ДВ3-Д076] ДВ3 ЗАПУСК ПРЕКРАЩЕН (115В НЕ В НОРМЕ, ДВ/С)
   uint16_t dv4_start_failed_supply_115    : 1; //!< [ДВ4-Д076] ДВ4 ЗАПУСК ПРЕКРАЩЕН (115В НЕ В НОРМЕ, ДВ/С)
} mfci_signals_word_12_b_t;

//! Слово 13 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_13_b_t {
   uint16_t dv1_start_failed_control  : 1; //!< [ДВ1-Д077] ДВ1 ЗАПУСК ПРЕКРАЩЕН (ЭСУД ОТКАЗ, ДВ/С)
   uint16_t dv2_start_failed_control  : 1; //!< [ДВ2-Д077] ДВ2 ЗАПУСК ПРЕКРАЩЕН (ЭСУД ОТКАЗ, ДВ/С)
   uint16_t dv3_start_failed_control  : 1; //!< [ДВ3-Д077] ДВ3 ЗАПУСК ПРЕКРАЩЕН (ЭСУД ОТКАЗ, ДВ/С)
   uint16_t dv4_start_failed_control  : 1; //!< [ДВ4-Д077] ДВ4 ЗАПУСК ПРЕКРАЩЕН (ЭСУД ОТКАЗ, ДВ/С)
   uint16_t dv1_start_failed_spinup   : 1; //!< [ДВ1-Д078] ДВ1 ЗАПУСК ПРЕКРАЩЕН (НЕТ РАСКРУТКИ, ДВ/С)
   uint16_t dv2_start_failed_spinup   : 1; //!< [ДВ2-Д078] ДВ2 ЗАПУСК ПРЕКРАЩЕН (НЕТ РАСКРУТКИ, ДВ/С)
   uint16_t dv3_start_failed_spinup   : 1; //!< [ДВ3-Д078] ДВ3 ЗАПУСК ПРЕКРАЩЕН (НЕТ РАСКРУТКИ, ДВ/С)
   uint16_t dv4_start_failed_spinup   : 1; //!< [ДВ4-Д078] ДВ4 ЗАПУСК ПРЕКРАЩЕН (НЕТ РАСКРУТКИ, ДВ/С)
   uint16_t dv1_start_failed_gas_temp : 1; //!< [ДВ1-Д079] ДВ1 ЗАПУСК ПРЕКРАЩЕН (ТЕМПЕР ГАЗА ОПАСНАЯ, ДВ/С)
   uint16_t dv2_start_failed_gas_temp : 1; //!< [ДВ2-Д079] ДВ2 ЗАПУСК ПРЕКРАЩЕН (ТЕМПЕР ГАЗА ОПАСНАЯ, ДВ/С)
   uint16_t dv3_start_failed_gas_temp : 1; //!< [ДВ3-Д079] ДВ3 ЗАПУСК ПРЕКРАЩЕН (ТЕМПЕР ГАЗА ОПАСНАЯ, ДВ/С)
   uint16_t dv4_start_failed_gas_temp : 1; //!< [ДВ4-Д079] ДВ4 ЗАПУСК ПРЕКРАЩЕН (ТЕМПЕР ГАЗА ОПАСНАЯ, ДВ/С)
   uint16_t dv1_start_failed_handup   : 1; //!< [ДВ1-Д080] ДВ1 ЗАПУСК ПРЕКРАЩЕН (ВРЕМЯ ЗАП ПРЕВЫШ, ДВ/С)
   uint16_t dv2_start_failed_handup   : 1; //!< [ДВ2-Д080] ДВ2 ЗАПУСК ПРЕКРАЩЕН (ВРЕМЯ ЗАП ПРЕВЫШ, ДВ/С)
   uint16_t dv3_start_failed_handup   : 1; //!< [ДВ3-Д080] ДВ3 ЗАПУСК ПРЕКРАЩЕН (ВРЕМЯ ЗАП ПРЕВЫШ, ДВ/С)
   uint16_t dv4_start_failed_handup   : 1; //!< [ДВ4-Д080] ДВ4 ЗАПУСК ПРЕКРАЩЕН (ВРЕМЯ ЗАП ПРЕВЫШ, ДВ/С)
} mfci_signals_word_13_b_t;

//! Слово 14 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_14_b_t {
   uint16_t dv1_start_failed_ignition : 1; //!< [ДВ1-Д081] ДВ1 ЗАПУСК ПРЕКРАЩЕН (НЕТ РОЗЖИГА, ДВ/С)
   uint16_t dv2_start_failed_ignition : 1; //!< [ДВ2-Д081] ДВ2 ЗАПУСК ПРЕКРАЩЕН (НЕТ РОЗЖИГА, ДВ/С)
   uint16_t dv3_start_failed_ignition : 1; //!< [ДВ3-Д081] ДВ3 ЗАПУСК ПРЕКРАЩЕН (НЕТ РОЗЖИГА, ДВ/С)
   uint16_t dv4_start_failed_ignition : 1; //!< [ДВ4-Д081] ДВ4 ЗАПУСК ПРЕКРАЩЕН (НЕТ РОЗЖИГА, ДВ/С)
   uint16_t dv1_kpv_undefined         : 1; //!< [ДВ1-Л001] ДВ1 КОМПРЕСС ОТКАЗ (ДВ/С)
   uint16_t dv2_kpv_undefined         : 1; //!< [ДВ2-Л001] ДВ2 КОМПРЕСС ОТКАЗ (ДВ/С)
   uint16_t dv3_kpv_undefined         : 1; //!< [ДВ3-Л001] ДВ3 КОМПРЕСС ОТКАЗ (ДВ/С)
   uint16_t dv4_kpv_undefined         : 1; //!< [ДВ4-Л001] ДВ4 КОМПРЕСС ОТКАЗ (ДВ/С)
   uint16_t dv1_esud_failure          : 1; //!< [ДВ1-Л002] ДВ1 ЭСУД НЕИСПР (ДВ/С)
   uint16_t dv2_esud_failure          : 1; //!< [ДВ2-Л002] ДВ2 ЭСУД НЕИСПР (ДВ/С)
   uint16_t dv3_esud_failure          : 1; //!< [ДВ3-Л002] ДВ3 ЭСУД НЕИСПР (ДВ/С)
   uint16_t dv4_esud_failure          : 1; //!< [ДВ4-Л002] ДВ4 ЭСУД НЕИСПР (ДВ/С)
   uint16_t dv1_gas_temp_high_danger  : 1; //!< [ДВ1-Л003] ДВ1 ТЕМПЕР ГАЗА ОПАСНАЯ (ДВ/С)
   uint16_t dv2_gas_temp_high_danger  : 1; //!< [ДВ2-Л003] ДВ2 ТЕМПЕР ГАЗА ОПАСНАЯ (ДВ/С)
   uint16_t dv3_gas_temp_high_danger  : 1; //!< [ДВ3-Л003] ДВ3 ТЕМПЕР ГАЗА ОПАСНАЯ (ДВ/С)
   uint16_t dv4_gas_temp_high_danger  : 1; //!< [ДВ4-Л003] ДВ4 ТЕМПЕР ГАЗА ОПАСНАЯ (ДВ/С)
} mfci_signals_word_14_b_t;

//! Слово 15 сигнализации МФЦИ (сигналы ДВ)
typedef struct mfci_signals_word_15_b_t {
   uint16_t dv1_n1_high          : 1; //!< [ДВ1-Л004] ДВ1 ОБОРОТЫ НД ОПАСНЫЕ (ДВ/С)
   uint16_t dv2_n1_high          : 1; //!< [ДВ2-Л004] ДВ2 ОБОРОТЫ НД ОПАСНЫЕ (ДВ/С)
   uint16_t dv3_n1_high          : 1; //!< [ДВ3-Л004] ДВ3 ОБОРОТЫ НД ОПАСНЫЕ (ДВ/С)
   uint16_t dv4_n1_high          : 1; //!< [ДВ4-Л004] ДВ4 ОБОРОТЫ НД ОПАСНЫЕ (ДВ/С)
   uint16_t dv1_n2_high          : 1; //!< [ДВ1-Л005] ДВ1 ОБОРОТЫ ВД ОПАСНЫЕ (ДВ/С)
   uint16_t dv2_n2_high          : 1; //!< [ДВ2-Л005] ДВ2 ОБОРОТЫ ВД ОПАСНЫЕ (ДВ/С)
   uint16_t dv3_n2_high          : 1; //!< [ДВ3-Л005] ДВ3 ОБОРОТЫ ВД ОПАСНЫЕ (ДВ/С)
   uint16_t dv4_n2_high          : 1; //!< [ДВ4-Л005] ДВ4 ОБОРОТЫ ВД ОПАСНЫЕ (ДВ/С)
   uint16_t dv1_reserve_controls : 1; //!< [ДВ1-Л006] ДВ1 ПЕРЕХОД НА РА (ДВ/С)
   uint16_t dv2_reserve_controls : 1; //!< [ДВ2-Л006] ДВ2 ПЕРЕХОД НА РА (ДВ/С)
   uint16_t dv3_reserve_controls : 1; //!< [ДВ3-Л006] ДВ3 ПЕРЕХОД НА РА (ДВ/С)
   uint16_t dv4_reserve_controls : 1; //!< [ДВ4-Л006] ДВ4 ПЕРЕХОД НА РА (ДВ/С)
   uint16_t dv1_gas_temp_high    : 1; //!< [ДВ1-Л007] ДВ1 ТЕМПЕР ГАЗА ПОВЫШЕН (ДВ/С)
   uint16_t dv2_gas_temp_high    : 1; //!< [ДВ2-Л007] ДВ2 ТЕМПЕР ГАЗА ПОВЫШЕН (ДВ/С)
   uint16_t dv3_gas_temp_high    : 1; //!< [ДВ3-Л007] ДВ3 ТЕМПЕР ГАЗА ПОВЫШЕН (ДВ/С)
   uint16_t dv4_gas_temp_high    : 1; //!< [ДВ4-Л007] ДВ4 ТЕМПЕР ГАЗА ПОВЫШЕН (ДВ/С)
} mfci_signals_word_15_b_t;

//! Слово 16 сигнализации МФЦИ (сигналы ДВ, ТОПЛ)
typedef struct mfci_signals_word_16_b_t {
   uint16_t dv1_esud_untested   : 1; //!< [ДВ1-Л008] ДВ1 ЭСУД ПРОВЕРЬ (ДВ/С)
   uint16_t dv2_esud_untested   : 1; //!< [ДВ2-Л008] ДВ2 ЭСУД ПРОВЕРЬ (ДВ/С)
   uint16_t dv3_esud_untested   : 1; //!< [ДВ3-Л008] ДВ3 ЭСУД ПРОВЕРЬ (ДВ/С)
   uint16_t dv4_esud_untested   : 1; //!< [ДВ4-Л008] ДВ4 ЭСУД ПРОВЕРЬ (ДВ/С)
   uint16_t dv1_intake_untested : 1; //!< [ДВ1-Л009] ДВ1 АУ ВЗ ПРОВЕРЬ (ДВ/С)
   uint16_t dv2_intake_untested : 1; //!< [ДВ2-Л009] ДВ2 АУ ВЗ ПРОВЕРЬ (ДВ/С)
   uint16_t dv3_intake_untested : 1; //!< [ДВ3-Л009] ДВ3 АУ ВЗ ПРОВЕРЬ (ДВ/С)
   uint16_t dv4_intake_untested : 1; //!< [ДВ4-Л009] ДВ4 АУ ВЗ ПРОВЕРЬ (ДВ/С)
   uint16_t dv1_dv_active       : 1; //!< [ДВ1-Д027] Двигатель работает
   uint16_t dv2_dv_active       : 1; //!< [ДВ2-Д027] Двигатель работает
   uint16_t dv3_dv_active       : 1; //!< [ДВ3-Д027] Двигатель работает
   uint16_t dv4_dv_active       : 1; //!< [ДВ4-Д027] Двигатель работает
   uint16_t topl_dz_on          : 1; //!< [ТОПЛ-Д001] ТОПЛ АВТ ЗАПРАВКИ ВКЛ (ДВ/С)
   uint16_t topl_dz_failure     : 1; //!< [ТОПЛ-Д002] ТОПЛ АВТ ЗАПРАВКИ ОТКАЗ (ДВ/С)
   uint16_t topl_failure_left   : 1; //!< [ТОПЛ-Д003] ТОПЛ ИЗМЕР ЛЕВ БОРТА ОТКАЗ (ДВ/С)
   uint16_t topl_failure_right  : 1; //!< [ТОПЛ-Д004] ТОПЛ ИЗМЕР ПРАВ БОРТА ОТКАЗ (ДВ/С)
} mfci_signals_word_16_b_t;

//! Слово 17 сигнализации МФЦИ (сигналы ТОПЛ)
typedef struct mfci_signals_word_17_b_t {
   uint16_t dz_lock               : 1; //!< [ТОПЛ-Д005] ДОЗАПРАВКА СЦЕПКА (ДВ/С)
   uint16_t topl_discharge_front  : 1; //!< [ТОПЛ-Д006] ТОПЛ СЛИВ АВАР ПЕРЕДН БАКОВ (ДВ/С)
   uint16_t topl_discharge_rear   : 1; //!< [ТОПЛ-Д007] ТОПЛ СЛИВ АВАР ЗАДН БАКОВ (ДВ/С)
   uint16_t topl_pump_b1l_failure : 1; //!< [ТОПЛ-Д256] ТОПЛ НАСОСЫ Б1Л ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b1r_failure : 1; //!< [ТОПЛ-Д257] ТОПЛ НАСОСЫ Б1П ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b2l_failure : 1; //!< [ТОПЛ-Д258] ТОПЛ НАСОСЫ Б2Л ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b2r_failure : 1; //!< [ТОПЛ-Д259] ТОПЛ НАСОСЫ Б2П ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b3l_failure : 1; //!< [ТОПЛ-Д260] ТОПЛ НАСОСЫ Б3Л ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b3r_failure : 1; //!< [ТОПЛ-Д261] ТОПЛ НАСОСЫ Б3П ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b4l_failure : 1; //!< [ТОПЛ-Д262] ТОПЛ НАСОСЫ Б4Л ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b4r_failure : 1; //!< [ТОПЛ-Д263] ТОПЛ НАСОСЫ Б4П ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b5_failure  : 1; //!< [ТОПЛ-Д264] ТОПЛ НАСОСЫ Б5 ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b6_failure  : 1; //!< [ТОПЛ-Д265] ТОПЛ НАСОСЫ Б6 ОТКАЗ (ДВ/С)
   uint16_t topl_pump_rb1_failure : 1; //!< [ТОПЛ-Д266] ТОПЛ НАСОСЫ РБ1 ОТКАЗ (ДВ/С)
   uint16_t topl_pump_rb2_failure : 1; //!< [ТОПЛ-Д267] ТОПЛ НАСОСЫ РБ2 ОТКАЗ (ДВ/С)
   uint16_t topl_pump_rb3_failure : 1; //!< [ТОПЛ-Д268] ТОПЛ НАСОСЫ РБ3 ОТКАЗ (ДВ/С)
} mfci_signals_word_17_b_t;

//! Слово 18 сигнализации МФЦИ (сигналы ТОПЛ)
typedef struct mfci_signals_word_18_b_t {
   uint16_t topl_pump_rb4_failure         : 1; //!< [ТОПЛ-Д269] ТОПЛ НАСОСЫ РБ4 ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b1l_balance_failure : 1; //!< [ТОПЛ-Д270] ТОПЛ БАЛАНС НАСОСЫ Б1Л ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b1r_balance_failure : 1; //!< [ТОПЛ-Д271] ТОПЛ БАЛАНС НАСОСЫ Б1П ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b5_balance_failure  : 1; //!< [ТОПЛ-Д272] ТОПЛ БАЛАНС НАСОСЫ Б5 ОТКАЗ (ДВ/С)
   uint16_t topl_pump_b6_balance_failure  : 1; //!< [ТОПЛ-Д273] ТОПЛ БАЛАНС НАСОСЫ Б6 ОТКАЗ (ДВ/С)
   uint16_t topl_centering_failure        : 1; //!< [ТОПЛ-Д274] ТОПЛ АВТ ЦЕНТРОВКИ ОТКАЗ (ДВ/С)
   uint16_t topl_consump_failure          : 1; //!< [ТОПЛ-Д275] ТОПЛ АВТ РАСХОДА ОТКАЗ (ДВ/С)
   uint16_t dz_supply_on                  : 1; //!< [ТОПЛ-Д276] Включение питания щитка дозаправки
   uint16_t force_fueling                 : 1; //!< [ТОПЛ-Д285] Принудительная заправка
   uint16_t dz_valve                      : 1; //!< [ТОПЛ-Д287] КЛАПАН ШТАНГИ (ДВ/С)
   uint16_t dz_valve_opened               : 1; //!< [ТОПЛ-Д288] КЛАПАН ОТКРЫТ (ДВ/С)
   uint16_t topl_centering_rear_lim       : 1; //!< [ТОПЛ-Д291] ТОПЛ ЦЕНТРОВКА ЗАДН ПРЕДЕЛ (ДВ/С)
   uint16_t topl_centering_front_lim      : 1; //!< [ТОПЛ-Д292] ТОПЛ ЦЕНТРОВКА ПЕРЕДН ПРЕДЕЛ (ДВ/С)
   uint16_t topl_venting_on               : 1; //!< [ТОПЛ-Д293] ТОПЛ НАСОС ДРЕНАЖА ВКЛ (ДВ/С)
   uint16_t topl_venting_active           : 1; //!< [ТОПЛ-Д294] ТОПЛ ДРЕНАЖ В БАКЕ (ДВ/С)
   uint16_t topl_12t                      : 1; //!< [ТОПЛ-Л002] ТОПЛ ОСТАТОК 12 Т (ДВ/С)
} mfci_signals_word_18_b_t;

//! Слово 19 сигнализации МФЦИ (сигналы ТОПЛ)
typedef struct mfci_signals_word_19_b_t {
   uint16_t topl_rb1_pump1_fail      : 1; //!< [ТОПЛ-Л_Н1РБ1_ОТКАЗ] ТОПЛ НАСОС 1 РБ1 ОТКАЗ (ДВ/С)
   uint16_t topl_rb1_pump2_fail      : 1; //!< [ТОПЛ-Л_Н2РБ1_ОТКАЗ] ТОПЛ НАСОС 2 РБ1 ОТКАЗ (ДВ/С)
   uint16_t topl_rb1_pump3_fail      : 1; //!< [ТОПЛ-Л_Н3РБ1_ОТКАЗ] ТОПЛ НАСОС 3 РБ1 ОТКАЗ (ДВ/С)
   uint16_t topl_rb2_pump1_fail      : 1; //!< [ТОПЛ-Л_Н1РБ2_ОТКАЗ] ТОПЛ НАСОС 1 РБ2 ОТКАЗ (ДВ/С)
   uint16_t topl_rb2_pump2_fail      : 1; //!< [ТОПЛ-Л_Н2РБ2_ОТКАЗ] ТОПЛ НАСОС 2 РБ2 ОТКАЗ (ДВ/С)
   uint16_t topl_rb2_pump3_fail      : 1; //!< [ТОПЛ-Л_Н3РБ2_ОТКАЗ] ТОПЛ НАСОС 3 РБ2 ОТКАЗ (ДВ/С)
   uint16_t topl_rb3_pump1_fail      : 1; //!< [ТОПЛ-Л_Н1РБ3_ОТКАЗ] ТОПЛ НАСОС 1 РБ3 ОТКАЗ (ДВ/С)
   uint16_t topl_rb3_pump2_fail      : 1; //!< [ТОПЛ-Л_Н2РБ3_ОТКАЗ] ТОПЛ НАСОС 2 РБ3 ОТКАЗ (ДВ/С)
   uint16_t topl_rb3_pump3_fail      : 1; //!< [ТОПЛ-Л_Н3РБ3_ОТКАЗ] ТОПЛ НАСОС 3 РБ3 ОТКАЗ (ДВ/С)
   uint16_t topl_rb4_pump1_fail      : 1; //!< [ТОПЛ-Л_Н1РБ4_ОТКАЗ] ТОПЛ НАСОС 1 РБ4 ОТКАЗ (ДВ/С)
   uint16_t topl_rb4_pump2_fail      : 1; //!< [ТОПЛ-Л_Н2РБ4_ОТКАЗ] ТОПЛ НАСОС 2 РБ4 ОТКАЗ (ДВ/С)
   uint16_t topl_rb4_pump3_fail      : 1; //!< [ТОПЛ-Л_Н3РБ4_ОТКАЗ] ТОПЛ НАСОС 3 РБ4 ОТКАЗ (ДВ/С)
   uint16_t topl_valve_pk1_closed_kv : 1; //!< [ТОПЛ-Д141] КВ ЗАКР пожарного крана ПК1 (для счетчика давления азота)
   uint16_t topl_valve_pk2_closed_kv : 1; //!< [ТОПЛ-Д145] КВ ЗАКР пожарного крана ПК2 (для счетчика давления азота)
   uint16_t topl_valve_pk3_closed_kv : 1; //!< [ТОПЛ-Д149] КВ ЗАКР пожарного крана ПК3 (для счетчика давления азота)
   uint16_t topl_valve_pk4_closed_kv : 1; //!< [ТОПЛ-Д153] КВ ЗАКР пожарного крана ПК4 (для счетчика давления азота)
} mfci_signals_word_19_b_t;

//! Слово 20 сигнализации МФЦИ (сигналы ТОПЛ, ПКР)
typedef struct mfci_signals_word_20_b_t {
   uint16_t topl_check_rb1  : 1; //!< [ТОПЛ-Д277] Проверь топливо РБ1 (положение РУД>72° нежелательно, для шкал двигателей)
   uint16_t topl_check_rb2  : 1; //!< [ТОПЛ-Д278] Проверь топливо РБ2 (положение РУД>72° нежелательно, для шкал двигателей)
   uint16_t topl_check_rb3  : 1; //!< [ТОПЛ-Д279] Проверь топливо РБ3 (положение РУД>72° нежелательно, для шкал двигателей)
   uint16_t topl_check_rb4  : 1; //!< [ТОПЛ-Д280] Проверь топливо РБ4 (положение РУД>72° нежелательно, для шкал двигателей)
   uint16_t topl_check      : 1; //!< [ТОПЛ-Л001] ТОПЛ ПРОВЕРЬ (ДВ/С)
   uint16_t speed_high      : 1; //!< [ПКР-Д001] СКОРОСТЬ ВЕЛИКА (ДВ/С)
   uint16_t speed_low       : 1; //!< [ПКР-Д002] СКОРОСТЬ МАЛА (ДВ/С)
   uint16_t ny_high         : 1; //!< [ПКР-Д003] Ny ПРЕДЕЛ (перегрузка выше максимальной, ДВ/С)
   uint16_t ny_low          : 1; //!< [ПКР-Д004] Ny ПРЕДЕЛ (перегрузка ниже минимальной, ДВ/С)
   uint16_t roll_left_high  : 1; //!< [ПКР-Д005] КРЕН ВЕЛИК (левый, ДВ/С)
   uint16_t roll_right_high : 1; //!< [ПКР-Д006] КРЕН ВЕЛИК (правый, ДВ/С)
   uint16_t alpha_high      : 1; //!< [ПКР-Д007] АЛЬФА ПРЕДЕЛ (угол атаки выше максимального, ДВ/С)
   uint16_t alpha_low       : 1; //!< [ПКР-Д008] АЛЬФА ПРЕДЕЛ (угол атаки ниже минимального, ДВ/С)
   uint16_t altitude_appr_1 : 1; //!< [ПКР-Д009] ЭШЕЛОН ПОДХОД (ДВ/С)
   uint16_t altitude_appr_2 : 1; //!< [ПКР-Д012] ЗАДАННАЯ ВЫСОТА ПОДХОД (ДВ/С)
   uint16_t pkr_failure     : 1; //!< [ПКР-Д017] ФУНКЦИИ ПКР ОТКАЗ (ДВ/С)
} mfci_signals_word_20_b_t;

//! Слово 21 сигнализации МФЦИ (сигналы ПКР, САУ)
typedef struct mfci_signals_word_21_b_t {
   uint16_t pkr_alpha_off       : 1; //!< [ПКР-Д018] ПКР НЕТ КОНТРОЛЯ УГЛА АТАКИ (СОСТ)
   uint16_t pkr_speed_min_off   : 1; //!< [ПКР-Д019] ПКР НЕТ КОНТРОЛЯ СКОРОСТИ МИН (СОСТ)
   uint16_t pkr_speed_max_off   : 1; //!< [ПКР-Д020] ПКР НЕТ КОНТРОЛЯ СКОРОСТИ МАКС (СОСТ)
   uint16_t pkr_ny_off          : 1; //!< [ПКР-Д021] ПКР НЕТ КОНТРОЛЯ ПЕРЕГРУЗКИ (СОСТ)
   uint16_t pkr_roll_off        : 1; //!< [ПКР-Д022] ПКР НЕТ КОНТРОЛЯ КРЕНА (СОСТ)
   uint16_t pkr_altitude_off_1  : 1; //!< [ПКР-Д023] ПКР НЕТ КОНТРОЛЯ ЗАДАННОГО ЭШЕЛОНА (СОСТ)
   uint16_t pkr_altitude_off_2  : 1; //!< [ПКР-Д024] ПКР НЕТ КОНТРОЛЯ ЗАДАННОЙ ВЫСОТЫ (СОСТ)
   uint16_t check_altitude      : 1; //!< [ПКР-Л001] ЭШЕЛОН ВЫСОТУ ПРОВЕРЬ (ДВ/С)
   uint16_t ap_failure          : 1; //!< [САУ-Д022] АП ОТКАЗ (ДВ/С)
   uint16_t azp_failure         : 1; //!< [САУ-Д023] АЗП ЗАПРЕЩЕН (ДВ/С)
   uint16_t ap_off              : 1; //!< [САУ-Д024] АП ОТКЛЮЧЕН (ДВ/С)
   uint16_t ap_mode_changed     : 1; //!< [САУ-Д025] АП РЕЖИМ ИЗМЕНЕН (ДВ/С)
   uint16_t at_control          : 1; //!< [САУ-Д026] ТЯГОЙ УПРАВЛЯЙ (ДВ/С)
   uint16_t landing_cathegory_1 : 1; //!< [САУ-Д042] КАТЕГОР ПОСАД1 (СОСТ)
   uint16_t landing_cathegory_2 : 1; //!< [САУ-Д043] КАТЕГОР ПОСАД2 (СОСТ)
   uint16_t sau_manual          : 1; //!< [САУ] ПЕРЕЙДИ НА ШТУРВАЛ (ДВ/С)
} mfci_signals_word_21_b_t;

//! Слово 22 сигнализации МФЦИ (сигналы САУ, АБСУ)
typedef struct mfci_signals_word_22_b_t {
   uint16_t unlock_rud               : 1; //!< [САУ] РУД РАССТОПОРИ (ДВ/С)
   uint16_t dv1_at_off               : 1; //!< [САУ] ДВ1 АТ ОТКЛЮЧЕН (ДВ/С)
   uint16_t dv2_at_off               : 1; //!< [САУ] ДВ2 АТ ОТКЛЮЧЕН (ДВ/С)
   uint16_t dv3_at_off               : 1; //!< [САУ] ДВ3 АТ ОТКЛЮЧЕН (ДВ/С)
   uint16_t dv4_at_off               : 1; //!< [САУ] ДВ4 АТ ОТКЛЮЧЕН (ДВ/С)
   uint16_t dz_pitch                 : 1; //!< [АБСУ-Д024] УПОР ДЗ ТАНГАЖ (ДВ/С)
   uint16_t assu_pitch_failure       : 1; //!< [АБСУ-Л019] АСШУ ТАНГАЖ ОТКАЗ (ДВ/С)
   uint16_t assu_interc_failure      : 1; //!< [АБСУ-Л020] ИНТЕРЦ ОТКАЗ (ДВ/С)
   uint16_t assu_fin_failure         : 1; //!< [АБСУ-Л021] КИЛЬ ОТКАЗ (ДВ/С)
   uint16_t absu_dmp_pitch_failure   : 1; //!< [АБСУ-Д037] АБСУ ДЕМПФЕР ТАНГАЖА ОТКАЗ (СОСТ)
   uint16_t absu_dmp_roll_failure    : 1; //!< [АБСУ-Д038] АБСУ ДЕМПФЕР КРЕНА ОТКАЗ (СОСТ)
   uint16_t absu_dmp_heading_failure : 1; //!< [АБСУ-Д039] АБСУ ДЕМПФЕР КУРСА ОТКАЗ (СОСТ)
   uint16_t absu_ny_invalid          : 1; //!< [АБСУ-Д040] АБСУ ОГРАНИЧЕНИЕ ПО ny ОТКАЗ (СОСТ)
   uint16_t absu_roll_invalid        : 1; //!< [АБСУ-Д041] АБСУ ОГРАНИЧЕНИЕ КРЕНА ОТКАЗ (СОСТ)
   uint16_t absu_stab_off            : 1; //!< [АБСУ-Д042] АБСУ СТАБ ОТКЛЮЧЕН (СОСТ)
   uint16_t absu_fin_off             : 1; //!< [АБСУ-Д043] АБСУ КИЛЬ ОТКЛЮЧЕН (СОСТ)
} mfci_signals_word_22_b_t;

//! Слово 23 сигнализации МФЦИ (сигналы АБСУ)
typedef struct mfci_signals_word_23_b_t {
   uint16_t absu_interc_off           : 1; //!< [АБСУ-Д044] АБСУ ИНТЕРЦ ОТКЛЮЧЕНЫ (СОСТ)
   uint16_t absu_flaperon_off         : 1; //!< [АБСУ-Д045] АБСУ ФЛАП ОТКЛЮЧЕНЫ (СОСТ)
   uint16_t dmp_ra_off_1              : 1; //!< [АБСУ-Д046] АБСУ ДЕМПФЕР РА 1К ОТКЛЮЧЕНЫ (СОСТ)
   uint16_t dmp_ra_off_2              : 1; //!< [АБСУ-Д047] АБСУ ДЕМПФЕР РА 2К ОТКЛЮЧЕНЫ (СОСТ)
   uint16_t dmp_ra_off_3              : 1; //!< [АБСУ-Д048] АБСУ ДЕМПФЕР РА 3К ОТКЛЮЧЕНЫ (СОСТ)
   uint16_t dmp_ra_off_4              : 1; //!< [АБСУ-Д049] АБСУ ДЕМПФЕР РА 4К ОТКЛЮЧЕНЫ (СОСТ)
   uint16_t dau_left_heating_failure  : 1; //!< [АБСУ-Д050] ДАУ ЛЕВ ОБОГРЕВА НЕТ (СОСТ)
   uint16_t dau_right_heating_failure : 1; //!< [АБСУ-Д051] ДАУ ПРАВ ОБОГРЕВА НЕТ (СОСТ)
   uint16_t mb_pitch1_failure         : 1; //!< [АБСУ-Д052] АБСУ МБ ТАНГ КАН 1 ОТКАЗ (СОСТ)
   uint16_t mb_pitch2_failure         : 1; //!< [АБСУ-Д053] АБСУ МБ ТАНГ КАН 2 ОТКАЗ (СОСТ)
   uint16_t mr3_1_failure             : 1; //!< [АБСУ-Д056] АБСУ МРЗ КАН 1 ОТКАЗ (СОСТ)
   uint16_t mr3_2_failure             : 1; //!< [АБСУ-Д057] АБСУ МРЗ КАН 2 ОТКАЗ (СОСТ)
   uint16_t assu_flaperon_failure     : 1; //!< [АБСУ-Л022] АСШУ ФЛАП ОТКАЗ (ДВ/С)
   uint16_t interc                    : 1; //!< [АБСУ-Д065] ИНТРЦ ВЫПУЩЕНЫ (НЕ ГОТОВ К ВЗЛЁТУ)
   uint16_t absu_weight_failure       : 1; //!< [АБСУ-Д066] АБСУ НЕТ ДАННЫХ ПО ВЕСУ (СОСТ)
   uint16_t absu_vsp_failure          : 1; //!< [АБСУ-Д067] АБСУ НЕТ ДАННЫХ ПО ВСП (СОСТ)
} mfci_signals_word_23_b_t;

//! Слово 24 сигнализации МФЦИ (сигналы АБСУ)
typedef struct mfci_signals_word_24_b_t {
   uint16_t absu_flap_failure          : 1; //!< [АБСУ-Д068] АБСУ НЕТ ДАННЫХ ПО ЗАКРЫЛКАМ (СОСТ)
   uint16_t absu_chi_failure           : 1; //!< [АБСУ-Д069] АБСУ НЕТ ДАННЫХ ПО СТРЕЛОВИДНОСТИ (СОСТ)
   uint16_t absu_alpha_failure         : 1; //!< [АБСУ-Д070] АБСУ НЕТ ДАННЫХ ПО УГЛУ АТАКИ (СОСТ)
   uint16_t trimmer_roll_failure       : 1; //!< [АБСУ-Д071] ТРИММЕР КРЕНА ОТКАЗ (ДВ/С)
   uint16_t trimmer_course_failure     : 1; //!< [АБСУ-Д072] ТРИММЕР КУРСА ОТКАЗ (ДВ/С)
   uint16_t trimmer_pitch_failure      : 1; //!< [АБСУ-Д073] ТРИММЕР ТАНГАЖА ОТКАЗ (ДВ/С)
   uint16_t absu_nx_failure            : 1; //!< [АБСУ-Д078] АБСУ ОГРАНИЧЕНИЕ ПО Nх ОТКАЗ (СОСТ)
   uint16_t absu_stab_no_reserve       : 1; //!< [АБСУ-Л001] РА СТАБ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t absu_fin_no_reserve        : 1; //!< [АБСУ-Л002] РА КИЛЬ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t absu_flaperon_l_no_reserve : 1; //!< [АБСУ-Л003] РА ФЛАП ЛЕВ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t absu_flaperon_r_no_reserve : 1; //!< [АБСУ-Л004] РА ФЛАП ПРАВ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t absu_interc_l_no_reserve   : 1; //!< [АБСУ-Л005] РА ИНТЕРЦ ЛЕВ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t absu_interc_r_no_reserve   : 1; //!< [АБСУ-Л006] РА ИНТЕРЦ ПРАВ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t absu_limit                 : 1; //!< [АБСУ-Л007] ОГРАНИЧЬ АЛЬФУ, ny, ГАММУ (ДВ/С)
   uint16_t balance_failure            : 1; //!< [АБСУ-Л008] AВТОБАЛАНС ОТКАЗ (ДВ/С)
   uint16_t set_m09_chi35              : 1; //!< [АБСУ-Л009] ПЕРЕЙДИ М<0.9 ХИ<35 (ДВ/С)
} mfci_signals_word_24_b_t;

//! Слово 25 сигнализации МФЦИ (сигналы АБСУ, СМК)
typedef struct mfci_signals_word_25_b_t {
   uint16_t roll_careful            : 1; //!< [АБСУ-Л010] УПРАВЛЯЙ КРЕНОМ ПЛАВНО (ДВ/С)
   uint16_t set_v900                : 1; //!< [АБСУ-Л011] ПЕРЕЙДИ НА V<900 (ДВ/С)
   uint16_t absu_landing_flap_15    : 1; //!< [АБСУ-Л012] ПОСАДКА ЗАКРЛК 15, V>300 (ДВ/С)
   uint16_t flap_unstable           : 1; //!< [АБСУ-Л013] ЗАКРЛК ПАРИРУЙ (ДВ/С)
   uint16_t bad_side_controls       : 1; //!< [АБСУ-Л014] БОК УПРАВЛ СНИЖЕНО (ДВ/С)
   uint16_t vt_failure              : 1; //!< [АБСУ-Л015] ВОЗД ТОРМ ОТКАЗ (ДВ/С)
   uint16_t pedals_failure          : 1; //!< [АБСУ-Л016] УПРАВЛ ПЕДАЛЯМИ ОТКАЗ (ДВ/С)
   uint16_t roll_no_neutral         : 1; //!< [АБСУ-Л017] КРЕН НЕЙТРАЛИ НЕТ (ДВ/С)
   uint16_t heading_no_neutral      : 1; //!< [АБСУ-Л018] КУРС НЕЙТРАЛИ НЕТ (ДВ/С)
   uint16_t flap_failure            : 1; //!< [СМК-Л001] ЗАКРЛК ОТКАЗ (ДВ/С)
   uint16_t slat_failure            : 1; //!< [СМК-Л002] ПРЕДКР ОТКАЗ (ДВ/С)
   uint16_t flap_correction_failure : 1; //!< [СМК-Л003] ЗАКРЛ-ПРЕДКР КОРРЕКЦИЯ ОТКАЗ (ДВ/С)
   uint16_t flap_track_mode_failure : 1; //!< [СМК-Л005] ЗАКРЛК-ПРЕДКР СЛЕДЯЩ РЕЖИМ ОТКАЗ (ДВ/С)
   uint16_t flap_async              : 1; //!< [СМК-Л007] ЗАКРЛК РАССИНХ (ДВ/С)
   uint16_t slat_async              : 1; //!< [СМК-Л008] ПРЕДКР РАССИНХ (ДВ/С)
   uint16_t flap_not_ready          : 1; //!< [СМК-Л009] ЗАКРЛК НЕВЗЛЕТ (НЕ ГОТОВ К ВЗЛЁТУ)
} mfci_signals_word_25_b_t;

//! Слово 26 сигнализации МФЦИ (сигналы СМК, СК, ТОРМ)
typedef struct mfci_signals_word_26_b_t {
   uint16_t flap_left_slow            : 1; //!< [СМК-Л010] ЗАКРЛ ЛЕВ ЗАТОРМ (ДВ/С)
   uint16_t flap_right_slow           : 1; //!< [СМК-Л011] ЗАКРЛ ПРАВ ЗАТОРМ (ДВ/С)
   uint16_t wing_track_mode_failure   : 1; //!< [СМК-Л012] КРЫЛО СЛЕДЯЩ РЕЖИМ ОТКАЗ (ДВ/С)
   uint16_t wing_failure              : 1; //!< [СМК-Л013] КРЫЛО ОТКАЗ (ДВ/С)
   uint16_t wing_async                : 1; //!< [СМК-Л015] КРЫЛО РАССИНХ (ДВ/С)
   uint16_t seat_pilot_1_moved_back   : 1; //!< [СК-Д001] КРЕСЛО КОМАНДИРА ОТКАТ (ДВ/С)
   uint16_t seat_pilot_2_moved_back   : 1; //!< [СК-Д002] КРЕСЛО ПОМОЩНИКА ОТКАТ (ДВ/С)
   uint16_t main_brakes_failure_1     : 1; //!< [ТОРМ-Д401] ТОРМ ОСН ОТКАЗ (ДВ/С)
   uint16_t emerg_brakes_failure      : 1; //!< [ТОРМ-Д601] ТОРМ РЕЗЕРВ ОТКАЗ (ДВ/С)
   uint16_t emerg_brakes_on           : 1; //!< [ТОРМ-Д603] ТОРМ РЕЗЕРВ ВКЛЮЧЕН (ДВ/С)
   uint16_t brakes_low_accum_pressure : 1; //!< [ТОРМ-Д620] ТОРМ ДАВЛ Г/АКК МАЛО (ДВ/С)
   uint16_t emergency_braking         : 1; //!< [ТОРМ-Д622] ТОРМОЖЕНИЕ АВАРИЙНОЕ (ДВ/С)
   uint16_t auto_brakes_off           : 1; //!< [ТОРМ-Л002] ТОРМ АВТ ОТКЛЮЧЕНО (ДВ/С)
   uint16_t gear_on_brakes            : 1; //!< [ТОРМ-Л004] КОЛЕСА ЗАТОРМОЖЕНЫ (ДВ/С)
   uint16_t start_braking             : 1; //!< [ТОРМ-Л005] СТАРТ ТОРМ ВКЛЮЧЕН (ДВ/С)
   uint16_t parking_brake_on          : 1; //!< [ТОРМ-Л007] СТОЯН ТОРМ ВКЛЮЧЕН (ДВ/С)
} mfci_signals_word_26_b_t;

//! Слово 27 сигнализации МФЦИ (сигналы ТОРМ, СЭС)
typedef struct mfci_signals_word_27_b_t {
   uint16_t auto_brakes_slight       : 1; //!< [ТОРМ-Л008] ТОРМОЖЕНИЕ АВТ СЛАБО (ДВ/С)
   uint16_t auto_brakes_low          : 1; //!< [ТОРМ-Л009] ТОРМОЖЕНИЕ АВТ ПОНИЖ (ДВ/С)
   uint16_t auto_brakes_normal       : 1; //!< [ТОРМ-Л010] ТОРМОЖЕНИЕ АВТ НОРМ (ДВ/С)
   uint16_t brakes_pair_failure      : 1; //!< [ТОРМ-Л011] ТОРМ ОДНА ПАРА ОТКАЗ (СОСТ)
   uint16_t main_brakes_failure_3    : 1; //!< [ТОРМ-Л012] ТОРМ ОСН ОТКАЗ (ДВ/С)
   uint16_t sas_115v_gen1_not_active : 1; //!< [СЭС-Д201] СЭС 115В ГЕН1 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_115v_gen2_not_active : 1; //!< [СЭС-Д202] СЭС 115В ГЕН2 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_115v_gen3_not_active : 1; //!< [СЭС-Д203] СЭС 115В ГЕН3 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_115v_gen4_not_active : 1; //!< [СЭС-Д204] СЭС 115В ГЕН4 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_115v_gen1_overload   : 1; //!< [СЭС-Д209] СЭС 115В ГЕН1 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_115v_gen2_overload   : 1; //!< [СЭС-Д210] СЭС 115В ГЕН2 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_115v_gen3_overload   : 1; //!< [СЭС-Д211] СЭС 115В ГЕН3 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_115v_gen4_overload   : 1; //!< [СЭС-Д212] СЭС 115В ГЕН4 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_115v_partial_left    : 1; //!< [СЭС-Д231] СЭС 115В СЕТЬ ЛЕВ ЧАСТИЧ РЕЖИМ (СИГН)
   uint16_t sas_115v_partial_right   : 1; //!< [СЭС-Д232] СЭС 115В СЕТЬ ПРАВ ЧАСТИЧ РЕЖИМ (СИГН)
   uint16_t sas_115v_connected       : 1; //!< [СЭС-Д233] СЭС 115В СЕТИ СОЕДИНЕНЫ (СИГН)
} mfci_signals_word_27_b_t;

//! Слово 28 сигнализации МФЦИ (сигналы СЭС)
typedef struct mfci_signals_word_28_b_t {
   uint16_t sas_115v_brzu_gen1_failure : 1; //!< [СЭС-Л006] СЭС 115В БРЗУ ГЕН1 ОТКАЗ (СИГН)
   uint16_t sas_115v_brzu_gen2_failure : 1; //!< [СЭС-Л007] СЭС 115В БРЗУ ГЕН2 ОТКАЗ (СИГН)
   uint16_t sas_115v_brzu_gen3_failure : 1; //!< [СЭС-Л008] СЭС 115В БРЗУ ГЕН3 ОТКАЗ (СИГН)
   uint16_t sas_115v_brzu_gen4_failure : 1; //!< [СЭС-Л009] СЭС 115В БРЗУ ГЕН4 ОТКАЗ (СИГН)
   uint16_t sas_115v_brzu_vsu_failure  : 1; //!< [СЭС-Л010] СЭС 115В БРЗУ ГЕН ВСУ ОТКАЗ (СИГН)
   uint16_t sas_115v_transd1_failure   : 1; //!< [СЭС-Л011] СЭС 115В ПРЕОБР1 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_115v_transd3_failure   : 1; //!< [СЭС-Л013] СЭС 115В ПРЕОБР3 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_115v_turn_off_ppo_gen1 : 1; //!< [СЭС-Л018] СЭС 115В ППО ГЕН1 ОТКЛЮЧИ (СИГН)
   uint16_t sas_115v_turn_off_ppo_gen2 : 1; //!< [СЭС-Л019] СЭС 115В ППО ГЕН2 ОТКЛЮЧИ (СИГН)
   uint16_t sas_115v_turn_off_ppo_gen3 : 1; //!< [СЭС-Л020] СЭС 115В ППО ГЕН3 ОТКЛЮЧИ (СИГН)
   uint16_t sas_115v_turn_off_ppo_gen4 : 1; //!< [СЭС-Л021] СЭС 115В ППО ГЕН4 ОТКЛЮЧИ (СИГН)
   uint16_t sas_27v_connected          : 1; //!< [СЭС-Д325] СЭС 27В СЕТИ СОЕДИНЕНЫ (СИГН)
   uint16_t sas_27v_gen1_not_active    : 1; //!< [СЭС-Д301] СЭС 27В Г1 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_27v_gen2_not_active    : 1; //!< [СЭС-Д302] СЭС 27В Г2 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_27v_gen3_not_active    : 1; //!< [СЭС-Д303] СЭС 27В Г3 НЕ РАБОТАЕТ (СОСТ)
   uint16_t sas_27v_gen4_not_active    : 1; //!< [СЭС-Д304] СЭС 27В Г4 НЕ РАБОТАЕТ (СОСТ)
} mfci_signals_word_28_b_t;

//! Слово 29 сигнализации МФЦИ (сигналы СЭС)
typedef struct mfci_signals_word_29_b_t {
   uint16_t sas_27v_gen1_overload     : 1; //!< [СЭС-Д309] СЭС 27В Г1 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_27v_gen2_overload     : 1; //!< [СЭС-Д310] СЭС 27В Г2 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_27v_gen3_overload     : 1; //!< [СЭС-Д311] СЭС 27В Г3 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_27v_gen4_overload     : 1; //!< [СЭС-Д312] СЭС 27В Г4 ПЕРЕГРУЗКА (СИГН)
   uint16_t sas_27v_left_on_battery   : 1; //!< [СЭС-Д321] СЭС 27В СЕТЬ ЛЕВ ОТ АКК (СИГН)
   uint16_t sas_27v_right_on_battery  : 1; //!< [СЭС-Д322] СЭС 27В СЕТЬ ПРАВ ОТ АКК (СИГН)
   uint16_t sas_27v_left_partial      : 1; //!< [СЭС-Д323] СЭС 27В СЕТЬ ЛЕВ ЧАСТИЧ РЕЖИМ (СИГН)
   uint16_t sas_27v_right_partial     : 1; //!< [СЭС-Д324] СЭС 27В СЕТЬ ПРАВ ЧАСТИЧ РЕЖИМ (СИГН)
   uint16_t sas_27v_turn_off_battery1 : 1; //!< [СЭС-Л014] СЭС 27В АКК1 ОТКЛЮЧИ (СИГН)
   uint16_t sas_27v_turn_off_battery2 : 1; //!< [СЭС-Л015] СЭС 27В АКК2 ОТКЛЮЧИ (СИГН)
   uint16_t sas_27v_battery1_off      : 1; //!< [СЭС-Л016] СЭС 27В АКК1 ОТКЛЮЧЕН (СОСТ)
   uint16_t sas_27v_battery2_off      : 1; //!< [СЭС-Л017] СЭС 27В АКК2 ОТКЛЮЧЕН (СОСТ)
   uint16_t sas_27v_turn_off_gen1     : 1; //!< [СЭС-Л022] СЭС 27В Г1 ОТКЛЮЧИ (СИГН)
   uint16_t sas_27v_turn_off_gen2     : 1; //!< [СЭС-Л023] СЭС 27В Г2 ОТКЛЮЧИ (СИГН)
   uint16_t sas_27v_turn_off_gen3     : 1; //!< [СЭС-Л024] СЭС 27В Г3 ОТКЛЮЧИ (СИГН)
   uint16_t sas_27v_turn_off_gen4     : 1; //!< [СЭС-Л025] СЭС 27В Г4 ОТКЛЮЧИ (СИГН)
} mfci_signals_word_29_b_t;

//! Слово 30 сигнализации МФЦИ (сигналы ГС)
typedef struct mfci_signals_word_30_b_t {
   uint16_t gs_crossfeeding        : 1; //!< [ГС-Д033] ГС КРАНЫ КОЛЬЦ ВКЛ (НЕ ГОТОВ К ВЗЛЁТУ)
   uint16_t gs_tgt_circuit_failure : 1; //!< [ГС-Д034] КОНТУР ТЖТ ОТКАЗ (ДВ/С)
   uint16_t gs_tgt_pump_failure    : 1; //!< [ГС-Д035] НАСОС ТЖТ ОТКАЗ (ДВ/С)
   uint16_t gs1_failure            : 1; //!< [ГС-Л005] ГС1 ОТКАЗ (ДВ/С)
   uint16_t gs2_failure            : 1; //!< [ГС-Л006] ГС2 ОТКАЗ (ДВ/С)
   uint16_t gs3_failure            : 1; //!< [ГС-Л007] ГС3 ОТКАЗ (ДВ/С)
   uint16_t gs4_failure            : 1; //!< [ГС-Л008] ГС4 ОТКАЗ (ДВ/С)
   uint16_t gs2_pump1_off          : 1; //!< [ГС-Л047] ГС2 Н1 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs1_pump2_off          : 1; //!< [ГС-Л048] ГС1 Н2 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs2_pump3_off          : 1; //!< [ГС-Л049] ГС2 Н3 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs1_pump4_off          : 1; //!< [ГС-Л050] ГС1 Н4 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs4_pump5_off          : 1; //!< [ГС-Л051] ГС4 Н5 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs3_pump6_off          : 1; //!< [ГС-Л052] ГС3 Н6 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs4_pump7_off          : 1; //!< [ГС-Л053] ГС4 Н7 ОТКЛЮЧЕН (ДВ/С)
   uint16_t gs3_pump8_off          : 1; //!< [ГС-Л054] ГС3 Н8 ОТКЛЮЧЕН (ДВ/С)
   uint16_t dv_pumps_failure       : 1; //!< [ОС-Л020] Г/НАСОСЫ ДВ ОТКЛ (НЕ ГОТОВ К ВЗЛЁТУ)
} mfci_signals_word_30_b_t;

//! Слово 31 сигнализации МФЦИ (сигналы ВСУ)
typedef struct mfci_signals_word_31_b_t {
   uint16_t vsu_oil_pressure_low     : 1; //!< [ВСУ-Д001] ДАВЛЕНИЕ МАСЛА ПРЕДЕЛ (ВСУ)
   uint16_t vsu_tg_high              : 1; //!< [ВСУ-Д002] ТЕМПЕР ГАЗА ПРЕДЕЛ (ВСУ)
   uint16_t vsu_n_high               : 1; //!< [ВСУ-Д003] ОБОРОТЫ ПРЕДЕЛ (ВСУ)
   uint16_t vsu_clogging             : 1; //!< [ВСУ-Д007] ТОПЛ ФИЛЬТР ЗАСОРЕН (ВСУ)
   uint16_t vsu_swarf                : 1; //!< [ВСУ-Д008] СТРУЖКА В МАСЛЕ (ВСУ)
   uint16_t vsu_fuel_pressure_normal : 1; //!< [ВСУ-Д009] ДАВЛЕНИЕ ТОПЛИВА (ВСУ)
   uint16_t vsu_air_bleed            : 1; //!< [ВСУ-Д010] ОТБОР ОТКРЫТ (ВСУ)
   uint16_t vsu_ready                : 1; //!< [ВСУ-Д012] ЗАПУСК ГОТОВ (ВСУ)
   uint16_t vsu_oil_level_low        : 1; //!< [ВСУ-Д013] МАСЛА МАЛО (ВСУ)
   uint16_t vsu_mode_active          : 1; //!< [ВСУ-Д014] РЕЖИМ (ВСУ, ДВ/С, СИГН)
   uint16_t vsu_unsafe               : 1; //!< [ВСУ-Д018] ЗАЩИТА ОТКЛЮЧЕНА (ВСУ)
   uint16_t vsu_test                 : 1; //!< [ВСУ-Д019] КОНТРОЛЬ (ВСУ)
   uint16_t vsu_oil_temperature_high : 1; //!< [ВСУ-Д020] ТЕМПЕР МАСЛА ВЕЛИКА (ВСУ)
   uint16_t vsu_warning              : 1; //!< [ВСУ-Л002] ВСУ НЕИСПРАВНОСТЬ (СОСТ)
   uint16_t vsu_failure              : 1; //!< [ВСУ-Л003] ВСУ ОТКАЗ (СОСТ)
   uint16_t vsu_turned_off           : 1; //!< [ВСУ-Л004] ВСУ АВАРИЙНЫЙ ОСТАНОВ (ДВ/С, СИГН)
} mfci_signals_word_31_b_t;

//! Слово 32 сигнализации МФЦИ (сигналы ВСУ, СКВ)
typedef struct mfci_signals_word_32_b_t {
   uint16_t vsu_n_high               : 1; //!< [ВСУ-Л005] ОБОРОТЫ ВЕЛИКИ (ВСУ)
   uint16_t vsu_tg_high              : 1; //!< [ВСУ-Л006] ТЕМПЕР ГАЗА ВЕЛИКА (ВСУ)
   uint16_t vsu_oil_pressure_low     : 1; //!< [ВСУ-Л007] ДАВЛЕНИЕ МАСЛА МАЛО (ВСУ)
   uint16_t vsu_shutters_opened      : 1; //!< [ВСУ-Л008] СТВОРКИ ОТКРЫТЫ (ВСУ, ДВ/С, СИГН)
   uint16_t skv_line_left_failure    : 1; //!< [СКВ-Д024] СКВ МАГИСТРАЛЬ ЛЕВ ОТКАЗ (СИГН)
   uint16_t skv_line_right_failure   : 1; //!< [СКВ-Д025] СКВ МАГИСТРАЛЬ ПРАВ ОТКАЗ (СИГН)
   uint16_t skv_dv_left_failure      : 1; //!< [СКВ-Д026] СКВ ОТБОР ЛЕВОГО БОРТА ОТКАЗ (СИГН)
   uint16_t skv_dv_right_failure     : 1; //!< [СКВ-Д027] СКВ ОТБОР ПРАВОГО БОРТА ОТКАЗ (СИГН)
   uint16_t skv_thu1_failure         : 1; //!< [СКВ-Д028] СКВ ТХУ1 КАБИНЫ ОТКАЗ (СОСТ)
   uint16_t skv_thu2_failure         : 1; //!< [СКВ-Д029] СКВ ТХУ2 ПЕРЕДН ТО ОТКАЗ (СОСТ)
   uint16_t skv_thu3_failure         : 1; //!< [СКВ-Д030] СКВ ТХУ3 СРЕДН ТО ЛЕВ, ПЕРЕДН ГО ОТКАЗ (СОСТ)
   uint16_t skv_thu4_failure         : 1; //!< [СКВ-Д031] СКВ ТХУ4 СРЕДН ТО ПРАВ, ЗАДН ГО ОТКАЗ (СОСТ)
   uint16_t skv_thu_failure          : 1; //!< [СКВ-Д032] СКВ ТХУ ОТКАЗ / РЭП ОХЛАЖД ОТКАЗ (СИГН)
   uint16_t skv_pressure_low         : 1; //!< [СКВ-Д033] СКВ ПОДАЧИ НЕТ (СИГН)
   uint16_t skv_vsu_heating_failure  : 1; //!< [СКВ-Д036] СКВ ОБОГРЕВ ОТСЕКА ВСУ ОТКАЗ (СИГН, ВСУ)
   uint16_t skv_zto_temperature_high : 1; //!< [СКВ-Д037] СКВ ЗАДН ТО ПЕРЕГРЕВ (СИГН)
} mfci_signals_word_32_b_t;

//! Слово 33 сигнализации МФЦИ (сигналы СКВ, СОИ)
typedef struct mfci_signals_word_33_b_t {
   uint16_t cabin_high_pressure      : 1; //!< [СКВ-Д300] КАБИНА ДАВЛ ВЕЛИКО (ДВ/С, СИГН)
   uint16_t cabin_loss_pressure      : 1; //!< [СКВ-Д301] КАБИНА ДАВЛ МАЛО (ДВ/С, СИГН)
   uint16_t rtr_sap_cooling_failure  : 1; //!< [СКВ-Д035] РТР И САП ОХЛАЖД ОТКАЗ (СОСТ)
   uint16_t compare_heading          : 1; //!< [УПР-Д051] КУРС СРАВНИ (ДВ/С, СИГН)
   uint16_t compare_roll             : 1; //!< [УПР-Д052] КРЕН СРАВНИ (ДВ/С)
   uint16_t compare_pitch            : 1; //!< [УПР-Д053] ТАНГАЖ СРАВНИ (ДВ/С)
   uint16_t compare_indicated_speed  : 1; //!< [УПР-Д055] СРАВНИ ПРИБОРНУЮ СКОРОСТЬ (ДВ/С)
   uint16_t compare_altitude         : 1; //!< [УПР-Д056] СРАВНИ БАРОВЫСОТУ (ДВ/С)
   uint16_t map_failure              : 1; //!< [СОИ-Л064] КАРТА ОТКАЗ (СОСТ)
   uint16_t bgs1_failure             : 1; //!< [СОИ] ГРАФИЧ СТАНЦИЯ 1 ОТКАЗ (СОСТ)
   uint16_t bgs2_failure             : 1; //!< [СОИ] ГРАФИЧ СТАНЦИЯ 2 ОТКАЗ (СОСТ)
   uint16_t bgs_reserve_failure      : 1; //!< [СОИ-Л065] БГС РЕЗЕРВА НЕТ (СОСТ)
   uint16_t bis1_failure             : 1; //!< [СОИ] БИС1 ОТКАЗ (СОСТ)
   uint16_t bis2_failure             : 1; //!< [СОИ] БИС2 ОТКАЗ (СОСТ)
   uint16_t bis_reserve_failure      : 1; //!< [СОИ-Л066] БИС РЕЗЕРВА НЕТ (СОСТ)
   uint16_t                          : 1; //!< Резерв
} mfci_signals_word_33_b_t;

//! Слово 34 сигнализации МФЦИ (сигналы ИНС, АНС, СВС)
typedef struct mfci_signals_word_34_b_t {
   uint16_t ins1_not_nav_mode    : 1; //!< [ИНС-Д006] ИНС1 НЕ ВЫСТАВЛЕНА (СОСТ)
   uint16_t ins2_not_nav_mode    : 1; //!< [ИНС-Д007] ИНС2 НЕ ВЫСТАВЛЕНА (СОСТ)
   uint16_t ins3_not_nav_mode    : 1; //!< [ИНС-Д008] ИНС3 НЕ ВЫСТАВЛЕНА (СОСТ)
   uint16_t ins1_failure         : 1; //!< [ИНС-Л001] ИНС1 ОТКАЗ (СОСТ)
   uint16_t ins2_failure         : 1; //!< [ИНС-Л002] ИНС2 ОТКАЗ (СОСТ)
   uint16_t ins3_failure         : 1; //!< [ИНС-Л003] ИНС3 ОТКАЗ (СОСТ)
   uint16_t ins12_failure        : 1; //!< [ИНС-Л004] ИНС12 ОТКАЗ (СОСТ)
   uint16_t ins13_failure        : 1; //!< [ИНС-Л005] ИНС13 ОТКАЗ (СОСТ)
   uint16_t ins23_failure        : 1; //!< [ИНС-Л006] ИНС23 ОТКАЗ (СОСТ)
   uint16_t ins_failure          : 1; //!< [ИНС-Л007] ИНС ОТКАЗ (ДВ/С, СИГН, СОСТ)
   uint16_t ins_reserve_failure  : 1; //!< [ИНС-Л008] ИНС РЕЗЕРВА НЕТ (ДВ/С, СИГН)
   uint16_t ins_not_nav_mode     : 1; //!< [СОИ-Л102] ИНС НЕ ВЫСТАВЛ (ДВ/С, СИГН)
   uint16_t ans_not_nav_mode     : 1; //!< [АНС-Л002] АНС НЕ ВЫСТАВЛ (СОСТ)
   uint16_t ppd1_heating_failure : 1; //!< [СВС-Д004] ППД 1 ОБОГРЕВА НЕТ (СОСТ)
   uint16_t ppd2_heating_failure : 1; //!< [СВС-Д005] ППД 2 ОБОГРЕВА НЕТ (СОСТ)
   uint16_t ppd3_heating_failure : 1; //!< [СВС-Д006] ППД 3 ОБОГРЕВА НЕТ (СОСТ)
} mfci_signals_word_34_b_t;

//! Слово 35 сигнализации МФЦИ (сигналы СВС)
typedef struct mfci_signals_word_35_b_t {
   uint16_t svs1_no_correction        : 1; //!< [СВС-Д007] СВС1 НЕТ КОРРЕКЦИИ ПО ВЫСОТЕ И СКОРОСТИ (СОСТ)
   uint16_t svs2_no_correction        : 1; //!< [СВС-Д008] СВС2 НЕТ КОРРЕКЦИИ ПО ВЫСОТЕ И СКОРОСТИ (СОСТ)
   uint16_t svs3_no_correction        : 1; //!< [СВС-Д009] СВС3 НЕТ КОРРЕКЦИИ ПО ВЫСОТЕ И СКОРОСТИ (СОСТ)
   uint16_t dau_left_heating_failure  : 1; //!< [СВС-ДХХХ] ДАУ ЛЕВ ОБОГРЕВА НЕТ
   uint16_t dau_right_heating_failure : 1; //!< [СВС-ДХХХ] ДАУ ПРАВ ОБОГРЕВА НЕТ
   uint16_t svs1_failure              : 1; //!< [СВС-Л001] СВС1 ОТКАЗ (СОСТ)
   uint16_t svs2_failure              : 1; //!< [СВС-Л002] СВС2 ОТКАЗ (СОСТ)
   uint16_t svs3_failure              : 1; //!< [СВС-Л003] СВС3 ОТКАЗ (СОСТ)
   uint16_t svs12_failure             : 1; //!< [СВС-Л004] СВС12 ОТКАЗ (СОСТ)
   uint16_t svs13_failure             : 1; //!< [СВС-Л005] СВС13 ОТКАЗ (СОСТ)
   uint16_t svs23_failure             : 1; //!< [СВС-Л006] СВС23 ОТКАЗ (СОСТ)
   uint16_t svs_failure               : 1; //!< [СВС-Л007] СВС ОТКАЗ (ДВ/С, СИГН, СОСТ)
   uint16_t ppd_heating_failure_1     : 1; //!< [СВС-Л008] ППД ОБОГРЕВА НЕТ (НЕ ГОТОВ К ВЗЛЁТУ)
   uint16_t ppd_heating_failure_2     : 1; //!< [СВС-Л009] ППД ОБОГРЕВА НЕТ (ДВ/С)
   uint16_t svs_reserve_failure       : 1; //!< [СВС-Л010] СВС РЕЗЕРВА НЕТ (ДВ/С, СИГН)
   uint16_t svs_no_correction         : 1; //!< [СВС-Л011] СВС НЕТ КОРРЕКЦИИ ПО ВЫСОТЕ И СКОРОСТИ (ДВ/С, СИГН)
} mfci_signals_word_35_b_t;

//! Слово 36 сигнализации МФЦИ (сигналы КИСЛ)
typedef struct mfci_signals_word_36_b_t {
   uint16_t oxygen_50                : 1; //!< [КИСЛ-Д001] КИСЛОРОД < 50% (ДВ/С)
   uint16_t oxygen_20                : 1; //!< [КИСЛ-Д002] КИСЛОРОД < 20% (ДВ/С, СИГН)
   uint16_t oxygen_failure_1         : 1; //!< [КИСЛ-Д003] КИСЛОРОД ОТКАЗ (ДВ/С, СИГН)
   uint16_t oxygen_failure_2         : 1; //!< [КИСЛ-Д004] КИСЛОРОД ОТКАЗ (ДВ/С)
   uint16_t use_oxygen               : 1; //!< [КИСЛ-Д005] КИСЛОРОД ИСПОЛЬЗУЙ (ДВ/С, СИГН)
   uint16_t oxygen_pilot1_low        : 1; //!< [КИСЛ-Д006] КИСЛОРОДА КОМАНДИРА НЕТ (ДВ/С)
   uint16_t oxygen_pilot2_low        : 1; //!< [КИСЛ-Д007] КИСЛОРОДА ПОМОЩНИКА НЕТ (ДВ/С)
   uint16_t oxygen_operator_low      : 1; //!< [КИСЛ-Д008] КИСЛОРОДА ОПЕРАТОРА НЕТ (ДВ/С, СИГН)
   uint16_t oxygen_navigator_low     : 1; //!< [КИСЛ-Д009] КИСЛОРОДА ШТУРМАНА НЕТ (ДВ/С, СИГН)
   uint16_t oxygen_pilot1_failure    : 1; //!< [КИСЛ-Д010] КИСЛОРОД КОМАНДИРА ОТКАЗ (ДВ/С)
   uint16_t oxygen_pilot2_failure    : 1; //!< [КИСЛ-Д011] КИСЛОРОД ПОМОЩНИКА ОТКАЗ (ДВ/С)
   uint16_t oxygen_operator_failure  : 1; //!< [КИСЛ-Д012] КИСЛОРОД ОПЕРАТОРА ОТКАЗ (ДВ/С, СИГН)
   uint16_t oxygen_navigator_failure : 1; //!< [КИСЛ-Д013] КИСЛОРОД ШТУРМАНА ОТКАЗ (ДВ/С, СИГН)
   uint16_t charge_oxygen            : 1; //!< [КИСЛ-Д014] КИСЛОРОД ЗАРЯДИ (ДВ/С)
   uint16_t oxygen_on                : 1; //!< [КИСЛ-Д015] КИСЛОРОД ВКЛ (СОСТ)
   uint16_t oxygen_off               : 1; //!< [КИСЛ-Л001] КИСЛОРОД ОТКЛ (ДВ/С)
} mfci_signals_word_36_b_t;

//! Слово 37 сигнализации МФЦИ (сигналы КИСЛ, ШАСС, ЛЕД)
typedef struct mfci_signals_word_37_b_t {
   uint16_t oxygen_pilot1_pressure_normal    : 1; //!< [КИСЛ-Д017] Командир корабля - давление норма
   uint16_t oxygen_pilot1_feeding            : 1; //!< [КИСЛ-Д019] Командир корабля - подача на дыхание
   uint16_t oxygen_pilot2_pressure_normal    : 1; //!< [КИСЛ-Д020] Помощник командира - давление норма
   uint16_t oxygen_pilot2_feeding            : 1; //!< [КИСЛ-Д022] Помощник командира - подача на дыхание
   uint16_t oxygen_operator_pressure_normal  : 1; //!< [КИСЛ-Д023] Штурман-оператор - давление норма
   uint16_t oxygen_operator_feeding          : 1; //!< [КИСЛ-Д025] Штурман-оператор - подача на дыхание
   uint16_t oxygen_navigator_pressure_normal : 1; //!< [КИСЛ-Д026] Штурман-навигатор - давление норма
   uint16_t oxygen_navigator_feeding         : 1; //!< [КИСЛ-Д028] Штурман-навигатор - подача на дыхание
   uint16_t gear_front_pressure_low          : 1; //!< [ШАСС-Д016] ШАССИ ПЕРЕДН ДАВЛ МАЛО (СОСТ)
   uint16_t gear_left_pressure_low           : 1; //!< [ШАСС-Д017] ШАССИ ЛЕВ ДАВЛ МАЛО (СОСТ)
   uint16_t gear_right_pressure_low          : 1; //!< [ШАСС-Д018] ШАССИ ПРАВ ДАВЛ МАЛО (СОСТ)
   uint16_t gear_pressure_low                : 1; //!< [ШАСС-Л003] ШАССИ ДАВЛ МАЛО (ДВ/С)
   uint16_t gear_check                       : 1; //!< [ШАСС-Л004] ШАССИ ПРОВЕРЬ (ДВ/С)
   uint16_t gear_down                        : 1; //!< [ШАСС-Л005] ШАССИ ВЫПУСТИ (ДВ/С)
   uint16_t gear_locked                      : 1; //!< [ШАСС-Л006] ШАССИ УБОРКА НЕВОЗМОЖНА ЗАМОК ЗАКРЫТ (ДВ/С)
   uint16_t icing                            : 1; //!< [ЛЕД-Л001] ОБЛЕДЕНЕНИЕ (ДВ/С, СИГН)
} mfci_signals_word_37_b_t;

//! Слово 38 сигнализации МФЦИ (сигналы БЦВМ)
typedef struct mfci_signals_word_38_b_t {
   uint16_t nav_lzp_changed        : 1; //!< [БЦВМ-Д007] НАВ СМЕНА ЛЗП (ДВ/С, СИГН)
   uint16_t nav_fuel_low           : 1; //!< [БЦВМ-Д009] НАВ ФАКТИЧ ЗАПАС ТОПЛИВА НИЖЕ ТРЕБУЕМОГО (ДВ/С, СИГН)
   uint16_t nav_go_around          : 1; //!< [БЦВМ-Д010] НАВ УХОД НА 2 КРУГ (ДВ/С, СИГН)
   uint16_t br                     : 1; //!< [БЦВМ] БОЕВОЙ РЕЖИМ (ДВ/С, СИГН)
   uint16_t nav_reserve_failure    : 1; //!< [БЦВМ-Д018] НАВ СЧИСЛЕН РЕЗЕРВА НЕТ (СОСТ)
   uint16_t nav_route_failure      : 1; //!< [БЦВМ-Д019] НАВ МАРШРУТ ОТКАЗ (СОСТ)
   uint16_t nav_return             : 1; //!< [БЦВМ-Д027] НАВ ВОЗВРАТ (ДВ/С, СИГН)
   uint16_t nav_failure            : 1; //!< [БЦВМ-Д028] НАВ СЧИСЛЕН ОТКАЗ (ДВ/С, СИГН)
   uint16_t bvd1_failure           : 1; //!< [БЦВМ] БВД1 ОТКАЗ (СОСТ)
   uint16_t bvd2_failure           : 1; //!< [БЦВМ] БВД2 ОТКАЗ (СОСТ)
   uint16_t dangerous_approach     : 1; //!< [ФПО НО-Б001] ГРУП ДИСТАНЦИЯ ОПАСНАЯ (ДВ/С, СИГН)
   uint16_t ur_failure             : 1; //!< [БЦВМ-Л001] ПУСК УР ОТКАЗ (ДВ/С, СИГН)
   uint16_t ur_reserve_failure     : 1; //!< [БЦВМ-Л002] ПУСК УР РЕЗЕРВА НЕТ (СОСТ)
   uint16_t unit_task_corr_failure : 1; //!< [БЦВМ-Л063] КОРР ЗАДАНИЯ ИЗД ОТКАЗ (СОСТ)
   uint16_t bcvm1_bp_failure       : 1; //!< [БЦВМ] БЦВМ1 БП ОТКАЗ
   uint16_t bcvm2_bp_failure       : 1; //!< [БЦВМ] БЦВМ2 БП ОТКАЗ
} mfci_signals_word_38_b_t;

//! Слово 38 сигнализации МФЦИ (сигналы БЦВМ, РЭП)
typedef struct mfci_signals_word_39_b_t {
   uint16_t bcvm1_unit_task_corr_failure : 1; //!< [БЦВМ] БЦВМ1 КОРР ЗАДАНИЯ ОТКАЗ
   uint16_t bcvm2_unit_task_corr_failure : 1; //!< [БЦВМ] БЦВМ2 КОРР ЗАДАНИЯ ОТКАЗ
   uint16_t bcvm1_kans_failure           : 1; //!< [БЦВМ] БЦВМ1 КЭНС ОТКАЗ
   uint16_t bcvm2_kans_failure           : 1; //!< [БЦВМ] БЦВМ2 КЭНС ОТКАЗ
   uint16_t rap_attack_left              : 1; //!< [РЭП-Б007] РЭП АТАКА СЛЕВА (ДВ/С)
   uint16_t rap_attack_right             : 1; //!< [РЭП-Б005] РЭП АТАКА СПРАВА (ДВ/С)
   uint16_t rap_attack_below             : 1; //!< [РЭП-Д003] РЭП АТАКА СНИЗУ (ДВ/С)
   uint16_t rap_attack_above             : 1; //!< [РЭП-Д004] РЭП АТАКА СВЕРХУ (ДВ/С)
   uint16_t rap_attack_front             : 1; //!< [РЭП-Б004] РЭП АТАКА СПЕРЕДИ (ДВ/С)
   uint16_t rap_attack_rear              : 1; //!< [РЭП-Б006] РЭП АТАКА СЗАДИ (ДВ/С)
   uint16_t rap_guidance                 : 1; //!< [РЭП-Б011] РЭП НАВЕДЕНИЕ
   uint16_t rap_tracking                 : 1; //!< [РЭП-Б010] РЭП СОПРОВОЖДЕНИЕ
   uint16_t rap_failure                  : 1; //!< [РЭП-Б753] РЭП ОТКАЗ (ДВ/С, СИГН)
   uint16_t rap_finder_failure           : 1; //!< [РЭП-Д007] РЭП ТЕПЛОПЕЛЕНГАТОР ОТКАЗ (СОСТ)
   uint16_t rap_lazer_failure            : 1; //!< [РЭП-Д008] РЭП ЛАЗЕРНАЯ СИСТЕМА ОТКАЗ (СОСТ)
   uint16_t rap_uv_valves_failure        : 1; //!< [СТВР-Д001] РЭП СТВОРКИ УВ-5 ОТКАЗ (СОСТ)
} mfci_signals_word_39_b_t;

//! Слово 40 сигнализации МФЦИ (сигналы РЭП, К070)
typedef struct mfci_signals_word_40_b_t {
   uint16_t rap_uv_failure         : 1; //!< [РЭП-Д009] РЭП УВ ОТКАЗ (СОСТ)
   uint16_t rap_recv_failure       : 1; //!< [РЭП-Д010] РЭП ПРИЕМНИК РТР ОТКАЗ (СОСТ)
   uint16_t rap_sender_failure     : 1; //!< [РЭП-Б756] РЭП ПЕРЕДАТЧИК ОТКАЗ (СОСТ)
   uint16_t rap_recv_left_failure  : 1; //!< [РЭП-Б768] РЭП ЛЕВ ПРИЕМНЫЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_recv_right_failure : 1; //!< [РЭП-Б777] РЭП ПРАВ ПРИЕМНЫЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_recv_rear_failure  : 1; //!< [РЭП-Б786] РЭП ЗАДН ПРИЕМНЫЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_send_front_failure : 1; //!< [РЭП-Б794] РЭП ПЕРЕДН ПЕРЕДАЮЩИЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_send_left_failure  : 1; //!< [РЭП-Б799] РЭП ЛЕВ ПЕРЕДАЮЩИЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_send_right_failure : 1; //!< [РЭП-Б811] РЭП ПРАВ ПЕРЕДАЮЩИЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_send_rear_failure  : 1; //!< [РЭП-Б823] РЭП ЗАДН ПЕРЕДАЮЩИЙ ПОСТ ОТКАЗ (СОСТ)
   uint16_t rap_unit1_failure      : 1; //!< [РЭП-Б703] РЭП ИЗД1 ОТКАЗ (СОСТ)
   uint16_t rap_unit2_failure      : 1; //!< [РЭП-Б722] РЭП ИЗД2 ОТКАЗ (СОСТ)
   uint16_t rap_unit5_failure      : 1; //!< [РЭП-Б737] РЭП ИЗД5 ОТКАЗ (СОСТ)
   uint16_t fire_emergency         : 1; //!< [К070-Д001] СБРОСЬ ГРУЗ АВАРИЙНО (ДВ/С, СИГН)
   uint16_t tsp_spec_on            : 1; //!< [К070-Д002] ТСП/СПЕЦ ВКЛЮЧИ (ДВ/С, СИГН)
   uint16_t tsp_spec_off           : 1; //!< [К070-Д003] ТСП/СПЕЦ ОТКЛЮЧИ (ДВ/С, СИГН)
} mfci_signals_word_40_b_t;

//! Слово 41 сигнализации МФЦИ (сигналы К070, БАСУ, ФОВБ, 19ДА)
typedef struct mfci_signals_word_41_b_t {
   uint16_t open_go                 : 1; //!< [К070-Д004] СТВОРКИ ПГО И ЗГО ОТКРОЙ ВРУЧНУЮ (СИГН)
   uint16_t close_go                : 1; //!< [К070-Д005] СТВОРКИ ПГО И ЗГО ЗАКРОЙ ВРУЧНУЮ (СИГН)
   uint16_t suo_failure             : 1; //!< [К070-Д006] СУО ОТКАЗ (ДВ/С, СИГН)
   uint16_t kav_failure             : 1; //!< [К070-Д007] КАВ ОТКАЗ (ДВ/С, СИГН)
   uint16_t suo_landing_not_ready_1 : 1; //!< [СУО-Д006] СУО ПОСАДКА ЗАПРЕЩЕНА, ДВИГАТЕЛЬ ВЫПУЩЕН (ДВ/С)
   uint16_t suo_landing_not_ready_2 : 1; //!< [СУО-Д007] СУО ПОСАДКА ЗАПРЕЩЕНА, СТВОРКИ ОТКРЫТЫ (ДВ/С)
   uint16_t asu_message             : 1; //!< [АСУ-Д001] АСУ СООБЩЕНИЕ ПРИМИ (ДВ/С, СИГН)
   uint16_t asu_failure             : 1; //!< [АСУ-Д003] АСУ ОТКАЗ (ДВ/С, СИГН)
   uint16_t asu_check_route         : 1; //!< [АСУ-Д008] АСУ МАРШРУТ ПРОВЕРЬ (ДВ/С, СИГН)
   uint16_t asu_check_bz            : 1; //!< [АСУ-Д006] АСУ БЗ ПРОВЕРЬ (ДВ/С, СИГН)
   uint16_t asu_lock_weapon         : 1; //!< [АСУ-Д007] АСУ ЗАБЛОКИРУЙ ОРУЖИЕ (ДВ/С, СИГН)
   uint16_t asu_report              : 1; //!< [АСУ-Д011] АСУ ДОНЕСЕНИЕ ВЫДАНО (ДВ/С, СИГН)
   uint16_t urpz_onbz_preparing     : 1; //!< [УРПЗ-Д001] ИДЕТ ФОРМИРОВАНИЕ ОНБЗ, время - XX:XX (ДВ/С, СИГН)
   uint16_t contrail_check          : 1; //!< [ФОВБ-Д001] ВИХРЬ ПРОВЕРЬ (ДВ/С)
   uint16_t bks_weapon_enabled      : 1; //!< [С505-Д001] РАЗБЛОКИРОВКА ОРУЖИЯ (ДВ/С, СИГН)
   uint16_t                         : 1; //!< Резерв
} mfci_signals_word_41_b_t;

//! Слово 42 сигнализации МФЦИ (сигналы МФИ)
typedef struct mfci_signals_word_42_b_t {
   uint16_t mfi01_reserve : 1; //!< [МФИ-Д001] МФИ1 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi02_reserve : 1; //!< [МФИ-Д002] МФИ2 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi03_reserve : 1; //!< [МФИ-Д003] МФИ3 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi04_reserve : 1; //!< [МФИ-Д004] МФИ4 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi05_reserve : 1; //!< [МФИ-Д005] МФИ5 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi06_reserve : 1; //!< [МФИ-Д006] МФИ6 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi07_reserve : 1; //!< [МФИ-Д007] МФИ7 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi08_reserve : 1; //!< [МФИ-Д008] МФИ8 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi09_reserve : 1; //!< [МФИ-Д009] МФИ9 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi10_reserve : 1; //!< [МФИ-Д010] МФИ10 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi11_reserve : 1; //!< [МФИ-Д011] МФИ11 РЕЗЕРВ РЕЖИМ (СОСТ)
   uint16_t mfi01_failure : 1; //!< [МФИ-Д012] МФИ1 ОТКАЗ (СОСТ)
   uint16_t mfi02_failure : 1; //!< [МФИ-Д013] МФИ2 ОТКАЗ (СОСТ)
   uint16_t mfi03_failure : 1; //!< [МФИ-Д014] МФИ3 ОТКАЗ (СОСТ)
   uint16_t mfi04_failure : 1; //!< [МФИ-Д015] МФИ4 ОТКАЗ (СОСТ)
   uint16_t mfi05_failure : 1; //!< [МФИ-Д016] МФИ5 ОТКАЗ (СОСТ)
} mfci_signals_word_42_b_t;

//! Слово 43 сигнализации МФЦИ (сигналы МФИ, МФПУ, ЛЮКИ)
typedef struct mfci_signals_word_43_b_t {
   uint16_t mfi06_failure    : 1; //!< [МФИ-Д017] МФИ6 ОТКАЗ (СОСТ)
   uint16_t mfi07_failure    : 1; //!< [МФИ-Д018] МФИ7 ОТКАЗ (СОСТ)
   uint16_t mfi08_failure    : 1; //!< [МФИ-Д019] МФИ8 ОТКАЗ (СОСТ)
   uint16_t mfi09_failure    : 1; //!< [МФИ-Д020] МФИ9 ОТКАЗ (СОСТ)
   uint16_t mfi10_failure    : 1; //!< [МФИ-Д021] МФИ10 ОТКАЗ (СОСТ)
   uint16_t mfi11_failure    : 1; //!< [МФИ-Д022] МФИ11 ОТКАЗ (СОСТ)
   uint16_t mfpu1_failure    : 1; //!< [МФПУ1-Д001] МФПУ1 ОТКАЗ (СОСТ)
   uint16_t mfpu2_failure    : 1; //!< [МФПУ2-Д001] МФПУ2 ОТКАЗ (СОСТ)
   uint16_t mfpu3_failure    : 1; //!< [МФПУ3-Д001] МФПУ3 ОТКАЗ (СОСТ)
   uint16_t depressurization : 1; //!< [ЛЮКИ-Л001*] ЛЮКИ ГЕРМЕТ ОТКАЗ (ДВ/С, СИГН)
   uint16_t canopy_1         : 1; //!< [ЛЮКИ-Л001] ФОНАРЬ ОТКРЫТ (НЕ ГОТОВ К ВЗЛЁТУ, СИГН)
   uint16_t canopy_pilot_1   : 1; //!< [ЛЮКИ-Л002] ФОНАРЬ КК ОТКРЫТ (СОСТ)
   uint16_t canopy_pilot_2   : 1; //!< [ЛЮКИ-Л003] ФОНАРЬ ПКК ОТКРЫТ (СОСТ)
   uint16_t canopy_navigator : 1; //!< [ЛЮКИ-Л004] ФОНАРЬ ШК ОТКРЫТ (СОСТ)
   uint16_t canopy_operator  : 1; //!< [ЛЮКИ-Л005] ФОНАРЬ ШО ОТКРЫТ (СОСТ)
   uint16_t canopy_2         : 1; //!< [ЛЮКИ-Л006] ФОНАРЬ ОТКРЫТ (ДВ/С)
} mfci_signals_word_43_b_t;

//! Слово 44 сигнализации МФЦИ (отказы систем)
typedef struct mfci_signals_word_44_b_t {
   uint16_t pui1_failure     : 1; //!< [ПУИ1-Д001] ПУИ1 ОТКАЗ (СОСТ)
   uint16_t pui2_failure     : 1; //!< [ПУИ2-Д001] ПУИ2 ОТКАЗ (СОСТ)
   uint16_t mup1_failure     : 1; //!< [МУП1-Д001] МУП1 ОТКАЗ (СОСТ)
   uint16_t mup2_failure     : 1; //!< [МУП2-Д001] МУП2 ОТКАЗ (СОСТ)
   uint16_t vim1_failure     : 1; //!< [VIM1-Д001] VIM1: ILS, VOR ОТКАЗ (СОСТ)
   uint16_t vim2_failure     : 1; //!< [VIM2-Д001] VIM2: ILS, VOR ОТКАЗ (СОСТ)
   uint16_t rvm1_failure     : 1; //!< [РВМ1-Д001] РВм1 ОТКАЗ (СОСТ)
   uint16_t rvm2_failure     : 1; //!< [РВМ2-Д001] РВм2 ОТКАЗ (СОСТ)
   uint16_t rvb_failure      : 1; //!< [РВБ-Д001] РВб ОТКАЗ (СОСТ)
   uint16_t sd75_1_failure   : 1; //!< [DME1-Д001] ДАЛЬНОМЕР1 ОТКАЗ (СОСТ)
   uint16_t sd75_2_failure   : 1; //!< [DME2-Д001] ДАЛЬНОМЕР2 ОТКАЗ (СОСТ)
   uint16_t rsbn_failure     : 1; //!< [РСБН-Д006] РСБН ОТКАЗ (СОСТ)
   uint16_t ans_failure      : 1; //!< [АНС-Д001] АНС ОТКАЗ (СОСТ)
   uint16_t ans_true_heading : 1; //!< [АНС-Л001] МФИ КУРС ИСТИННЫЙ ОТ АНС (ДВ/С, СИГН)
   uint16_t diss_failure     : 1; //!< [ДИСС] ДИСС ОТКАЗ (СОСТ)
   uint16_t diss_memory      : 1; //!< [ДИСС-Д001] ДИСС ПАМЯТЬ (СОСТ)
} mfci_signals_word_44_b_t;

//! Слово 45 сигнализации МФЦИ (отказы систем)
typedef struct mfci_signals_word_45_b_t {
   uint16_t ark_failure                  : 1; //!< [АРК-Д001]  АРК ОТКАЗ (СОСТ)
   uint16_t sev_failure                  : 1; //!< [СЕВ-Д001]  СЕВ ОТКАЗ (СОСТ)
   uint16_t abd_failure                  : 1; //!< [АБД-Д001]  АБД ОТКАЗ (СОСТ)
   uint16_t bask_failure                 : 1; //!< [БАСК-Д001] БАСК ОТКАЗ (СОСТ)
   uint16_t rls_failure                  : 1; //!< [РЛС-Д001]  РЛС ОТКАЗ (ДВ/С, СИГН)
   uint16_t msrp_zbn1_failure            : 1; //!< [МСРП-Д001] МСРП ЗБН1 ОТКАЗ (СОСТ)
   uint16_t msrp_zbn2_failure            : 1; //!< [МСРП-Д002] МСРП ЗБН2 ОТКАЗ (СОСТ)
   uint16_t msrp_bspi_failure            : 1; //!< [МСРП-Д003] МСРП БСПИ ОТКАЗ (СОСТ)
   uint16_t msrp_pusn_failure            : 1; //!< [МСРП-Д004] МСРП ПУ СН ОТКАЗ (СОСТ)
   uint16_t svr_failure                  : 1; //!< [СВР-Д001]  СВР ОТКАЗ (СОСТ)
   uint16_t kvr_failure                  : 1; //!< [КВР] КВР ОТКАЗ (ДВ/С, СИГН)
   uint16_t front_shield_heating_failure : 1; //!< [ОБОГ-Д001] СТЕКЛО ЛОБОВОЕ ОТКАЗ ОБОГРЕВ ОТКЛЮЧИ (ДВ/С)
   uint16_t right_shield_heating_failure : 1; //!< [ОБОГ-Д002] СТЕКЛО ПРАВОЕ ОТКАЗ ОБОГРЕВ ОТКЛЮЧИ (ДВ/С)
   uint16_t left_shield_heating_failure  : 1; //!< [ОБОГ-Д003] СТЕКЛО ЛЕВОЕ ОТКАЗ ОБОГРЕВ ОТКЛЮЧИ (ДВ/С)
   uint16_t raft_failure                 : 1; //!< [ПЛОТ-Д001] ПЛОТ ОТКАЗ (СОСТ)
   uint16_t radiation                    : 1; //!< [РАД-Д001] РАДИАЦИЯ (ДВ/С, СИГН)
} mfci_signals_word_45_b_t;

//! Слово 46 сигнализации МФЦИ (отказы систем)
typedef struct mfci_signals_word_46_b_t {
   uint16_t bis_kans_failure         : 1; //!< [ИУС-Л001] БИС КЭНС ОТКАЗ (СОСТ)
   uint16_t ubvr_ems_failure         : 1; //!< [УБВР-Д019] УБВР ОБЕСПЕЧЕНИЕ ЭМС ОТКАЗ (СОСТ)
   uint16_t uks1_failure             : 1; //!< [УКС-Д003] КОНЦЕНТРАТОР СИГНАЛОВ 1 ОТКАЗ (СОСТ)
   uint16_t uks2_failure             : 1; //!< [УКС-Д004] КОНЦЕНТРАТОР СИГНАЛОВ 2 ОТКАЗ (СОСТ)
   uint16_t uks3_failure             : 1; //!< [УКС-Д005] КОНЦЕНТРАТОР СИГНАЛОВ 3 ОТКАЗ (СОСТ)
   uint16_t uks4_failure             : 1; //!< [УКС-Д006] КОНЦЕНТРАТОР СИГНАЛОВ 4 ОТКАЗ (СОСТ)
   uint16_t uks_analog_failure       : 1; //!< [УКС-Д007] КОНЦЕНТРАТОР АНАЛОГ СИГНАЛОВ ОТКАЗ (СОСТ)
   uint16_t uks_rk_failure           : 1; //!< [УКС-Д008] КОНЦЕНТРАТОР РАЗОВЫХ КОМАНД ОТКАЗ (СОСТ)
   uint16_t uks_unreserved           : 1; //!< [УКС-Д009] КОНЦЕНТРАТОР СИГНАЛОВ РЕЗЕРВА НЕТ (ДВ/С)
   uint16_t uks_parametric_failure   : 1; //!< [УКС-Д010] КОНЦЕНТРАТОР СИГНАЛОВ ИНФОРМ ОТКАЗ (ДВ/С)
   uint16_t uks_tar_available        : 1; //!< [ТАР] Доступность тарировки УКС
   uint16_t front_boost_pressure_low : 1; //!< [НАД-Д001] НАДДУВ БЛОКОВ ДАВЛ МАЛО ПЕРЕДН (СОСТ)
   uint16_t rear_boost_pressure_low  : 1; //!< [НАД-Д002] НАДДУВ БЛОКОВ ДАВЛ МАЛО ЗАДН (СОСТ)
   uint16_t chute_failure            : 1; //!< [ПРШТ-Д001] ПАРАШЮТ ОТКАЗ (ДВ/С)
   uint16_t chute_cut                : 1; //!< [ПРШТ-Д002] ПАРАШЮТ СБРОШЕН (ДВ/С)
   uint16_t chute_dragged            : 1; //!< [ПРШТ-Д003] ПАРАШЮТ ВЫПУЩЕН (ДВ/С)
} mfci_signals_word_46_b_t;

//! Слово 47 сигнализации МФЦИ (сигналы СПЗ)
typedef struct mfci_signals_word_47_b_t {
   uint16_t dv1_fire             : 1; //!< [СПЗ-Л005] ДВ1 ПОЖАР (ДВ/С, СИГН)
   uint16_t dv1_overheating      : 1; //!< [СПЗ-Л001] ДВ1 ПЕРЕГРЕВ (ДВ/С, СИГН)
   uint16_t dv1_rud_low_down     : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, УСТАНОВИ РУД ДВ1 НА МГ (ДВ/С)
   uint16_t dv1_close_stop_valve : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ СТОП-КРАН ДВ1 (ДВ/С)
   uint16_t dv1_close_fire_cock  : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ ПК1 (ДВ/С)
   uint16_t dv1_press_dvig       : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ДВИГ1 (ДВ/С)
   uint16_t dv1_press_strike_1   : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 1 (ДВ/С)
   uint16_t dv1_press_strike_2   : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 2 (ДВ/С)
   uint16_t dv1_press_strike_3   : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 3 (ДВ/С)
   uint16_t dv1_turn_off_gen_1   : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 1 (ДВ/С)
   uint16_t dv1_turn_off_gen_2   : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 1 (СИГН)
   uint16_t dv1_turn_off_bleed_1 : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ1 (ДВ/С)
   uint16_t dv1_turn_off_bleed_2 : 1; //!< [СПЗ] ДВ1 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ1 (СИГН)
   uint16_t dv2_fire             : 1; //!< [СПЗ-Л006] ДВ2 ПОЖАР (ДВ/С, СИГН)
   uint16_t dv2_overheating      : 1; //!< [СПЗ-Л002] ДВ2 ПЕРЕГРЕВ (ДВ/С, СИГН)
   uint16_t dv2_rud_low_down     : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, УСТАНОВИ РУД ДВ2 НА МГ (ДВ/С)
} mfci_signals_word_47_b_t;

//! Слово 48 сигнализации МФЦИ (сигналы СПЗ)
typedef struct mfci_signals_word_48_b_t {
   uint16_t dv2_close_stop_valve : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ СТОП-КРАН ДВ2 (ДВ/С)
   uint16_t dv2_close_fire_cock  : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ ПК2 (ДВ/С)
   uint16_t dv2_press_dvig       : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ДВИГ2 (ДВ/С)
   uint16_t dv2_press_strike_1   : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 1 (ДВ/С)
   uint16_t dv2_press_strike_2   : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 2 (ДВ/С)
   uint16_t dv2_press_strike_3   : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 3 (ДВ/С)
   uint16_t dv2_turn_off_gen_1   : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 2 (ДВ/С)
   uint16_t dv2_turn_off_gen_2   : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 2 (СИГН)
   uint16_t dv2_turn_off_bleed_1 : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ2 (ДВ/С)
   uint16_t dv2_turn_off_bleed_2 : 1; //!< [СПЗ] ДВ2 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ2 (СИГН)
   uint16_t dv3_fire             : 1; //!< [СПЗ-Л007] ДВ3 ПОЖАР (ДВ/С, СИГН)
   uint16_t dv3_overheating      : 1; //!< [СПЗ-Л003] ДВ3 ПЕРЕГРЕВ (ДВ/С, СИГН)
   uint16_t dv3_rud_low_down     : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, УСТАНОВИ РУД ДВ3 НА МГ (ДВ/С)
   uint16_t dv3_close_stop_valve : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ СТОП-КРАН ДВ3 (ДВ/С)
   uint16_t dv3_close_fire_cock  : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ ПК3 (ДВ/С)
   uint16_t dv3_press_dvig       : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ДВИГ3 (ДВ/С)
} mfci_signals_word_48_b_t;

//! Слово 49 сигнализации МФЦИ (сигналы СПЗ)
typedef struct mfci_signals_word_49_b_t {
   uint16_t dv3_press_strike_1   : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 1 (ДВ/С)
   uint16_t dv3_press_strike_2   : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 2 (ДВ/С)
   uint16_t dv3_press_strike_3   : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 3 (ДВ/С)
   uint16_t dv3_turn_off_gen_1   : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 3 (ДВ/С)
   uint16_t dv3_turn_off_gen_2   : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 3 (СИГН)
   uint16_t dv3_turn_off_bleed_1 : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ3 (ДВ/С)
   uint16_t dv3_turn_off_bleed_2 : 1; //!< [СПЗ] ДВ3 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ3 (СИГН)
   uint16_t dv4_fire             : 1; //!< [СПЗ-Л008] ДВ4 ПОЖАР (ДВ/С, СИГН)
   uint16_t dv4_overheating      : 1; //!< [СПЗ-Л004] ДВ4 ПЕРЕГРЕВ (ДВ/С, СИГН)
   uint16_t dv4_rud_low_down     : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, УСТАНОВИ РУД ДВ4 НА МГ (ДВ/С)
   uint16_t dv4_close_stop_valve : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ СТОП-КРАН ДВ4 (ДВ/С)
   uint16_t dv4_close_fire_cock  : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, ЗАКРОЙ ПК4 (ДВ/С)
   uint16_t dv4_press_dvig       : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ДВИГ4 (ДВ/С)
   uint16_t dv4_press_strike_1   : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 1 (ДВ/С)
   uint16_t dv4_press_strike_2   : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 2 (ДВ/С)
   uint16_t dv4_press_strike_3   : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, НАЖМИ ОЧЕРЕДЬ 3 (ДВ/С)
} mfci_signals_word_49_b_t;

//! Слово 50 сигнализации МФЦИ (сигналы СПЗ, РАД, БЦВМ, НО)
typedef struct mfci_signals_word_50_b_t {
   uint16_t dv4_turn_off_gen_1   : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 4 (ДВ/С)
   uint16_t dv4_turn_off_gen_2   : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ГЕНЕРАТОРЫ 4 (СИГН)
   uint16_t dv4_turn_off_bleed_1 : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ4 (ДВ/С)
   uint16_t dv4_turn_off_bleed_2 : 1; //!< [СПЗ] ДВ4 ПОЖАР/ПЕРЕГРЕВ, ОТКЛЮЧИ ОТБОР ОТ ДВ4 (СИГН)
   uint16_t vsu_fire             : 1; //!< [СПЗ-Л009] ВСУ ПОЖАР (ДВ/С, СИГН)
   uint16_t vsu_press_stop       : 1; //!< [СПЗ] ВСУ ПОЖАР, НАЖМИ ОСТАНОВ ВСУ (СИГН)
   uint16_t vsu_turn_off_gen     : 1; //!< [СПЗ] ВСУ ПОЖАР, ОТКЛЮЧИ ГЕНЕРАТОР ВСУ (СИГН)
   uint16_t vsu_press_strike_1   : 1; //!< [СПЗ] ВСУ ПОЖАР, НАЖМИ ОЧЕРЕДЬ 1 (СИГН)
   uint16_t vsu_press_strike_2   : 1; //!< [СПЗ] ВСУ ПОЖАР, НАЖМИ ОЧЕРЕДЬ 2 (СИГН)
   uint16_t vsu_press_strike_3   : 1; //!< [СПЗ] ВСУ ПОЖАР, НАЖМИ ОЧЕРЕДЬ 3 (СИГН)
   uint16_t bcvm_sel_course      : 1; //!< [БЦВМ-Д006] ЗК РУЧН (ПЛАН)
   uint16_t bcvm_to_point        : 1; //!< [БЦВМ-Д011] ПРЯМО НА (ПЛАН)
   uint16_t bcvm_route_shift     : 1; //!< [БЦВМ-Д012] СМЕЩ МАРШ (ПЛАН)
   uint16_t bcvm_orbit_left      : 1; //!< [БЦВМ-Д013] ОРБИТА ЛЕВ (ПЛАН)
   uint16_t bcvm_orbit_right     : 1; //!< [БЦВМ-Д014] ОРБИТА ПРАВ (ПЛАН)
   uint16_t bcvm_waiting_zone    : 1; //!< [БЦВМ-Д015] ЗОНА ОЖ (ПЛАН)
} mfci_signals_word_50_b_t;

//! Слово 51 сигнализации МФЦИ (сигналы БЦВМ, НО)
typedef struct mfci_signals_word_51_b_t {
   uint16_t bcvm_reverse_route     : 1; //!< [БЦВМ-Д023] РЕВЕРС МАРШ (ПЛАН)
   uint16_t bcvm_teardrop          : 1; //!< [БЦВМ-Д029] ОТВОРОТ НА РУ (ПЛАН)
   uint16_t bcvm_azimuth_to_rsbn   : 1; //!< [БЦВМ-Д031] АЗИМУТ НА РСБН (ПЛАН)
   uint16_t bcvm_azimuth_from_rsbn : 1; //!< [БЦВМ-Д032] АЗИМУТ ОТ РСБН (ПЛАН)
   uint16_t bcvm_azimuth_to_vor1   : 1; //!< [БЦВМ-Д033] АЗИМУТ НА VOR1 (ПЛАН)
   uint16_t bcvm_azimuth_from_vor1 : 1; //!< [БЦВМ-Д034] АЗИМУТ ОТ VOR1 (ПЛАН)
   uint16_t bcvm_azimuth_to_vor2   : 1; //!< [БЦВМ-Д035] АЗИМУТ НА VOR2 (ПЛАН)
   uint16_t bcvm_azimuth_from_vor2 : 1; //!< [БЦВМ-Д036] АЗИМУТ ОТ VOR2 (ПЛАН)
   uint16_t bcvm_sel_track_angle   : 1; //!< [БЦВМ-Д037] ЗПУ РУЧН (ПЛАН)
   uint16_t bcvm_sel_time_maneuver : 1; //!< [БЦВМ-Д038] ВЫХ Тзад (ПОГАШЕНИЕ dt, ПЛАН)
   uint16_t bcvm_sel_roll_right    : 1; //!< [БЦВМ-Д039] ВИРАЖ ПРАВ (ПЛАН)
   uint16_t bcvm_turn              : 1; //!< [БЦВМ-Д040] СТАНД РАЗВ (ПЛАН)
   uint16_t bcvm_inverted_turn     : 1; //!< [БЦВМ-Д041] ОБР СТАНД РАЗВ (ПЛАН)
   uint16_t bcvm_tacking           : 1; //!< [БЦВМ-Д042] ГАЛСИРОВАНИЕ (ПЛАН)
   uint16_t bcvm_shuttle           : 1; //!< [БЦВМ-Д043] ЧЕЛНОК (ПЛАН)
   uint16_t bcvm_landing_pattern   : 1; //!< [БЦВМ-Д044] БК (ПЛАН)
} mfci_signals_word_51_b_t;

//! Слово 52 сигнализации МФЦИ (сигналы БЦВМ, НО, ПБД, БГС)
typedef struct mfci_signals_word_52_b_t {
   uint16_t bcvm_sel_roll_left     : 1; //!< [БЦВМ-Д045] ВИРАЖ ЛЕВ (ПЛАН)
   uint16_t bcvm_takeoff_rud_65    : 1; //!< [БЦВМ-Д050] ВЗЛЕТ АЛЬФА РУД = 65 (ДВ/С)
   uint16_t bcvm_takeoff_rud_72    : 1; //!< [БЦВМ-Д051] ВЗЛЕТ АЛЬФА РУД = 72 (ДВ/С)
   uint16_t bcvm_takeoff_rud_85    : 1; //!< [БЦВМ-Д052] ВЗЛЕТ АЛЬФА РУД = 85 (ДВ/С)
   uint16_t bcvm_takeoff_rud_95    : 1; //!< [БЦВМ-Д053] ВЗЛЕТ АЛЬФА РУД = 95 (ДВ/С)
   uint16_t bcvm_takeoff_rud_115   : 1; //!< [БЦВМ-Д054] ВЗЛЕТ АЛЬФА РУД = 115 (ДВ/С)
   uint16_t bvd_compare_pbd        : 1; //!< [БВД] ПБД СРАВНИ (СОСТ)
   uint16_t bvd_compare_nd1        : 1; //!< [БВД] НД1 СРАВНИ (СОСТ)
   uint16_t bvd_compare_nd2        : 1; //!< [БВД] НД2 СРАВНИ (СОСТ)
   uint16_t bvd_compare_nd3        : 1; //!< [БВД] НД3 СРАВНИ (СОСТ)
   uint16_t bvd_compare_nd4        : 1; //!< [БВД] НД4 СРАВНИ (СОСТ)
   uint16_t bgs1_failure           : 1; //!< [МФИ] Отказ БГС1
   uint16_t bgs2_failure           : 1; //!< [МФИ] Отказ БГС2
   uint16_t                        : 3; //!< Резерв
} mfci_signals_word_52_b_t;

//! Слово 53 сигнализации МФЦИ (сигналы НГ, СНС, СУПК)
typedef struct mfci_signals_word_53_b_t {
   uint16_t tanks_pressure_low         : 1; //!< [НГ-Д001] РАЗРЕЖЕН БАКОВ ВЕЛИКО (ДВ/С)
   uint16_t pressurization_high        : 1; //!< [НГ-Д002] НАДДУВ БАКОВ ВЕЛИК (ДВ/С)
   uint16_t pressurization_low         : 1; //!< [НГ-Д003] НАДДУВ БАКОВ МАЛ (ДВ/С)
   uint16_t pressurization_failure     : 1; //!< [НГ-Д004] НАДДУВ БАКОВ ОТКАЗ (ДВ/С)
   uint16_t nitrogen_low               : 1; //!< [НГ-Д005] ТОПЛ АЗОТА НЕТ (ДВ/С)
   uint16_t sns_failure                : 1; //!< [СНС-Л002] ПНАП ОТКАЗ (СОСТ)
   uint16_t sns_glns_failure           : 1; //!< [СНС-Л003] ПНАП ГЛНС ОТКАЗ (СОСТ)
   uint16_t sns_srns_failure           : 1; //!< [СНС-Л004] ПНАП СРНС ОТКАЗ (СОСТ)
   uint16_t sns_ifrns_failure          : 1; //!< [СНС-Л005] ПНАП ИФРНС ОТКАЗ (СОСТ)
   uint16_t steering_no_conrol         : 1; //!< [СУПК-Л001] ПОВОРОТ КОЛЕС САМООРИЕНТ (ДВ/С)
   uint16_t taxing                     : 1; //!< [СУПК-Л002] КОЛЕСА РУЛЕНИЕ (ДВ/С, НЕ ГОТОВ К ВЗЛЁТУ)
   uint16_t steering_channel_1_failure : 1; //!< [СУПК-Л003] ПОВОРОТ КОЛЕС КАНАЛ 1 ОТКАЗ (СОСТ)
   uint16_t steering_channel_2_failure : 1; //!< [СУПК-Л004] ПОВОРОТ КОЛЕС КАНАЛ 2 ОТКАЗ (СОСТ)
   uint16_t                            : 3; //!< Резерв
} mfci_signals_word_53_b_t;

//! Слово 54 сигнализации МФЦИ (сигналы САС/ЦСО)
typedef struct mfci_signals_word_54_b_t {
   uint16_t ius_sound_failure          : 1; //!< [СОИ-Л004] ИУС ЗВУК СИГН ОТКАЗ (ДВ/С, СИГН)
   uint16_t ius_cso_failure            : 1; //!< [СОИ-Л005] ИУС ЦСО ОТКАЗ (ДВ/С, СИГН)
   uint16_t ius_sound_reserve_failure  : 1; //!< [СОИ-Л006] ИУС ИУС ЗВУК СИГН РЕЗЕРВА НЕТ (СОСТ)
   uint16_t ius_cso_reserve_failure    : 1; //!< [СОИ-Л007] ИУС ИУС ЦСО РЕЗЕРВА НЕТ (СОСТ)
   uint16_t sas_failure_pilot_1        : 1; //!< [САС-Л001] САС КОМАНДИРА СИГН НЕДОСТОВЕРНА (СОСТ)
   uint16_t sas_failure_pilot_2        : 1; //!< [САС-Л002] САС ПОМОЩНИКА СИГН НЕДОСТОВЕРНА (СОСТ)
   uint16_t sas_failure_operator       : 1; //!< [САС-Л003] САС ОПЕРАТОРА СИГН НЕДОСТОВЕРНА (СОСТ)
   uint16_t sas_failure_navigator      : 1; //!< [САС-Д009] САС ШТУРМАНА СИГН НЕДОСТОВЕРНА (СОСТ)
   uint16_t sas_clear_pilot_1          : 1; //!< [САС] Отбой ЦСО № 1 КК (ЦСО летчика 1 нажата)
   uint16_t sas_clear_pilot_2          : 1; //!< [САС] Отбой ЦСО № 2 ПКК (ЦСО летчика 2 нажата)
   uint16_t sas_clear_operator         : 1; //!< [САС] Отбой ЦСО № 3 ШО (ЦСО штурмана-оператора нажата)
   uint16_t sas_clear_navigator        : 1; //!< [САС] Отбой ЦСО № 4 ШК (ЦСО штурмана-навигатора нажата)
   uint16_t                            : 4; //!< Резерв
} mfci_signals_word_54_b_t;

//! Слово 1 сигналов 19-ДА
typedef struct u19_flag_word_1_b_t {
   uint16_t healthy           : 1; //!< Наличие достоверных данных от 19-ДА
   uint16_t rear_mpu_position : 3; //!< Номер нижней позиции в заднем грузоотсеке на МПУ //(min:1 max:6)
   uint16_t unit1_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 1 (в заднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit2_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 2 (в заднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit3_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 3 (в заднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit4_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 4 (в заднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit5_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 5 (в заднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit6_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 6 (в заднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
} u19_flag_word_1_b_t;

//! Слово 2 сигналов 19-ДА
typedef struct u19_flag_word_2_b_t {
   uint16_t front_mpu_position : 4; //!< Номер нижней позиции в переднем грузоотсеке на МПУ //(min:7 max:12)
   uint16_t unit7_status       : 2; //!< Состояние разблокировки изделия на точке подвеса 7 (в переднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit8_status       : 2; //!< Состояние разблокировки изделия на точке подвеса 8 (в переднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit9_status       : 2; //!< Состояние разблокировки изделия на точке подвеса 9 (в переднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit10_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 10 (в переднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit11_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 11 (в переднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
   uint16_t unit12_status      : 2; //!< Состояние разблокировки изделия на точке подвеса 12 (в переднем грузоотсеке, 0 - нет данных, 1 - заблокировано, 2 - разблокировано) //(min:0 max:2)
} u19_flag_word_2_b_t;

//! Слово 3 сигналов 19-ДА
typedef struct u19_flag_word_3_b_t {
   uint16_t weapon_enabled : 1;  //!< [19ДА] Разблокировано
   uint16_t tsp            : 1;  //!< [19ДА] ТСП снято
   uint16_t                : 14; //!< Резерв
} u19_flag_word_3_b_t;

//! Слово 1 сигналов АБСУ
typedef struct absu_flag_word_1_b_t {
   uint16_t fin_fail_1        : 1; //!< [АБСУ-Д001] Рулевые агрегаты киля канал 1 отказ
   uint16_t fin_fail_2        : 1; //!< [АБСУ-Д002] Рулевые агрегаты киля канал 2 отказ
   uint16_t fin_fail_3        : 1; //!< [АБСУ-Д003] Рулевые агрегаты киля канал 3 отказ
   uint16_t fin_fail_4        : 1; //!< [АБСУ-Д004] Рулевые агрегаты киля канал 4 отказ
   uint16_t stab_fail_1       : 1; //!< [АБСУ-Д005] Рулевые агрегаты стабилизатора канал 1 отказ
   uint16_t stab_fail_2       : 1; //!< [АБСУ-Д006] Рулевые агрегаты стабилизатора канал 2 отказ
   uint16_t stab_fail_3       : 1; //!< [АБСУ-Д007] Рулевые агрегаты стабилизатора канал 3 отказ
   uint16_t stab_fail_4       : 1; //!< [АБСУ-Д008] Рулевые агрегаты стабилизатора канал 4 отказ
   uint16_t spoiler_l_fail_1  : 1; //!< [АБСУ-Д009] Рулевые агрегаты левых интерцепторов канал 1 отказ
   uint16_t spoiler_l_fail_2  : 1; //!< [АБСУ-Д010] Рулевые агрегаты левых интерцепторов канал 2 отказ
   uint16_t spoiler_l_fail_3  : 1; //!< [АБСУ-Д011] Рулевые агрегаты левых интерцепторов канал 3 отказ
   uint16_t spoiler_r_fail_1  : 1; //!< [АБСУ-Д012] Рулевые агрегаты правых интерцепторов канал 1 отказ
   uint16_t spoiler_r_fail_2  : 1; //!< [АБСУ-Д013] Рулевые агрегаты правых интерцепторов канал 2 отказ
   uint16_t spoiler_r_fail_3  : 1; //!< [АБСУ-Д014] Рулевые агрегаты правых интерцепторов канал 3 отказ
   uint16_t flaperon_l_fail_1 : 1; //!< [АБСУ-Д015] Рулевые агрегаты левого флаперона канал 1 отказ
   uint16_t flaperon_l_fail_2 : 1; //!< [АБСУ-Д016] Рулевые агрегаты левого флаперона канал 2 отказ
} absu_flag_word_1_b_t;

//! Слово 2 сигналов АБСУ
typedef struct absu_flag_word_2_b_t {
   uint16_t flaperon_l_fail_3       : 1; //!< [АБСУ-Д017] Рулевые агрегаты левого флаперона канал 3 отказ
   uint16_t flaperon_r_fail_1       : 1; //!< [АБСУ-Д018] Рулевые агрегаты правого флаперона канал 1 отказ
   uint16_t flaperon_r_fail_2       : 1; //!< [АБСУ-Д019] Рулевые агрегаты правого флаперона канал 2 отказ
   uint16_t flaperon_r_fail_3       : 1; //!< [АБСУ-Д020] Рулевые агрегаты правого флаперона канал 3 отказ
   uint16_t neutral_course          : 1; //!< [АБСУ-Д021] Нейтраль по курсу
   uint16_t neutral_roll            : 1; //!< [АБСУ-Д022] Нейтраль по крену
   uint16_t dz_off                  : 1; //!< [АБСУ-Д025] Отключение дополнительного загружателя тангажа
   uint16_t rut_valid               : 1; //!< [АБСУ-Д061] Достоверность сигнала положения РУТ
   uint16_t pedals_position_failure : 1; //!< [АБСУ-Д062] Отказ сигнала положения педалей
   uint16_t srb_opened              : 1; //!< [АБСУ-Д064] Шторка ШРБ открыта
   uint16_t interc_rus_valid        : 1; //!< [АБСУ-Д074] Достоверность сигнала положения РУС для интерцепторов
   uint16_t flaperon_rus_valid      : 1; //!< [АБСУ-Д075] Достоверность сигнала положения РУС для флаперонов
   uint16_t pedals_position_valid   : 1; //!< [АБСУ-Д076] Достоверность сигнала положения педалей
   uint16_t braking_failed          : 1; //!< [АБСУ-Д077] Отказ торможения интерцепторами
   uint16_t                         : 2; //!< Резерв
} absu_flag_word_2_b_t;

//! Заголовок АСУ (слово данных 1)
typedef struct asu_header_word_1_b_t {
   uint16_t segment_crc_low; //!< Младшая часть контрольной суммы сегмента (CRC-32) //(min:0 max:4294967295 bits:4..19 lsb:1)
} asu_header_word_1_b_t;

//! Заголовок АСУ (слово данных 2)
typedef struct asu_header_word_2_b_t {
   uint16_t segment_crc_high; //!< Старшая часть контрольной суммы сегмента (CRC-32) //(min:0 max:4294967295 bits:4..19 lsb:1)
} asu_header_word_2_b_t;

//! Заголовок АСУ (слово данных 3)
typedef struct asu_header_word_3_b_t {
   uint16_t sender_id    : 6; //!< Уникальный идентификационный номер системы отправителя (2-ФПО БАСУ, 6-ФПО СОИ) //(min:1 max:17)
   uint16_t receiver_id  : 6; //!< Уникальный идентификационный номер системы получателя (2-ФПО БАСУ, 6-ФПО СОИ) //(min:1 max:17)
   uint16_t unit_id      : 3; //!< Уникальный идентификационный номер изделия отправителя (2-БЦВМ, 6-МФЦИ1070, 7-МФЦИ1570) //(min:1 max:7)
   uint16_t last_segment : 1; //!< Признак последнего сегмента
} asu_header_word_3_b_t;

//! Заголовок АСУ (слово данных 4)
typedef struct asu_header_word_4_b_t {
   uint16_t ga_module      : 4; //!< Номер КФМ отправителя //(min:0 max:10)
   uint16_t number_contour : 2; //!< Номер контура //(min:0 max:3)
   uint16_t mfpu_linked    : 1; //!< Активно подключение МФПУ к МФЦИ (передаётся из МФЦИ в БЦВМ)
   uint16_t                : 1; //!< Резерв
   uint16_t data_type      : 8; //!< Тип данных (3-взаимодействие СОИ с БАСУ) //(min:0 max:8)
} asu_header_word_4_b_t;

//! Заголовок АСУ (слово данных 5)
typedef struct asu_header_word_5_b_t {
   uint16_t segment_number; //!< Номер передаваемого сегмента (нумерация с нуля) //(min:0 max:255 bits:4..19 lsb:1)
} asu_header_word_5_b_t;

//! Заголовок АСУ (слово данных 6)
typedef struct asu_header_word_6_b_t {
   uint16_t message_id; //!< Идентификатор сообщения //(min:1 max:65535 bits:4..19 lsb:1)
} asu_header_word_6_b_t;

//! Заголовок АСУ (слово данных 7, вариант для передачи данных из БЦВМ в МФЦИ)
typedef struct asu_header_word_7_in_b_t {
   uint16_t mfpu_linked_1  : 1; //!< Активно подключение МФПУ к МФЦИ № 1
   uint16_t mfpu_linked_2  : 1; //!< Активно подключение МФПУ к МФЦИ № 2
   uint16_t mfpu_linked_3  : 1; //!< Активно подключение МФПУ к МФЦИ № 3
   uint16_t mfpu_linked_4  : 1; //!< Активно подключение МФПУ к МФЦИ № 4
   uint16_t mfpu_linked_5  : 1; //!< Активно подключение МФПУ к МФЦИ № 5
   uint16_t mfpu_linked_6  : 1; //!< Активно подключение МФПУ к МФЦИ № 6
   uint16_t mfpu_linked_7  : 1; //!< Активно подключение МФПУ к МФЦИ № 7
   uint16_t mfpu_linked_8  : 1; //!< Активно подключение МФПУ к МФЦИ № 8
   uint16_t mfpu_linked_9  : 1; //!< Активно подключение МФПУ к МФЦИ № 9
   uint16_t mfpu_linked_10 : 1; //!< Активно подключение МФПУ к МФЦИ № 10
   uint16_t mfpu_linked_11 : 1; //!< Активно подключение МФПУ к МФЦИ № 11
   uint16_t                : 5; //!< Резерв
} asu_header_word_7_in_b_t;

//! Заголовок АСУ (слово данных 7, вариант для передачи данных из МФЦИ в БЦВМ)
typedef struct asu_header_word_7_out_b_t {
   uint16_t segments_count; //!< Количество сегментов //(min:0 max:255 bits:4..19 lsb:1)
} asu_header_word_7_out_b_t;

//! Заголовок АСУ (слово данных 8)
typedef struct asu_header_word_8_b_t {
   uint16_t segment_size; //!< Размер сегмента //(min:1 max:48 bits:4..19 lsb:1)
} asu_header_word_8_b_t;

//! Слово 1 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_1_b_t {
   uint16_t hit_time_low; //!< [БП-504/506-А001] Заданное время удара, младшие 16 разрядов //(min:0 max:86399 lsb:1 с)
} bp_50x_aur1_flag_word_1_b_t;

//! Слово 2 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_2_b_t {
   uint16_t hit_time_high         : 1; //!< [БП-504/506-А001] Заданное время удара, старший 17-й разряд
   uint16_t show_hit_time         : 1; //!< [БП-504/506-Д001] Отображать заданное время удара
   uint16_t show_enter_time       : 1; //!< [БП-504/506-Д003] Отображать заданное время прохода самолетом передней границы РЗП/ОРЗП
   uint16_t show_prepare_time_rem : 1; //!< [БП-504/506-Д006] Отображать оставшееся время до прохода передней границы РЗП/ОРЗП
   uint16_t standalone_path       : 1; //!< [БП-504/506-Д010] Выполнение автономного полета
   uint16_t route_loaded          : 1; //!< [БП-504/506-Д013] Боевое задание загружено
   uint16_t fire_mode             : 3; //!< [БП-504/506-А014] Режим подготовки изделий (1-боевой, 2-имитация, 3-ППП, 4-имитация на земле) //(min:0 max:4)
   uint16_t prepare_mode          : 3; //!< [БП-504/506-А015] Вариант выставки изделий (1-змейка/прав, 2-змейка/лев, 3-поворот МПУ, 4-орт.прав, 5-орт.лев. 6-запуск в воздухе) //(min:0 max:6)
   uint16_t show_speed_correction : 1; //!< [БП-504/506-Д018] Отображать рекомендуемое изменение воздушной скорости для выхода в РЗП/ОРЗП
   uint16_t show_redundant_time   : 1; //!< [БП-504/506-Д022] Отображать избыток времени при выходе в РЗП/ОРЗП
   uint16_t track_angle_active    : 1; //!< [БП-504/506-Д029.1] Режим ЗПУ
   uint16_t course_active         : 1; //!< [БП-504/506-Д029.2] Режим ЗК
} bp_50x_aur1_flag_word_2_b_t;

//! Слово 3 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_3_b_t {
   uint16_t enter_time_low; //!< [БП-504/506-А003] Заданное время прохода самолетом передней границы РЗП/ОРЗП, младшие 16 разрядов //(min:0 max:86399 lsb:1 с)
} bp_50x_aur1_flag_word_3_b_t;

//! Слово 4 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_4_b_t {
   uint16_t enter_time_high    : 1; //!< [БП-504/506-А003] Заданное время прохода самолетом передней границы РЗП/ОРЗП, старший 17-й разряд
   uint16_t rear_mpu_position  : 3; //!< [БП-504/506-А036.1] Номер нижней позиции в заднем грузоотсеке на МПУ //(min:1 max:6)
   uint16_t front_mpu_position : 4; //!< [БП-504/506-А036.2] Номер нижней позиции в переднем грузоотсеке на МПУ //(min:7 max:12)
   uint16_t main_message       : 3; //!< [БП-504/506-А038] Сообщение "Главный" (1-АСУ пуск не разрешен, 2-включи Главный (проблеск), 3-включи ТСП (проблеск), 4-отключи ТСП, 5-отключи Главный) //(min:0 max:5)
   uint16_t unit_1_status      : 5; //!< [БП-504/506-А037.1] Состояние изделия 1 (0 - нет изделия) //(min:0 max:21)
} bp_50x_aur1_flag_word_4_b_t;

//! Слово 5 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_5_b_t {
   uint16_t unit_2_status : 5; //!< [БП-504/506-А037.2] Состояние изделия 2 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_3_status : 5; //!< [БП-504/506-А037.3] Состояние изделия 3 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_4_status : 5; //!< [БП-504/506-А037.4] Состояние изделия 4 (0 - нет изделия) //(min:0 max:21)
   uint16_t               : 1; //!< Резерв
} bp_50x_aur1_flag_word_5_b_t;

//! Слово 6 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_6_b_t {
   uint16_t unit_5_status : 5; //!< [БП-504/506-А037.5] Состояние изделия 5 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_6_status : 5; //!< [БП-504/506-А037.6] Состояние изделия 6 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_7_status : 5; //!< [БП-504/506-А037.7] Состояние изделия 7 (0 - нет изделия) //(min:0 max:21)
   uint16_t               : 1; //!< Резерв
} bp_50x_aur1_flag_word_6_b_t;

//! Слово 7 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_7_b_t {
   uint16_t unit_8_status  : 5; //!< [БП-504/506-А037.8] Состояние изделия 8 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_9_status  : 5; //!< [БП-504/506-А037.9] Состояние изделия 9 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_10_status : 5; //!< [БП-504/506-А037.10] Состояние изделия 10 (0 - нет изделия) //(min:0 max:21)
   uint16_t                : 1; //!< Резерв
} bp_50x_aur1_flag_word_7_b_t;

//! Слово 8 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_8_b_t {
   uint16_t unit_11_status   : 5; //!< [БП-504/506-А037.11] Состояние изделия 11 (0 - нет изделия) //(min:0 max:21)
   uint16_t unit_12_status   : 5; //!< [БП-504/506-А037.12] Состояние изделия 12 (0 - нет изделия) //(min:0 max:21)
   uint16_t enter_accuracy   : 3; //!< [БП-504/506-А049] Точность входа в РЗП/ОРЗП (1-попадает в зону, 2-следует слева, 3-следует справа, 4-вошел, 5-прошел слева, 6-прошел справа) //(min:0 max:6)
   uint16_t align_scale_type : 3; //!< [БП-504/506-А060] Тип шкалы динамического процесса (0-нет, 1-БЗ, 2-РВП, 3-ГИС, 4-змейка, 5-МПУ, 6-орт., 7-запуск в воздухе) //(min:0 max:7)
} bp_50x_aur1_flag_word_8_b_t;

//! Слово 9 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_9_b_t {
   uint16_t rzp_coords_message : 1; //!< [БП-504/506-А050] Область координат РЗП (0-нет, 1-координаты РЗП)
   uint16_t message_1l         : 2; //!< [БП-504/506-А054.1] Строка 1 левая (0-нет, 1-выставка, 2-дежурный, 3-обогрев) //(min:0 max:3)
   uint16_t message_1m         : 3; //!< [БП-504/506-А055.1] Строка 1 по центру (0-нет, 1/4-гор.полет, 2-макс глав, 3-время ОУ, 5-маневр пр, 6-маневр лев) //(min:0 max:6)
   uint16_t message_1r         : 2; //!< [БП-504/506-А056] Строка 1 правая (0-нет, 1-БЗ невыполнимо, 2-ОСП невыполним, 3-Ту невыполнимо) //(min:0 max:3)
   uint16_t message_2l         : 2; //!< [БП-504/506-А057.1] Строка 2 левая (0-нет, 1-створки ПГО, 2-створки ПГО (проблеск), 3-Ту рекомендуемое) //(min:0 max:3)
   uint16_t message_2m         : 3; //!< [БП-504/506-А058.1] Строка 2 по центру (0-нет, 1-до отцепки, 2-до выставки, 3-контроль, 4-ввод ПЗ) //(min:0 max:4)
   uint16_t message_2r         : 2; //!< [БП-504/506-А059] Строка 2 правая (0-нет, 1-створки ЗГО, 2-створки ЗГО (проблеск), 3-включи траекторию) //(min:0 max:3)
   uint16_t                    : 1; //!< Резерв
} bp_50x_aur1_flag_word_9_b_t;

//! Слово 10 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_10_b_t {
   uint16_t asu_hit_time_low; //!< [БП-504/506-А068.2] Время удара к подсказке зоны 3 стр. 1 "Назначь ТУ", младшие 16 разрядов //(min:0 max:86399 lsb:1 с)
} bp_50x_aur1_flag_word_10_b_t;

//! Слово 11 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_11_b_t {
   uint16_t asu_hit_time_high   : 1;  //!< [БП-504/506-А068.2] Время удара к подсказке зоны 3 стр. 1 "Назначь ТУ", старший 17-й разряд
   uint16_t message_2m_time_rem : 13; //!< [БП-504/506-А058.2] Оставшееся время для строки 2 по центру //(min:0 max:5999 lsb:1 с)
   uint16_t show_rzp            : 1;  //!< [БП-504/506-Д112] Отображать РЗП/ОРЗП
   uint16_t                     : 1;  //!< Резерв
} bp_50x_aur1_flag_word_11_b_t;

//! Слово 12 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_12_b_t {
   uint16_t message_2l_hit_time_low; //!< [БП-504/506-А057.2] Рекомендуемое время удара, младшие 16 разрядов //(min:0 max:86399 lsb:1 с)
} bp_50x_aur1_flag_word_12_b_t;

//! Слово 13 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_13_b_t {
   uint16_t message_2l_hit_time_high : 1; //!< [БП-504/506-А057.2] Рекомендуемое время удара, старший 17-й разряд
   uint16_t align_value_bz_rvp       : 7; //!< [БП-504/506-А061.1] Состояние загрузки БЗ / расчета ОУ и РВП (%) //(min:0 max:100)
   uint16_t align_value_mark         : 7; //!< [БП-504/506-А062] Положение метки готовности Тоу на шкале РВП (%) //(min:0 max:100)
   uint16_t                          : 1; //!< Резерв
} bp_50x_aur1_flag_word_13_b_t;

//! Слово 14 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_14_b_t {
   uint16_t mach_value      : 7; //!< [БП-504/506-А068.3] Число Маха к подсказке зоны 3 страницы 1 "Увеличь М" //(min:0.4 max:0.78 lsb:0.01)
   uint16_t select_bz       : 1; //!< [БП-504/506-Д068.1] Назначь БЗ (АСУ)
   uint16_t select_hit_time : 1; //!< [БП-504/506-Д068.2] Назначь время удара (АСУ)
   uint16_t bz_cancelled    : 1; //!< [БП-504/506-Д068.3] Отмени БЗ (АСУ)
   uint16_t bz_missed       : 1; //!< [БП-504/506-Д068.4] В БД нет БЗ (АСУ)
   uint16_t mpu_locked      : 1; //!< [БП-504/506-Д068.5] Запрет повортота МПУ на 5 минут
   uint16_t set_roll_5      : 1; //!< [БП-504/506-Д068.6] Уменьши крен до 5°
   uint16_t set_pitch_5     : 1; //!< [БП-504/506-Д068.7] Установи тангаж от -5° до +15°
   uint16_t set_mach_08     : 1; //!< [БП-504/506-Д068.8] Уменьши число Маха до 0.8
   uint16_t mach            : 1; //!< [БП-504/506-Д068.9] Увеличь число Маха
} bp_50x_aur1_flag_word_14_b_t;

//! Слово 15 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_15_b_t {
   uint16_t alt_up           : 1; //!< [БП-504/506-Д068.10] Увеличь высоту
   uint16_t alt_down         : 1; //!< [БП-504/506-Д068.11] Уменьши высоту
   uint16_t wrong_unit_type  : 1; //!< [БП-504/506-Д068.12] Тип изделия не соответствует БЗ
   uint16_t drop_fail        : 1; //!< [БП-504/506-Д068.13] Зависло
   uint16_t emergency_drop   : 1; //!< [БП-504/506-Д068.14] Аварийный сброс нижнего изделия
   uint16_t pz_cancelled     : 1; //!< [БП-504/506-Д068.15] Отмена нескольких ПЗ (АСУ)
   uint16_t rear_spus_fail   : 1; //!< [БП-504/506-Д068.16] Отказ СПУС заднего грузоотсека
   uint16_t front_spus_fail  : 1; //!< [БП-504/506-Д068.17] Отказ СПУС переднего грузоотсека
   uint16_t rear_fail        : 1; //!< [БП-504/506-Д068.18] Отказ заднего грузоотсека
   uint16_t front_fail       : 1; //!< [БП-504/506-Д068.19] Отказ переднего грузоотсека
   uint16_t rear_mpu_fail    : 1; //!< [БП-504/506-Д068.20] Отказ МПУ заднего грузоотсека
   uint16_t front_mpu_fail   : 1; //!< [БП-504/506-Д068.21] Отказ МПУ переднего грузоотсека
   uint16_t rear_skv_manual  : 1; //!< [БП-504/506-Д068.22] Ручное управление СКВ заднего грузоотсека
   uint16_t front_skv_manual : 1; //!< [БП-504/506-Д068.23] Ручное управление СКВ переднего грузоотсека
   uint16_t wrong_bz         : 1; //!< [БП-504/506-Д068.24] Некорректное БЗ
   uint16_t bz_loading_fail  : 1; //!< [БП-504/506-Д068.25] Сбой загрузки БЗ
} bp_50x_aur1_flag_word_15_b_t;

//! Слово 16 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_16_b_t {
   uint16_t load_route         : 1; //!< [БП-504/506-Д068.26] Введи БЗ
   uint16_t check_units        : 1; //!< [БП-504/506-Д068.27] Проверь включение изделий
   uint16_t set_hit_time       : 1; //!< [БП-504/506-Д068.28] Введи время удара
   uint16_t set_orzp           : 1; //!< [БП-504/506-Д068.29] Назначь ОРЗП после расчета РВП
   uint16_t set_align_mode     : 1; //!< [БП-504/506-Д068.30] Включи режим подготовки
   uint16_t rear_spus_res      : 1; //!< [БП-504/506-Д068.31] Резервный канал СПУС заднего грузоотсека
   uint16_t front_spus_res     : 1; //!< [БП-504/506-Д068.32] Резервный канал СПУС переднего грузоотсека
   uint16_t mode_finished      : 1; //!< [БП-504/506-Д068.33] Конец режима
   uint16_t bz_loading_message : 1; //!< [БП-504/506-А066.1] Подсказка о загрузке ПЗ в СУО (0-нет, 1-загрузка ПЗ)
   uint16_t bz_loading_percent : 7; //!< [БП-504/506-А066.2] Процент загрузки ПЗ в СУО (0…100 %)
} bp_50x_aur1_flag_word_16_b_t;

//! Слово 17 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_17_b_t {
   uint16_t unit_type_bz : 2; //!< [БП-504/506-А069] Тип изделия, записанного в БЗ (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_1_type  : 2; //!< [БП-504/506-А070.1] Тип изделия 1 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_2_type  : 2; //!< [БП-504/506-А070.2] Тип изделия 2 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_3_type  : 2; //!< [БП-504/506-А070.3] Тип изделия 3 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_4_type  : 2; //!< [БП-504/506-А070.4] Тип изделия 4 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_5_type  : 2; //!< [БП-504/506-А070.5] Тип изделия 5 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_6_type  : 2; //!< [БП-504/506-А070.6] Тип изделия 6 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_7_type  : 2; //!< [БП-504/506-А070.7] Тип изделия 7 (0-не определен, 1-504, 2-506) //(min:0 max:2)
} bp_50x_aur1_flag_word_17_b_t;

//! Слово 18 сигналов БП-504/506 (из раздела 1 АУР)
typedef struct bp_50x_aur1_flag_word_18_b_t {
   uint16_t unit_8_type     : 2; //!< [БП-504/506-А070.8] Тип изделия 8 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_9_type     : 2; //!< [БП-504/506-А070.9] Тип изделия 9 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_10_type    : 2; //!< [БП-504/506-А070.10] Тип изделия 10 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_11_type    : 2; //!< [БП-504/506-А070.11] Тип изделия 11 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t unit_12_type    : 2; //!< [БП-504/506-А070.12] Тип изделия 12 (0-не определен, 1-504, 2-506) //(min:0 max:2)
   uint16_t rzp_points_type : 2; //!< [БП-504/506-А071] Наличие данных о координатах точек "A" и "B" РЗП/ОРЗП (0-нет, 1-РЗП, 2-ОРЗП) //(min:0 max:2)
   uint16_t show_trk_button : 1; //!< [БП-504/506-Д100] Доступность кнопки "ТРК"
   uint16_t inside_zone     : 1; //!< [БП-504/506-Д101] Подсказка "В зоне"
   uint16_t                 : 2; //!< Резерв
} bp_50x_aur1_flag_word_18_b_t;

//! Слово 1 сигналов инициализации исполняемой/предлагаемой траектории БП-504/506 (из раздела 1 АУР)
typedef struct mfci_in_suo_50x_path_flag_word_1_b_t {
   uint16_t path_type                  : 2; //!< [БП-504/506-А124.1/А125.1] Тип траектории (0-нет, 1-РЗП, 2-ОСП) //(min:0 max:2)
   uint16_t distance_type              : 2; //!< [БП-504/506-А124.13/А125.13] Тип индицируемого расстояния (1-Sг, 2-Z) //(min:0 max:2)
   uint16_t points_count               : 4; //!< [БП-504/506-А124.3/А125.3] Количество точек //(min:0 max:15)
   uint16_t prepare_start_point_number : 4; //!< [БП-504/506-А124.7/А125.7] Номер рубежа начала выставки (0-нет) //(min:0 max:15)
   uint16_t ready_point_number         : 4; //!< [БП-504/506-А124.8/А125.8] Номер рубежа готовности изделий (0-нет) //(min:0 max:15)
} mfci_in_suo_50x_path_flag_word_1_b_t;

//! Слово 2 сигналов инициализации исполняемой/предлагаемой траектории БП-504/506 (из раздела 1 АУР)
typedef struct mfci_in_suo_50x_path_flag_word_2_b_t {
   uint16_t tnr_point_number              : 4; //!< [БП-504/506-А124.9/А125.9] Номер точки ТНР (0-нет) //(min:0 max:15)
   uint16_t nbp_point_number              : 4; //!< [БП-504/506-А124.10/А125.10] Номер начала боевого пути НБП (0-нет) //(min:0 max:15)
   uint16_t show_rzp_start_point_distance : 1; //!< [БП-504/506-Д124/Д125] Достоверность расстояния до передней границы РЗП ("А")
   uint16_t show_redundant_values_rzp     : 1; //!< [БП-504/506-Д103] Достоверность рекомендуемого изменения скорости и времени при выходе в РЗП/ОРЗП (только для предлагаемой ТРК)
   uint16_t hit_time_fail                 : 1; //!< [БП-504/506-Д115] Невыполнение времени удара (только для предлагаемой ТРК)
   uint16_t                               : 5; //!< Резерв
} mfci_in_suo_50x_path_flag_word_2_b_t;

//! Слово сигналов траектории в режиме автономного полета СУО-504/506 (из раздела 1 АУР)
typedef struct mfci_in_suo_50x_trk_ap_flag_word_b_t {
   uint16_t show_waypoint_distance : 1;  //!< [БП-504/506-Д138] Достоверность расстояния до очередного ППМ
   uint16_t show_delta_z           : 1;  //!< [БП-504/506-Д140] Достоверность линейного бокового уклонения от линии заданного пути
   uint16_t                        : 14; //!< Резерв
} mfci_in_suo_50x_trk_ap_flag_word_b_t;

//! Слово 1 сигналов БП-504/506 (из раздела 2 АУР)
typedef struct bp_50x_aur2_flag_word_1_b_t {
   uint16_t osp_outer_points_count : 8; //!< [БП-504/506-А117] Количество точек контура ОСП //(min:0 max:135)
   uint16_t osp_inner_points_count : 6; //!< [БП-504/506-А117.4] Количество точек рубежа начала пусков ОСП //(min:0 max:45)
   uint16_t rvp_proj_valid         : 1; //!< [БП-504/506-Д200] Достоверность параметров гномонической проекции в кадре 3
   uint16_t                        : 1; //!< Резерв
} bp_50x_aur2_flag_word_1_b_t;

//! Слово 2 сигналов БП-504/506 (из раздела 2 АУР)
typedef struct bp_50x_aur2_flag_word_2_b_t {
   uint16_t bp_point_start_number : 8; //!< [БП-504/506-А201.1] Номер ППМ начала боевого участка в маршруте от ФПО НО //(min:1 max:150)
   uint16_t bp_point_end_number   : 8; //!< [БП-504/506-А201.2] Номер ППМ окончания боевого участка в маршруте от ФПО НО //(min:1 max:150)
} bp_50x_aur2_flag_word_2_b_t;

//! Слово 3 сигналов БП-504/506 (из раздела 2 АУР)
typedef struct bp_50x_aur2_flag_word_3_b_t {
   uint16_t rvp_valid                : 1; //!< [БП-504/506-Д208.1] РВП рассчитан
   uint16_t rvp_side                 : 1; //!< [БП-504/506-Д208.2] Расположение РВП (0-слева, 1-справа)
   uint16_t rvp_loading              : 1; //!< [БП-504/506-Д208.3] Перезагрузка РВП
   uint16_t cursor_type              : 1; //!< [БП-504/506-Д215.1] Управление курсором от МФПУ (0 - от МФЦИ, 1 - от МФПУ)
   uint16_t ti_reset                 : 1; //!< [БП-504/506-Д215.2] Сброс ТИ в положение по умолчанию
   uint16_t prepare_end_point_number : 8; //!< [БП-504/506-А216.1] Номер ППМ в маршруте от ФПО НО, после которого расположен рубеж передней границы РЗП //(min:1 max:150)
   uint16_t show_prepare_end_point   : 1; //!< [БП-504/506-Д216] Отображать рубеж передней границы РЗП на стр.3
   uint16_t orzp_shifts_type         : 2; //!< [БП-504/506-А218] Тип отображения поля сдвигов (0-нет, 1-серым, 2-по кнопке ОРЗП) //(min:0 max:2)
} bp_50x_aur2_flag_word_3_b_t;

//! Слово-идентификатор передаваемой группы участков траектории БП-504/506
typedef struct bp_path_id_b_t {
   uint16_t start_number : 4; //!< Номер первого элемента в массиве передаваемой группы участков траектории //(min:1 max:15 lsb:1)
   uint16_t leg_1_type   : 2; //!< [БП-504/506-А124/А125.6] Тип участка 1 (0-прямая, 1-дуга против часовой, 2-дуга по часовой) //(min:0 max:2)
   uint16_t leg_2_type   : 2; //!< [БП-504/506-А124/А125.6] Тип участка 2 (0-прямая, 1-дуга против часовой, 2-дуга по часовой) //(min:0 max:2)
   uint16_t leg_3_type   : 2; //!< [БП-504/506-А124/А125.6] Тип участка 3 (0-прямая, 1-дуга против часовой, 2-дуга по часовой) //(min:0 max:2)
   uint16_t leg_4_type   : 2; //!< [БП-504/506-А124/А125.6] Тип участка 4 (0-прямая, 1-дуга против часовой, 2-дуга по часовой) //(min:0 max:2)
   uint16_t leg_5_type   : 2; //!< [БП-504/506-А124/А125.6] Тип участка 5 (0-прямая, 1-дуга против часовой, 2-дуга по часовой) //(min:0 max:2)
   uint16_t              : 2; //!< Резерв
} bp_path_id_b_t;

//! Слово 1 количества АСП в точках контура ОСП БП-504/506 (из раздела 2 АУР)
typedef struct bp_50x_osp_units_count_1_b_t {
   uint16_t count_1 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 1 фрагмента массива точек контура ОСП //(min:0 max:11)
   uint16_t count_2 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 2 фрагмента массива точек контура ОСП //(min:0 max:11)
   uint16_t count_3 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 3 фрагмента массива точек контура ОСП //(min:0 max:11)
   uint16_t count_4 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 4 фрагмента массива точек контура ОСП //(min:0 max:11)
} bp_50x_osp_units_count_1_b_t;

//! Слово 2 количества АСП в точках контура ОСП БП-504/506 (из раздела 2 АУР)
typedef struct bp_50x_osp_units_count_2_b_t {
   uint16_t count_5 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 5 фрагмента массива точек контура ОСП //(min:0 max:11)
   uint16_t count_6 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 6 фрагмента массива точек контура ОСП //(min:0 max:11)
   uint16_t count_7 : 4; //!< [БП-504/506-А117.3] Количество АСП в точке 7 фрагмента массива точек контура ОСП //(min:0 max:11)
   uint16_t         : 4; //!< Резерв
} bp_50x_osp_units_count_2_b_t;

//! Координаты географической точки БП-504/506
typedef struct mfci_bp_coord_b_t {
   uint16_t lat_high; //!< Широта, старшее слово //(min:-324000 max:324000 signed:4 bits:5..19 lsb:0.001")
   uint16_t lat_low;  //!< Широта, младшее слово
   uint16_t lon_high; //!< Долгота, старшее слово //(min:-648000 max:648000 signed:4 bits:5..19 lsb:0.001")
   uint16_t lon_low;  //!< Долгота, младшее слово
} mfci_bp_coord_b_t;

//! Описание запретной или опасной зоны БП-504/506
typedef struct mfci_bp_area_b_t {
   uint16_t last_point_number : 9; //!< [БП-504/506-А129.2] Номер последней вершины зоны (0-завершение массива зон) //(min:1 max:256)
   uint16_t type              : 1; //!< [БП-504/506-Д129] Тип зоны (0-запретная, 1-опасная)
   uint16_t                   : 6; //!< Резерв
} mfci_bp_area_b_t;

//! Координаты точки РВП на косой гномонической проекции БП-504/506
typedef struct mfci_bp_rvp_point_b_t {
   uint16_t x; //!< Координата на оси x проекции (рад, ЦСР переменная) //(min:-32767 max:32767 signed:4 bits:5..19 lsb:1)
   uint16_t y; //!< Координата на оси y проекции (рад, ЦСР переменная) //(min:-32767 max:32767 signed:4 bits:5..19 lsb:1)
} mfci_bp_rvp_point_b_t;

//! Описание полигона РВП БП-504/506
typedef struct mfci_bp_rvp_polygon_b_t {
   uint16_t last_point_number : 11; //!< [БП-504/506-А208.2] Номер последней вершины полигона (0-завершение массива полигонов) //(min:1 max:1500)
   uint16_t color             : 4;  //!< [БП-504/506-А208.3] Цвет полигона (0-черный, 1-красный, 3-желтый, 11-серый, 12-бирюзовый) //(min:0 max:12)
   uint16_t                   : 1;  //!< Резерв
} mfci_bp_rvp_polygon_b_t;

//! Слово 1 сигналов БЦВМ
typedef struct bcvm_flag_word_1_b_t {
   uint16_t course_magn_selected  : 1; //!< [БЦВМ-Д001] Выбран магнитный курс (вместо истинного)
   uint16_t vnav_active           : 1; //!< [БЦВМ-Д002] Режим вертикальной навигации выполняется
   uint16_t route                 : 1; //!< [БЦВМ-Д017] Полет по активному маршруту
   uint16_t show_orto_coords      : 1; //!< [БЦВМ-Д030] Индикация места самолета в прямоугольной системе координат относительно торца ВПП взлета (посадки)
   uint16_t koi_nav_mode          : 1; //!< [БЦВМ-Д046] Режим комплексной обработки информации (КОИ)
   uint16_t ir_nav_mode           : 1; //!< [БЦВМ-Д047] Инерциальный режим счисления навигационных параметров (ИР)
   uint16_t idr_nav_mode          : 1; //!< [БЦВМ-Д048] Инерциально-допплеровский режим счисления навигационных параметров (ИДР)
   uint16_t air_nav_mode          : 1; //!< [БЦВМ-Д049] Астроинерциальный режим счисления навигационных параметров (АИР)
   uint16_t time_msk              : 1; //!< [БЦВМ-А045] Признак текущего времени - московское
   uint16_t time_utc              : 1; //!< [БЦВМ-А045] Признак текущего времени - UTC
   uint16_t time_local            : 1; //!< [БЦВМ-А045] Признак текущего времени - местное поясное
   uint16_t mfpu_landing_sys_prmg : 1; //!< [БЦВМ] На МФПУ выбрана СП ПРМГ
   uint16_t mfpu_landing_sys_ils  : 1; //!< [БЦВМ] На МФПУ выбрана СП ILS
   uint16_t mfpu_landing_sys_sns  : 1; //!< [БЦВМ] На МФПУ выбрана СП СНС
   uint16_t                       : 2; //!< Резерв
} bcvm_flag_word_1_b_t;

//! Слова 2-3 сигналов БЦВМ
typedef struct bcvm_flag_words_2_3_b_t {
   uint32_t route_number         : 20; //!< [БЦВМ-А034] Номер маршрута //(min:0 max:999999 bits:4..19 lsb:1)
   uint32_t waypoint_time_hour   : 5;  //!< [БЦВМ-А011] Время пролета очередного ППМ, час //(min:0 max:23)
   uint32_t waypoint_time_minute : 6;  //!< [БЦВМ-А011] Время пролета очередного ППМ, минута //(min:0 max:59)
   uint32_t                      : 1;  //!< Резерв
} bcvm_flag_words_2_3_b_t;

//! Слова 4-5 сигналов БЦВМ
typedef struct bcvm_flag_words_4_5_b_t {
   uint32_t waypoint_time_second : 6; //!< [БЦВМ-А011] Время пролета очередного ППМ, секунда //(min:0 max:59)
   uint32_t fuel_time_hour       : 5; //!< [БЦВМ-А026] Время, оставшееся по запасу топлива, час //(min:0 max:23)
   uint32_t fuel_time_minute     : 6; //!< [БЦВМ-А026] Время, оставшееся по запасу топлива, минута //(min:0 max:59)
   uint32_t fuel_time_second     : 6; //!< [БЦВМ-А026] Время, оставшееся по запасу топлива, секунда //(min:0 max:59)
   uint32_t waypoint_time_e_hour : 5; //!< [БЦВМ-А033] Время полета, оставшееся до очередного ППМ, час //(min:0 max:23)
   uint32_t                      : 4;  //!< Резерв
} bcvm_flag_words_4_5_b_t;

//! Слова 6-7 сигналов БЦВМ
typedef struct bcvm_flag_words_6_7_b_t {
   uint32_t waypoint_time_e_minute : 6; //!< [БЦВМ-А033] Время полета, оставшееся до очередного ППМ, минута //(min:0 max:59)
   uint32_t waypoint_time_e_second : 6; //!< [БЦВМ-А033] Время полета, оставшееся до очередного ППМ, секунда //(min:0 max:59)
   uint32_t current_time_hour      : 5; //!< [БЦВМ-А036] Текущее время, час //(min:0 max:23)
   uint32_t current_time_minute    : 6; //!< [БЦВМ-А036] Текущее время, минута //(min:0 max:59)
   uint32_t current_time_second    : 6; //!< [БЦВМ-А036] Текущее время, секунда //(min:0 max:59)
   uint32_t                        : 3; //!< Резерв
} bcvm_flag_words_6_7_b_t;

//! Слово сигналов и достоверностей ВСУ
typedef struct vsu_flag_valid_word_b_t {
   uint16_t oil_pressure_low          : 1; //!< [ВСУ-Д004] Пониженное давление масла на входе Рм
   uint16_t tg_high                   : 1; //!< [ВСУ-Д005] Повышенная температура газа за турбиной Тг
   uint16_t n_high                    : 1; //!< [ВСУ-Д006] Повышенные обороты ротора N
   uint16_t shutters_opened           : 1; //!< [ВСУ-Д011] Створки открыты
   uint16_t                           : 4; //!< Резерв
   uint16_t n_valid                   : 1; //!< Д[ВСУ-А001] Достоверность значения оборотов ротора ВСУ
   uint16_t n_max_2_valid             : 1; //!< Д[ВСУ-А002] Достоверность предельного значения оборотов ротора ВСУ
   uint16_t n_max_1_valid             : 1; //!< Д[ВСУ-А003] Достоверность повышенного значения оборотов ротора ВСУ
   uint16_t tg_valid                  : 1; //!< Д[ВСУ-А004] Достоверность температуры газа за турбиной ВСУ
   uint16_t tg_max_2_valid            : 1; //!< Д[ВСУ-А005] Достоверность предельной температуры газа за турбиной ВСУ
   uint16_t tg_max_1_valid            : 1; //!< Д[ВСУ-А007] Достоверность повышенной температуры газа за турбиной ВСУ
   uint16_t oil_temperature_valid     : 1; //!< Д[ВСУ-А008] Достоверность температуры масла в маслобаке ВСУ
   uint16_t oil_temperature_max_valid : 1; //!< Д[ВСУ-А009] Достоверность повышенной температуры масла в маслобаке ВСУ
} vsu_flag_valid_word_b_t;

//! Слово сигналов РЛС
typedef struct rls_flag_word_b_t {
   uint16_t rli_type : 2;  //!< Тип радиолокационного изображения (0 - нет РЛИ, 1 - 10-дюймовое, 2 - 15-дюймовое) //(min:0 max:2)
   uint16_t          : 14; //!< Резерв
} rls_flag_word_b_t;

//! Слово сигналов РЭП
typedef struct rap_flag_word_b_t {
   uint16_t volume         : 4;  //!< [РЭП-А054] Громкость тональных сигналов РЭП "Наведение" и "Сопровождение" //(min:0 max:11 bits:4..19 lsb:1)
   uint16_t bsv_bu_loading : 1;  //!< Выполнение загрузки библиотеки угроз БУ и ПО
   uint16_t                : 11; //!< Резерв
} rap_flag_word_b_t;

//! Слово 1 сигналов ФПО НО с данными ударных групп
typedef struct group_flag_word_1_b_t {
   uint16_t callsign                  : 12; //!< [ФПО НО-А016] Позывной собственного самолета //(min:0 max:999)
   uint16_t callsign_valid            : 1;  //!< Д[ФПО НО-А016] Наличие информации о позывном собственного самолета
   uint16_t selected_elevation_valid  : 1;  //!< Д[ФПО НО-А093] Наличие информации о заданном превышении dh между своим и впререди летящим самолетом
   uint16_t selected_distance_z_valid : 1;  //!< Д[ФПО НО-А094] Наличие информации о заданном интервале i между своим и впререди летящим самолетом
   uint16_t selected_distance_x_valid : 1;  //!< Д[ФПО НО-А095] Наличие информации о заданной дистанции d между своим и впререди летящим самолетом
} group_flag_word_1_b_t;

//! Слово 2 сигналов ФПО НО с данными ударных групп
typedef struct group_flag_word_2_b_t {
   uint16_t position      : 5;  //!< [ФПО НО] Позиция собственного самолета среди ударных групп (0 - не известна) //(min:0 max:16)
   uint16_t safe_distance : 11; //!< [ФПО НО-А062] Безопасная дистанция //(min:0 max:500)
} group_flag_word_2_b_t;

//! Слово 3 сигналов ФПО НО с данными ударных групп
typedef struct group_flag_word_3_b_t {
   uint16_t safe_distance_valid : 1; //!< Д[ФПО НО-А062] Наличие информации о безопасной дистанции
   uint16_t data_01_valid       : 1; //!< Наличие информации о самолете 1 ударных групп
   uint16_t data_02_valid       : 1; //!< Наличие информации о самолете 2 ударных групп
   uint16_t data_03_valid       : 1; //!< Наличие информации о самолете 3 ударных групп
   uint16_t data_04_valid       : 1; //!< Наличие информации о самолете 4 ударных групп
   uint16_t data_05_valid       : 1; //!< Наличие информации о самолете 5 ударных групп
   uint16_t data_06_valid       : 1; //!< Наличие информации о самолете 6 ударных групп
   uint16_t data_07_valid       : 1; //!< Наличие информации о самолете 7 ударных групп
   uint16_t data_08_valid       : 1; //!< Наличие информации о самолете 8 ударных групп
   uint16_t data_09_valid       : 1; //!< Наличие информации о самолете 9 ударных групп
   uint16_t data_10_valid       : 1; //!< Наличие информации о самолете 10 ударных групп
   uint16_t data_11_valid       : 1; //!< Наличие информации о самолете 11 ударных групп
   uint16_t data_12_valid       : 1; //!< Наличие информации о самолете 12 ударных групп
   uint16_t data_13_valid       : 1; //!< Наличие информации о самолете 13 ударных групп
   uint16_t data_14_valid       : 1; //!< Наличие информации о самолете 14 ударных групп
   uint16_t data_15_valid       : 1; //!< Наличие информации о самолете 15 ударных групп
} group_flag_word_3_b_t;

//! Номера самолетов ударных групп, информация о которых передается
typedef struct group_aircraft_numbers_b_t {
   uint16_t aircraft_a_number : 4; //!< [ФПО НО] Номер самолета ударных групп, информация о котором передается //(min:1 max:15)
   uint16_t aircraft_b_number : 4; //!< [ФПО НО] Номер самолета ударных групп, информация о котором передается //(min:1 max:15)
   uint16_t aircraft_c_number : 4; //!< [ФПО НО] Номер самолета ударных групп, информация о котором передается //(min:1 max:15)
   uint16_t aircraft_d_number : 4; //!< [ФПО НО] Номер самолета ударных групп, информация о котором передается //(min:1 max:15)
} group_aircraft_numbers_b_t;

//! Слово 1 сигналов ДВ
typedef struct dv_flag_word_1_b_t {
   uint16_t dv1_start_ready_on_land : 1; //!< [ДВ1-Д001] Запуск на земле готов
   uint16_t dv2_start_ready_on_land : 1; //!< [ДВ2-Д001] Запуск на земле готов
   uint16_t dv3_start_ready_on_land : 1; //!< [ДВ3-Д001] Запуск на земле готов
   uint16_t dv4_start_ready_on_land : 1; //!< [ДВ4-Д001] Запуск на земле готов
   uint16_t dv1_start_ready_in_air  : 1; //!< [ДВ1-Д002] Запуск в воздухе готов
   uint16_t dv2_start_ready_in_air  : 1; //!< [ДВ2-Д002] Запуск в воздухе готов
   uint16_t dv3_start_ready_in_air  : 1; //!< [ДВ3-Д002] Запуск в воздухе готов
   uint16_t dv4_start_ready_in_air  : 1; //!< [ДВ4-Д002] Запуск в воздухе готов
   uint16_t dv1_afterburning        : 1; //!< [ДВ1-Д003] Форсаж включен
   uint16_t dv2_afterburning        : 1; //!< [ДВ2-Д003] Форсаж включен
   uint16_t dv3_afterburning        : 1; //!< [ДВ3-Д003] Форсаж включен
   uint16_t dv4_afterburning        : 1; //!< [ДВ4-Д003] Форсаж включен
   uint16_t dv1_wet_start_ready     : 1; //!< [ДВ1-Д004] Ложный запуск готов
   uint16_t dv2_wet_start_ready     : 1; //!< [ДВ2-Д004] Ложный запуск готов
   uint16_t dv3_wet_start_ready     : 1; //!< [ДВ3-Д004] Ложный запуск готов
   uint16_t dv4_wet_start_ready     : 1; //!< [ДВ4-Д004] Ложный запуск готов
} dv_flag_word_1_b_t;

//! Слово 2 сигналов ДВ
typedef struct dv_flag_word_2_b_t {
   uint16_t dv1_dry_motoring_ready : 1; //!< [ДВ1-Д005] Холодная прокрутка готова
   uint16_t dv2_dry_motoring_ready : 1; //!< [ДВ2-Д005] Холодная прокрутка готова
   uint16_t dv3_dry_motoring_ready : 1; //!< [ДВ3-Д005] Холодная прокрутка готова
   uint16_t dv4_dry_motoring_ready : 1; //!< [ДВ4-Д005] Холодная прокрутка готова
   uint16_t dv1_start_land         : 1; //!< [ДВ1-Д009] Запуск на земле
   uint16_t dv2_start_land         : 1; //!< [ДВ2-Д009] Запуск на земле
   uint16_t dv3_start_land         : 1; //!< [ДВ3-Д009] Запуск на земле
   uint16_t dv4_start_land         : 1; //!< [ДВ4-Д009] Запуск на земле
   uint16_t dv1_start_in_air       : 1; //!< [ДВ1-Д010] Запуск в воздухе
   uint16_t dv2_start_in_air       : 1; //!< [ДВ2-Д010] Запуск в воздухе
   uint16_t dv3_start_in_air       : 1; //!< [ДВ3-Д010] Запуск в воздухе
   uint16_t dv4_start_in_air       : 1; //!< [ДВ4-Д010] Запуск в воздухе
   uint16_t dv1_dry_motoring       : 1; //!< [ДВ1-Д011] Холодная прокрутка
   uint16_t dv2_dry_motoring       : 1; //!< [ДВ2-Д011] Холодная прокрутка
   uint16_t dv3_dry_motoring       : 1; //!< [ДВ3-Д011] Холодная прокрутка
   uint16_t dv4_dry_motoring       : 1; //!< [ДВ4-Д011] Холодная прокрутка
} dv_flag_word_2_b_t;

//! Слово 3 сигналов ДВ
typedef struct dv_flag_word_3_b_t {
   uint16_t dv1_wet_start       : 1; //!< [ДВ1-Д012] Ложный запуск
   uint16_t dv2_wet_start       : 1; //!< [ДВ2-Д012] Ложный запуск
   uint16_t dv3_wet_start       : 1; //!< [ДВ3-Д012] Ложный запуск
   uint16_t dv4_wet_start       : 1; //!< [ДВ4-Д012] Ложный запуск
   uint16_t dv1_emergency_start : 1; //!< [ДВ1-Д013] Аварийный запуск в воздухе
   uint16_t dv2_emergency_start : 1; //!< [ДВ2-Д013] Аварийный запуск в воздухе
   uint16_t dv3_emergency_start : 1; //!< [ДВ3-Д013] Аварийный запуск в воздухе
   uint16_t dv4_emergency_start : 1; //!< [ДВ4-Д013] Аварийный запуск в воздухе
   uint16_t dv1_kpp_opened      : 1; //!< [ДВ1-Д022] Клапаны перепуска ВД открыты
   uint16_t dv2_kpp_opened      : 1; //!< [ДВ2-Д022] Клапаны перепуска ВД открыты
   uint16_t dv3_kpp_opened      : 1; //!< [ДВ3-Д022] Клапаны перепуска ВД открыты
   uint16_t dv4_kpp_opened      : 1; //!< [ДВ4-Д022] Клапаны перепуска ВД открыты
   uint16_t dv1_kpv_not_closed  : 1; //!< [ДВ1-Д025] Незакрытие КПВ ВД
   uint16_t dv2_kpv_not_closed  : 1; //!< [ДВ2-Д025] Незакрытие КПВ ВД
   uint16_t dv3_kpv_not_closed  : 1; //!< [ДВ3-Д025] Незакрытие КПВ ВД
   uint16_t dv4_kpv_not_closed  : 1; //!< [ДВ4-Д025] Незакрытие КПВ ВД
} dv_flag_word_3_b_t;

//! Слово 4 сигналов ДВ
typedef struct dv_flag_word_4_b_t {
   uint16_t dv1_vna_heating  : 1; //!< [ДВ1-Д051] Обогрев ВНА включен
   uint16_t dv2_vna_heating  : 1; //!< [ДВ2-Д051] Обогрев ВНА включен
   uint16_t dv3_vna_heating  : 1; //!< [ДВ3-Д051] Обогрев ВНА включен
   uint16_t dv4_vna_heating  : 1; //!< [ДВ4-Д051] Обогрев ВНА включен
   uint16_t dv1_takeoff_mode : 1; //!< [ДВ1-Д059] Режим полета "взлет"
   uint16_t dv2_takeoff_mode : 1; //!< [ДВ2-Д059] Режим полета "взлет"
   uint16_t dv3_takeoff_mode : 1; //!< [ДВ3-Д059] Режим полета "взлет"
   uint16_t dv4_takeoff_mode : 1; //!< [ДВ4-Д059] Режим полета "взлет"
   uint16_t dv1_in_air_mode  : 1; //!< [ДВ1-Д060] Режим полета "полет"
   uint16_t dv2_in_air_mode  : 1; //!< [ДВ2-Д060] Режим полета "полет"
   uint16_t dv3_in_air_mode  : 1; //!< [ДВ3-Д060] Режим полета "полет"
   uint16_t dv4_in_air_mode  : 1; //!< [ДВ4-Д060] Режим полета "полет"
   uint16_t dv1_cooling_on   : 1; //!< [ДВ1-Д082] Охлаждение включено
   uint16_t dv2_cooling_on   : 1; //!< [ДВ2-Д082] Охлаждение включено
   uint16_t dv3_cooling_on   : 1; //!< [ДВ3-Д082] Охлаждение включено
   uint16_t dv4_cooling_on   : 1; //!< [ДВ4-Д082] Охлаждение включено
} dv_flag_word_4_b_t;

//! Слово сигналов МСРП
typedef struct msrp_flag_word_b_t {
   uint16_t flag_1  : 1;  //!< [МСРП-Д001] Резерв
   uint16_t flag_2  : 1;  //!< [МСРП-Д002] Резерв
   uint16_t flag_3  : 1;  //!< [МСРП-Д003] Резерв
   uint16_t flag_4  : 1;  //!< [МСРП-Д004] Резерв
   uint16_t barring : 1;  //!< [МСРП-Д005] Запрет выдачи отчета (информация недоступна, МСРП не готова или не в режиме обслуживания)
   uint16_t         : 11; //!< Резерв
} msrp_flag_word_b_t;

//! Слово сигналов ПКР
typedef struct pkr_flag_word_b_t {
   uint16_t echelon_far      : 1; //!< [ПКР-Д010] Недопустимое отклонение от эшелона
   uint16_t echelon_danger   : 1; //!< [ПКР-Д011] Опасное отклонение от эшелона
   uint16_t altitude_far     : 1; //!< [ПКР-Д013] Недопустимое отклонение от заданной высоты
   uint16_t altitude_control : 1; //!< [ПКР-Д014] Наличие контроля за отклонением от эшелона/заданной высоты
   uint16_t echelon_check    : 1; //!< [ПКР-Д015] Вертикальная скорость приближения к заданному эшелону меньше 2 м/с
   uint16_t altitude_check   : 1; //!< [ПКР-Д016] Вертикальная скорость приближения к заданной высоте меньше 2 м/с
   uint16_t mach_high        : 1; //!< [ПКР-Д025] Достижение максимально допустимого числа Маха
   uint16_t                  : 9; //!< Резерв
} pkr_flag_word_b_t;

//! Слово 1 сигналов ПУИ
typedef struct pui_flag_word_1_b_t {
   uint16_t vpr                     : 1; //!< [УПР-Д012] Активен режим индикации ВПР/Ноп
   uint16_t mvs                     : 1; //!< [УПР-Д013] Активен режим индикации МВС
   uint16_t vpr_selecting           : 1; //!< [УПР-Д017] Активен режим выставки ВПР/Ноп (режим не подтвержден кнопкой ВВОД)
   uint16_t mvs_selecting           : 1; //!< [УПР-Д018] Активен режим выставки МВС (режим не подтвержден кнопкой ВВОД)
   uint16_t baro_type               : 2; //!< [УПР-Д014…УПР-Д016] Режим индикации барокоррекции для кадров ПНП/ПЛАН/СУО (1-СТД, 2-QFE, 3-QNH)
   uint16_t baro_type_kpi           : 2; //!< [УПР-Д014…УПР-Д016*] Режим индикации барокоррекции для кадра КПИ (1-СТД, 2-QFE, 3-QNH)
   uint16_t baro_type_kpi_selecting : 2; //!< [УПР-Д019…УПР-Д025] Режим выставки барокоррекции для кадра КПИ (0-не активен, 1-СТД, 2-QFE, 3-QNH)
   uint16_t confirm_pressures       : 1; //!< [УПР-Д026] Ожидание подтверждения выставленной барокоррекции с другого ПУИ
   uint16_t enter_pressures         : 1; //!< [УПР] Барокоррекции не введены
   uint16_t zero_alt_available      : 1; //!< [УПР] Доступность автоматической выставки нулевой баровысоты QFE по кнопке "H=0"
   uint16_t unreserved_pui1         : 1; //!< [УПР] Отключение подтверждения ввода с ПУИ1
   uint16_t unreserved_pui2         : 1; //!< [УПР] Отключение подтверждения ввода с ПУИ2
   uint16_t                         : 1; //!< Резерв
} pui_flag_word_1_b_t;

//! Слово 2 сигналов ПУИ
typedef struct pui_flag_word_2_b_t {
   uint16_t pui1_mfci1        : 1; //!< Вызов индикации ПУИ 1 в кадре МФЦИ 1
   uint16_t pui1_mfci2        : 1; //!< Вызов индикации ПУИ 1 в кадре МФЦИ 2
   uint16_t pui1_mfci3        : 1; //!< Вызов индикации ПУИ 1 в кадре МФЦИ 3
   uint16_t pui1_button_topl  : 1; //!< Нажатие на кнопку "ТОПЛ" на ПУИ 1
   uint16_t pui1_button_upr   : 1; //!< Нажатие на кнопку "УПР" на ПУИ 1
   uint16_t pui1_button_asu   : 1; //!< Нажатие на кнопку "АСУ" на ПУИ 1
   uint16_t pui1_button_suo   : 1; //!< Нажатие на кнопку "СУО" на ПУИ 1
   uint16_t pui1_button_plan  : 1; //!< Нажатие на кнопку "ПЛАН" на ПУИ 1
   uint16_t pui1_button_dvs   : 1; //!< Нажатие на кнопку "ДВ/С" на ПУИ 1
   uint16_t pui1_button_pnp   : 1; //!< Нажатие на кнопку "ПНП" на ПУИ 1
   uint16_t pui1_button_kpi   : 1; //!< Нажатие на кнопку "КПИ" на ПУИ 1
   uint16_t pui1_button_menu  : 1; //!< Нажатие на кнопку "Меню" на ПУИ 1
   uint16_t pui1_cursor_left  : 1; //!< Отклонение джойстика ПУИ 1 влево
   uint16_t pui1_cursor_right : 1; //!< Отклонение джойстика ПУИ 1 вправо
   uint16_t pui1_cursor_up    : 1; //!< Отклонение джойстика ПУИ 1 вверх
   uint16_t pui1_cursor_down  : 1; //!< Отклонение джойстика ПУИ 1 вниз
} pui_flag_word_2_b_t;

//! Слово 3 сигналов ПУИ
typedef struct pui_flag_word_3_b_t {
   uint16_t pui2_mfci3        : 1; //!< Вызов индикации ПУИ 2 в кадре МФЦИ 3
   uint16_t pui2_mfci4        : 1; //!< Вызов индикации ПУИ 2 в кадре МФЦИ 4
   uint16_t pui2_mfci5        : 1; //!< Вызов индикации ПУИ 2 в кадре МФЦИ 5
   uint16_t pui2_button_topl  : 1; //!< Нажатие на кнопку "ТОПЛ" на ПУИ 2
   uint16_t pui2_button_upr   : 1; //!< Нажатие на кнопку "УПР" на ПУИ 2
   uint16_t pui2_button_asu   : 1; //!< Нажатие на кнопку "АСУ" на ПУИ 2
   uint16_t pui2_button_suo   : 1; //!< Нажатие на кнопку "СУО" на ПУИ 2
   uint16_t pui2_button_plan  : 1; //!< Нажатие на кнопку "ПЛАН" на ПУИ 2
   uint16_t pui2_button_dvs   : 1; //!< Нажатие на кнопку "ДВ/С" на ПУИ 2
   uint16_t pui2_button_pnp   : 1; //!< Нажатие на кнопку "ПНП" на ПУИ 2
   uint16_t pui2_button_kpi   : 1; //!< Нажатие на кнопку "КПИ" на ПУИ 2
   uint16_t pui2_button_menu  : 1; //!< Нажатие на кнопку "Меню" на ПУИ 2
   uint16_t pui2_cursor_left  : 1; //!< Отклонение джойстика ПУИ 2 влево
   uint16_t pui2_cursor_right : 1; //!< Отклонение джойстика ПУИ 2 вправо
   uint16_t pui2_cursor_up    : 1; //!< Отклонение джойстика ПУИ 2 вверх
   uint16_t pui2_cursor_down  : 1; //!< Отклонение джойстика ПУИ 2 вниз
} pui_flag_word_3_b_t;

//! Слово 4 сигналов ПУИ
typedef struct pui_flag_word_4_b_t {
   uint16_t pui1_button_choise       : 1;  //!< Нажатие на кнопку "Выбор" на ПУИ 1
   uint16_t pui2_button_choise       : 1;  //!< Нажатие на кнопку "Выбор" на ПУИ 2
   uint16_t vpr_warning              : 1;  //!< [СОИ-Л002] Достижение высоты принятия решения
   uint16_t danger_altitude_warning  : 1;  //!< [СОИ-Л003] Достижение опасной высоты
   uint16_t vpr_danger_altitude_flag : 1;  //!< [РВМ1-A001 < ПУИ-A001 + РВМ2-A001 < ПУИ-A001] Высота от любого РВм меньше высоты принятия решения (опасной высоты)
   uint16_t                          : 11; //!< Резерв
} pui_flag_word_4_b_t;

//! Слово сигналов РСБН/VIM/DME
typedef struct rsbn_vim_dme_flag_word_b_t {
   uint16_t rsbn_navigation       : 1; //!< [РСБН-Д001] Режим работы РСБН "навигация"
   uint16_t rsbn_landing          : 1; //!< [РСБН-Д002] Режим работы РСБН "посадка"
   uint16_t rsbn_measure          : 1; //!< [РСБН-Д003] Режим работы РСБН "встреча-измерение"
   uint16_t rsbn_transmit         : 1; //!< [РСБН-Д004] Режим работы РСБН "встреча-ретрансляция"
   uint16_t rsbn_measure_transmit : 1; //!< [РСБН-Д005] Режим работы РСБН "встреча-измерение-ретрансляция"
   uint16_t vim_dprm              : 1; //!< [VIM-Д001] ДПРМ (Сигнал пролета маркерного маяка дальнего 400 Гц)
   uint16_t vim_sprm              : 1; //!< [VIM-Д002] СПРМ (Сигнал пролета маркерного маяка среднего 1300 Гц)
   uint16_t vim_bprm              : 1; //!< [VIM-Д003] БПРМ (Сигнал пролета маркерного маяка ближнего 3000 Гц)
   uint16_t vim1_ils_mode         : 1; //!< [VIM-Д004] Выбор режима ILS/VOR VIM1 (1-ILS, 0-VOR)
   uint16_t vim2_ils_mode         : 1; //!< [VIM-Д004] Выбор режима ILS/VOR VIM2 (1-ILS, 0-VOR)
   uint16_t dme1_nm_mode          : 1; //!< [DME] Режим индикации дальности в морских милях DME1
   uint16_t dme2_nm_mode          : 1; //!< [DME] Режим индикации дальности в морских милях DME2
   uint16_t                       : 4; //!< Резерв
} rsbn_vim_dme_flag_word_b_t;

//! Слово 1 сигналов САУ
typedef struct sau_flag_word_1_b_t {
   uint16_t gnav_active             : 1; //!< [САУ-Д001] Режим "Горизонтальная навигация" выполняется (ГОР НАВ)
   uint16_t course_active           : 1; //!< [САУ-Д002] Функция "Стабилизация курса" в режиме "Совмещенное управление" выполняется (КУРС)
   uint16_t roll_active             : 1; //!< [САУ-Д003] Функция "Стабилизация крена" в режиме "Совмещенное управление" выполняется (КРЕН)
   uint16_t zk_active               : 1; //!< [САУ-Д004] Режим "ЗК" выполняется (ЗК)
   uint16_t zpu_active              : 1; //!< [САУ-Д005] Режим "ЗПУ" выполняется (ЗПУ)
   uint16_t stab_course_active      : 1; //!< [САУ-Д006] Стабилизация текущего курсового угла выполняется (СТАБ К)
   uint16_t stab_track_angle_active : 1; //!< [САУ-Д007] Стабилизация путевого угла выполняется (СТАБ ПУ)
   uint16_t course_zone_active      : 1; //!< [САУ-Д008] Функция "Управление по курсовой зоне" в режимах "Курсовая зона" или "Посадка" выполняется (КУР ЗОН)
   uint16_t go_around_x_active      : 1; //!< [САУ-Д009] Режим "Уход на 2-ой круг" в боковом канале выполняется (УХОД)
   uint16_t stab_h_active           : 1; //!< [САУ-Д010] Режим "Стабилизация высоты" выполняется (СТАБ Н)
   uint16_t path_angle_active       : 1; //!< [САУ-Д011] Функция стабилизации угла наклона траектории в режиме "Совмещенное управление" выполняется (УНТ)
   uint16_t h_active                : 1; //!< [САУ-Д012] Режим "Выход на высоту эшелона" выполняется (ВЫХ Н)
   uint16_t vy_active               : 1; //!< [САУ-Д013] Режим "Vy" выполняется (В СКОР)
   uint16_t gliss_active            : 1; //!< [САУ-Д014] Управление по глиссаде в режиме "Посадка" выполняется (ГЛИС)
   uint16_t go_around_y_active      : 1; //!< [САУ-Д015] Режим "Уход" в канале тангажа выполняется (УХОД)
   uint16_t gnav_ready              : 1; //!< [САУ-Д016] Режим "Горизонтальная навигация" подготовлен (ГОР НАВ)
} sau_flag_word_1_b_t;

//! Слово 2 сигналов САУ
typedef struct sau_flag_word_2_b_t {
   uint16_t course_zone_ready : 1; //!< [САУ-Д017] Функция "Управление по курсовой зоне" в режимах "Курсовая зона" или "Посадка" подготовлена (КУР ЗОН)
   uint16_t gliss_ready       : 1; //!< [САУ-Д018] Управление по глиссаде в режиме "Посадка" подготовлено (ГЛИС)
   uint16_t stab_h_ready      : 1; //!< [САУ-Д019] Режим "Стабилизация высоты" подготовлен (СТАБ Н)
   uint16_t ap_on             : 1; //!< [САУ-Д020] Включен автоматический режим управления (АП)
   uint16_t director          : 1; //!< [САУ-Д021] Включен директорный режим управления (ДИР)
   uint16_t speed_active      : 1; //!< [САУ-Д027] Режим "Стабилизация и управление приборной скоростью" выполняется (СКОР)
   uint16_t mach_active       : 1; //!< [САУ-Д028] Режим "Стабилизация и управление числом М полета" выполняется (М)
   uint16_t pitch_active      : 1; //!< [САУ-Д029] Функция "Стабилизация тангажа в режиме "совмещенное управление" выполняется (ТНГЖ)
   uint16_t fzd_active        : 1; //!< [САУ-Д030] Функция "Защита диапазона по скорости" выполняется (ФЗД)
   uint16_t horizon_x_active  : 1; //!< [САУ-Д031] Функция "Приведение к горизонту в боковом канале" выполняется (ГОРИЗНТ)
   uint16_t horizon_y_active  : 1; //!< [САУ-Д032] Функция "Приведение к горизонту в продольном канале" выполняется (ГОРИЗНТ)
   uint16_t landing_high      : 1; //!< [САУ-Д033] Отклонение вверх от расчетной глиссады велико
   uint16_t landing_low       : 1; //!< [САУ-Д034] Отклонение вниз от расчетной глиссады велико
   uint16_t landing_right     : 1; //!< [САУ-Д035] Отклонение вправо от курса посадки велико
   uint16_t landing_left      : 1; //!< [САУ-Д036] Отклонение влево от курса посадки велико
   uint16_t stab_t            : 1; //!< [САУ-Д037] Выполняется режим "Стабилизация эквивалента тяги" (СТАБ Т)
} sau_flag_word_2_b_t;

//! Слово 3 сигналов САУ
typedef struct sau_flag_word_3_b_t {
   uint16_t go_around_active     : 1; //!< [САУ-Д038] Выполняется режим "Уход на второй круг"
   uint16_t landing_cathegory_1  : 1; //!< [САУ-Д039] Оборудование обеспечивает заход на посадку по категории 1 (КАТ 1)
   uint16_t landing_cathegory_2  : 1; //!< [САУ-Д040] Оборудование обеспечивает заход на посадку по категории 2 (КАТ 2)
   uint16_t at_ready             : 1; //!< [САУ-Д041] Канал тяги готов к работе в автоматических режимах (АТ)
   uint16_t vnav_ready           : 1; //!< [САУ-Д044] Режим "Вертикальная навигация" подготовлен (В НАВ)
   uint16_t vnav_active          : 1; //!< [САУ-Д045] Режим "Вертикальная навигация" выполняется (В НАВ)
   uint16_t director_right_on    : 1; //!< [САУ-Д046] Правый директор включен
   uint16_t director_left_on     : 1; //!< [САУ-Д047] Левый директор включен
   uint16_t show_director_x      : 1; //!< [САУ-Д048] Необходимость отображения директорной планки бокового канала
   uint16_t show_director_y      : 1; //!< [САУ-Д049] Необходимость отображения директорной планки продольного канала
   uint16_t course_zone_approach : 1; //!< [САУ-Д050] Выход на курсовую зону в посадке выполняется
   uint16_t gliss_approach       : 1; //!< [САУ-Д051] Выход на глиссаду в посадке выполняется
   uint16_t at_active            : 1; //!< [САУ-Д052] АТ (автоматическое управление в канале тяги выполняется)
   uint16_t                      : 3; //!< Резерв
} sau_flag_word_3_b_t;

//! Слово сигналов СВР
typedef struct svr_flag_word_b_t {
   uint16_t date_entered  : 1; //!< [СВР-Д039] Дата поиска введена
   uint16_t time_entered  : 1; //!< [СВР-Д040] Время поиска введено
   uint16_t event_entered : 1; //!< [СВР-Д041] Номер события записи введен
   uint16_t test_failed   : 1; //!< [СВР-Д043] true-"КОНТРОЛЬ ЗАВЕРШЕН. СВР ОТКАЗ", false-"КОНТРОЛЬ ЗАВЕРШЕН. СВР ИСПРАВНА"
   uint16_t check_date    : 1; //!< [СВР-Д044] ПРОВЕРЬ ДАННЫЕ ПОИСКА (ДАТА)
   uint16_t check_time    : 1; //!< [СВР-Д045] ПРОВЕРЬ ДАННЫЕ ПОИСКА (ВРЕМЯ/СОБЫТИЕ)
   uint16_t test_active   : 1; //!< [СВР] Контроль активен
   uint16_t test_passed   : 1; //!< [СВР] Контроль завершен
   uint16_t play_active   : 1; //!< [СВР] Активно воспроизведение записанной информации (режим просмотра записанной информации отличен от "нет воспроизведения")
   uint16_t watch_active  : 1; //!< [СВР] Активен просмотр текущей информации
   uint16_t               : 6; //!< Резерв
} svr_flag_word_b_t;

//! Слово 1 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_1_b_t {
   uint16_t kisl_pressure_l_valid        : 1; //!< Д[КИСЛ-А001] Достоверность давления кислорода левый борт
   uint16_t kisl_pressure_r_valid        : 1; //!< Д[КИСЛ-А002] Достоверность давления кислорода правый борт
   uint16_t skv_temperature_pilots_valid : 1; //!< Д[СКВ-А001] Достоверность температуры в кабине экипажа
   uint16_t skv_temperature_pgo_valid    : 1; //!< Д[СКВ-А002] Достоверность температуры в переднем грузовом отсеке
   uint16_t skv_temperature_zgo_valid    : 1; //!< Д[СКВ-А003] Достоверность температуры в заднем грузовом отсеке
   uint16_t skv_temperature_zto_valid    : 1; //!< Д[СКВ-А004] Достоверность температуры в заднем техническом отсеке
   uint16_t skv_dv1_air_bleed_closed     : 1; //!< [СКВ-Д001] Отбор от двигателя 1 закрыт
   uint16_t skv_dv2_air_bleed_closed     : 1; //!< [СКВ-Д002] Отбор от двигателя 2 закрыт
   uint16_t skv_dv3_air_bleed_closed     : 1; //!< [СКВ-Д003] Отбор от двигателя 3 закрыт
   uint16_t skv_dv4_air_bleed_closed     : 1; //!< [СКВ-Д004] Отбор от двигателя 4 закрыт
   uint16_t skv_air_crossfeed_opened_l   : 1; //!< [СКВ-Д006] Заслонка кольцевания отборов открыта левая
   uint16_t skv_air_crossfeed_opened_r   : 1; //!< [СКВ-Д007] Заслонка кольцевания отборов открыта правая
   uint16_t skv_line1_off                : 1; //!< [СКВ-Д008] Магистраль 1 (левая) отключена
   uint16_t skv_line2_off                : 1; //!< [СКВ-Д009] Магистраль 2 (правая) отключена
   uint16_t skv_line_crossfeed_opened_l  : 1; //!< [СКВ-Д010] Заслонка кольцевания магистралей 1, 2 открыта левая
   uint16_t skv_line_crossfeed_opened_r  : 1; //!< [СКВ-Д011] Заслонка кольцевания магистралей 1, 2 открыта правая
} skv_gs_flag_word_1_b_t;

//! Слово 2 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_2_b_t {
   uint16_t skv_thu1_off                 : 1; //!< [СКВ-Д012] Турбохолодильная установка ТХУ1 отключена
   uint16_t skv_thu2_off                 : 1; //!< [СКВ-Д013] Турбохолодильная установка ТХУ2 отключена
   uint16_t skv_thu3_off                 : 1; //!< [СКВ-Д014] Турбохолодильная установка ТХУ3 отключена
   uint16_t skv_thu4_off                 : 1; //!< [СКВ-Д015] Турбохолодильная установка ТХУ4 отключена
   uint16_t skv_zsa_on                   : 1; //!< [СКВ-Д016] СКВ ЗСЭ включена
   uint16_t skv_nto_thu2_cooling_closed  : 1; //!< [СКВ-Д017] Заслонка подачи воздуха в НТО от ТХУ2 закрыта
   uint16_t skv_nto_thu1_cooling_closed  : 1; //!< [СКВ-Д018] Заслонка подачи воздуха в НТО от ТХУ1 закрыта
   uint16_t skv_thu34_crossfeed_opened   : 1; //!< [СКВ-Д019] Заслонка линии кольцевания ТХУ3 и ТХУ4 открыта
   uint16_t skv_vsu_heating_closed       : 1; //!< [СКВ-Д020] Заслонка обогрева отсека ВСУ закрыта
   uint16_t skv_zsa_failure              : 1; //!< [СКВ-Д034] Отказ СКВ ЗСЭ
   uint16_t skv_temperature_pilots_undef : 1; //!< [СКВ-Д091] Температура в кабине экипажа, нет данных
   uint16_t skv_temperature_pgo_undef    : 1; //!< [СКВ-Д092] Температура в переднем грузовом отсеке, нет данных
   uint16_t skv_temperature_zgo_undef    : 1; //!< [СКВ-Д093] Температура в заднем грузовом отсеке, нет данных
   uint16_t skv_temperature_zto_undef    : 1; //!< [СКВ-Д094] Температура в заднем техническом отсеке, нет данных
   uint16_t skv_dv1_air_bleed_failure    : 1; //!< [СКВ-Д102] Отказ регулятора отбора от двигателя 1
   uint16_t skv_dv2_air_bleed_failure    : 1; //!< [СКВ-Д103] Отказ регулятора отбора от двигателя 2
} skv_gs_flag_word_2_b_t;

//! Слово 3 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_3_b_t {
   uint16_t skv_dv3_air_bleed_failure         : 1; //!< [СКВ-Д118] Отказ регулятора отбора от двигателя 3
   uint16_t skv_dv4_air_bleed_failure         : 1; //!< [СКВ-Д119] Отказ регулятора отбора от двигателя 4
   uint16_t                                   : 1; //!< Резерв
   uint16_t skv_test                          : 1; //!< [СКВ-Д302] Режим "Наземный расширенный контроль"
   uint16_t skv_zsa_cooling_undef             : 1; //!< [СКВ-Д308] Нет данных управления подачей воздуха в СКВ ЗС
   uint16_t skv_nto_thu2_cooling_undef        : 1; //!< [СКВ-Д309] Нет данных управления подачей воздуха в НТО от ТХУ2
   uint16_t skv_pto_cooling_undef             : 1; //!< [СКВ-Д310] Нет данных управления подачей воздуха в ПТО
   uint16_t skv_temperature_ctrl_zgo_undef    : 1; //!< [СКВ-Д311] Нет данных регулирования температуры в ЗГО
   uint16_t skv_zto_thu_crossfeed_undef       : 1; //!< [СКВ-Д312] Нет данных определения температуры в ЗТО и контроля кольцевания ТХУ
   uint16_t skv_sto_zgo_cooling_undef         : 1; //!< [СКВ-Д313] Нет данных управления подачей воздуха в СТО ЗГО
   uint16_t skv_temperature_ctrl_pgo_undef    : 1; //!< [СКВ-Д314] Нет данных регулирования температуры в ПГО
   uint16_t skv_sto_thu_crossfeed_undef       : 1; //!< [СКВ-Д315] Нет данных контроля кольцевания ТХУ СТО
   uint16_t skv_sto_pgo_cooling_undef         : 1; //!< [СКВ-Д316] Нет данных управления подачей воздуха в СТО ПГО
   uint16_t skv_temperature_ctrl_pilots_undef : 1; //!< [СКВ-Д317] Нет данных регулирования температуры в кабине экипажа
   uint16_t skv_nto_thu1_cooling_undef        : 1; //!< [СКВ-Д318] Нет данных управления подачей воздуха в НТО от ТХУ1
   uint16_t skv_pilots_cooling_undef          : 1; //!< [СКВ-Д319] Нет данных управления подачей воздуха в кабине экипажа
} skv_gs_flag_word_3_b_t;

//! Слово 4 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_4_b_t {
   uint16_t skv_rid4_line_crossfeed_undef  : 1; //!< [СКВ-Д320] Нет данных управления РИД4 и заслонкой линии кольцевания магистралей 1 и 2
   uint16_t skv_air_crossfeed_undef        : 1; //!< [СКВ-Д321] Нет данных контроля правой заслонки кольцевания отборов и заслонок струйной защиты
   uint16_t skv_line2_rid3_cooling_undef   : 1; //!< [СКВ-Д322] Нет данных управления подачей в магистраль 2 и РИД3
   uint16_t skv_rid2_tvt12_crossfeed_undef : 1; //!< [СКВ-Д323] Нет данных управления РИД2 и заслонками линии кольцевания ТВТ1 и ТВТ2
   uint16_t skv_vsu_cooling_undef          : 1; //!< [СКВ-Д324] Нет данных управления подачей в отсек ВСУ и левой заслонкой кольцевания отборов
   uint16_t skv_line1_rid1_cooling_undef   : 1; //!< [СКВ-Д325] Нет данных управления подачей в магистраль 1 и РИД1
   uint16_t skv_temperature_ctrl_pgo_on    : 1; //!< [СКВ-Д326] Регулирование в ПГО включено
   uint16_t skv_temperature_ctrl_zgo_on    : 1; //!< [СКВ-Д327] Регулирование в ЗГО включено
   uint16_t mpu1_cooling_closed            : 1; //!< [МПУ-Д101] Заслонка охлаждения МПУ1 закрыта
   uint16_t mpu1_unit_flag                 : 1; //!< [МПУ-Д102] Наличие груза на МПУ1
   uint16_t mpu2_cooling_closed            : 1; //!< [МПУ-Д103] Заслонка охлаждения МПУ2 закрыта
   uint16_t mpu2_unit_flag                 : 1; //!< [МПУ-Д104] Наличие груза на МПУ2
   uint16_t mpu_bukv1_failure              : 1; //!< [МПУ-Д105] Отказ БУКВ-1 № 1
   uint16_t mpu_bukv2_failure              : 1; //!< [МПУ-Д106] Отказ БУКВ-1 № 2
   uint16_t gs_pressure_1_valid            : 1; //!< Д[ГС-А001] Достоверность давления в ГС1
   uint16_t gs_pressure_2_valid            : 1; //!< Д[ГС-А002] Достоверность давления в ГС2
} skv_gs_flag_word_4_b_t;

//! Слово 5 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_5_b_t {
   uint16_t gs_pressure_3_valid        : 1; //!< Д[ГС-А003] Достоверность давления в ГС3
   uint16_t gs_pressure_4_valid        : 1; //!< Д[ГС-А004] Достоверность давления в ГС4
   uint16_t gs_pressure_acc_1_valid    : 1; //!< Д[ГС-А005] Достоверность давления гидроаккумулятора ГС1
   uint16_t gs_pressure_acc_2_valid    : 1; //!< Д[ГС-А006] Достоверность давления гидроаккумулятора ГС2
   uint16_t gs_pressure_acc_3_valid    : 1; //!< Д[ГС-А007] Достоверность давления гидроаккумулятора ГС3
   uint16_t gs_pressure_acc_4_valid    : 1; //!< Д[ГС-А008] Достоверность давления гидроаккумулятора ГС4
   uint16_t gs_oil_level_1_valid       : 1; //!< Д[ГС-А009] Достоверность уровеня рабочей жидкости в баке ГС1
   uint16_t gs_oil_level_2_valid       : 1; //!< Д[ГС-А010] Достоверность уровеня рабочей жидкости в баке ГС2
   uint16_t gs_oil_level_3_valid       : 1; //!< Д[ГС-А011] Достоверность уровеня рабочей жидкости в баке ГС3
   uint16_t gs_oil_level_4_valid       : 1; //!< Д[ГС-А012] Достоверность уровеня рабочей жидкости в баке ГС4
   uint16_t gs_oil_temperature_1_valid : 1; //!< Д[ГС-А013] Достоверность температуры рабочей жидкости в баке ГС1
   uint16_t gs_oil_temperature_2_valid : 1; //!< Д[ГС-А015] Достоверность температуры рабочей жидкости в баке ГС2
   uint16_t gs_oil_temperature_3_valid : 1; //!< Д[ГС-А017] Достоверность температуры рабочей жидкости в баке ГС3
   uint16_t gs_oil_temperature_4_valid : 1; //!< Д[ГС-А019] Достоверность температуры рабочей жидкости в баке ГС4
   uint16_t gs_pressure_bulb_1_valid   : 1; //!< Д[ГС-А021] Достоверность давления в баллоне наддува № 1
   uint16_t gs_pressure_bulb_2_valid   : 1; //!< Д[ГС-А022] Достоверность давления в баллоне наддува № 2
} skv_gs_flag_word_5_b_t;

//! Слово 6 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_6_b_t {
   uint16_t gs_pressure_insuff_1_valid : 1; //!< Д[ГС-А023] Достоверность давления наддува в баке ГС1
   uint16_t gs_pressure_insuff_2_valid : 1; //!< Д[ГС-А024] Достоверность давления наддува в баке ГС2
   uint16_t gs_pressure_insuff_3_valid : 1; //!< Д[ГС-А025] Достоверность давления наддува в баке ГС3
   uint16_t gs_pressure_insuff_4_valid : 1; //!< Д[ГС-А026] Достоверность давления наддува в баке ГС4
   uint16_t gs_pressure_1_130          : 1; //!< [ГС-Д001] Давление в ГС1 мало (меньше 130 кгс/кв.см)
   uint16_t gs_pressure_2_130          : 1; //!< [ГС-Д002] Давление в ГС2 мало (меньше 130 кгс/кв.см)
   uint16_t gs_pressure_3_130          : 1; //!< [ГС-Д003] Давление в ГС3 мало (меньше 130 кгс/кв.см)
   uint16_t gs_pressure_4_130          : 1; //!< [ГС-Д004] Давление в ГС4 мало (меньше 130 кгс/кв.см)
   uint16_t gs_oil_level_1_min         : 1; //!< [ГС-Д005] Минимальный уровень жидкости в баке ГС1
   uint16_t gs_oil_level_2_min         : 1; //!< [ГС-Д006] Минимальный уровень жидкости в баке ГС2
   uint16_t gs_oil_level_3_min         : 1; //!< [ГС-Д007] Минимальный уровень жидкости в баке ГС3
   uint16_t gs_oil_level_4_min         : 1; //!< [ГС-Д008] Минимальный уровень жидкости в баке ГС4
   uint16_t gs_tnuk_1_active           : 1; //!< [ГС-Д009] ТНУК ГС1 работает
   uint16_t gs_tnuk_2_active           : 1; //!< [ГС-Д010] ТНУК ГС2 работает
   uint16_t gs_tnuk_3_active           : 1; //!< [ГС-Д011] ТНУК ГС3 работает
   uint16_t gs_tnuk_4_active           : 1; //!< [ГС-Д012] ТНУК ГС4 работает
} skv_gs_flag_word_6_b_t;

//! Слово 7 сигналов СКВ/КИСЛ/ГС/МПУ
typedef struct skv_gs_flag_word_7_b_t {
   uint16_t gs_pump_1_not_active : 1; //!< [ГС-Д017] Насос Н1 не работает
   uint16_t gs_pump_2_not_active : 1; //!< [ГС-Д018] Насос Н2 не работает
   uint16_t gs_pump_3_not_active : 1; //!< [ГС-Д019] Насос Н3 не работает
   uint16_t gs_pump_4_not_active : 1; //!< [ГС-Д020] Насос Н4 не работает
   uint16_t gs_pump_5_not_active : 1; //!< [ГС-Д021] Насос Н5 не работает
   uint16_t gs_pump_6_not_active : 1; //!< [ГС-Д022] Насос Н6 не работает
   uint16_t gs_pump_7_not_active : 1; //!< [ГС-Д023] Насос Н7 не работает
   uint16_t gs_pump_8_not_active : 1; //!< [ГС-Д024] Насос Н8 не работает
   uint16_t gs_pump_1_off        : 1; //!< [ГС-Д025] Насос Н1 отключен
   uint16_t gs_pump_2_off        : 1; //!< [ГС-Д026] Насос Н2 отключен
   uint16_t gs_pump_3_off        : 1; //!< [ГС-Д027] Насос Н3 отключен
   uint16_t gs_pump_4_off        : 1; //!< [ГС-Д028] Насос Н4 отключен
   uint16_t gs_pump_5_off        : 1; //!< [ГС-Д029] Насос Н5 отключен
   uint16_t gs_pump_6_off        : 1; //!< [ГС-Д030] Насос Н6 отключен
   uint16_t gs_pump_7_off        : 1; //!< [ГС-Д031] Насос Н7 отключен
   uint16_t gs_pump_8_off        : 1; //!< [ГС-Д032] Насос Н8 отключен
} skv_gs_flag_word_7_b_t;

//! Слово 1 сигналов СМК/СУПК
typedef struct smk_supk_flag_word_1_b_t {
   uint16_t flap_fail            : 1; //!< [СМК-Д001] Отказ закрылков
   uint16_t slat_fail            : 1; //!< [СМК-Д002] Отказ предкрылков
   uint16_t flap_jam             : 1; //!< [СМК-Д003] Заклинивание трансмиссии закрылков
   uint16_t slat_jam             : 1; //!< [СМК-Д004] Заклинивание трансмиссии предкрылков
   uint16_t flap_corr_fail       : 1; //!< [СМК-Д005] Отказ коррекции закрылков
   uint16_t flap_slat_track      : 1; //!< [СМК-Д006] Следящий режим закрылков-предкрылков
   uint16_t flap_slat_track_fail : 1; //!< [СМК-Д007] Отказ следящего режима закрылков-предкрылков
   uint16_t flap_slat_reserve    : 1; //!< [СМК-Д008] Резервный режим закрылков-предкрылков
   uint16_t flap_async           : 1; //!< [СМК-Д009] Рассинхронизация закрылков
   uint16_t slat_async           : 1; //!< [СМК-Д010] Рассинхронизация предкрылков
   uint16_t flap_increase_active : 1; //!< [СМК-Д011] Выпуск закрылков
   uint16_t flap_decrease_active : 1; //!< [СМК-Д012] Уборка закрылков
   uint16_t slat_increase_active : 1; //!< [СМК-Д013] Выпуск предкрылков
   uint16_t slat_decrease_active : 1; //!< [СМК-Д014] Уборка предкрылков
   uint16_t flap_not_ready       : 1; //!< [СМК-Д015] Закрылки не во взлетном положении
   uint16_t wing_fail            : 1; //!< [СМК-Д016] Отказ управления консолями крыла
} smk_supk_flag_word_1_b_t;

//! Слово 2 сигналов СМК/СУПК
typedef struct smk_supk_flag_word_2_b_t {
   uint16_t wing_track_fail      : 1; //!< [СМК-Д017] Отказ следящего режима крыла
   uint16_t wing_jam             : 1; //!< [СМК-Д018] Заклинивание трансмиссии консолей крыла
   uint16_t wing_reserve         : 1; //!< [СМК-Д019] Резервный режим крыла
   uint16_t wing_async           : 1; //!< [СМК-Д020] Рассинхронизация консолей крыла
   uint16_t wing_increase_active : 1; //!< [СМК-Д021] Выпуск консолей крыла
   uint16_t wing_decrease_active : 1; //!< [СМК-Д022] Уборка консолей крыла
   uint16_t flag_23              : 1; //!< [СМК-Д023] Резерв
   uint16_t flap_l_slow          : 1; //!< [СМК-Д024] Срабатывание тормоза левых закрылков
   uint16_t flap_r_slow          : 1; //!< [СМК-Д025] Срабатывание тормоза правых закрылков
   uint16_t spk_failure          : 1; //!< [СМК] Нет информации от СПК
   uint16_t spmk_failure         : 1; //!< [СМК] Нет информации от СПМК
   uint16_t steering_valid       : 1; //!< [СУПК-Д001/СУПК-Д002] Поворот колес (канал 1/2), исправность
   uint16_t taxing               : 1; //!< [СУПК-Д003/СУПК-Д004] Колеса руление (канал 1/2)
   uint16_t supk_failure         : 1; //!< [ОИ-Л001/ОИ-Л002] Отсутствие информации от канала 1/2 СУПК (канал обесточен, нет связи или полный отказ)
   uint16_t                      : 2; //!< Резерв
} smk_supk_flag_word_2_b_t;

//! Слово 1 сигналов СЭС
typedef struct sas_flag_word_1_b_t {
   uint16_t u115_gen1_on               : 1; //!< [СЭС-Д205] Сеть 115В: Генератор 1 включен
   uint16_t u115_gen2_on               : 1; //!< [СЭС-Д206] Сеть 115В: Генератор 2 включен
   uint16_t u115_gen3_on               : 1; //!< [СЭС-Д207] Сеть 115В: Генератор 3 включен
   uint16_t u115_gen4_on               : 1; //!< [СЭС-Д208] Сеть 115В: Генератор 4 включен
   uint16_t u115_vsu_active            : 1; //!< [СЭС-Д213] Сеть 115В: Генератор ВСУ работает
   uint16_t u115_brzu_gen1_failure     : 1; //!< [СЭС-Д214] Сеть 115В: Неисправность БРЗУ генератора 1
   uint16_t u115_brzu_gen2_failure     : 1; //!< [СЭС-Д215] Сеть 115В: Неисправность БРЗУ генератора 2
   uint16_t u115_brzu_gen3_failure     : 1; //!< [СЭС-Д216] Сеть 115В: Неисправность БРЗУ генератора 3
   uint16_t u115_brzu_gen4_failure     : 1; //!< [СЭС-Д217] Сеть 115В: Неисправность БРЗУ генератора 4
   uint16_t u115_brzu_vsu_failure      : 1; //!< [СЭС-Д218] Сеть 115В: Неисправность БРЗУ генератора ВСУ
   uint16_t u115_ppo_gen1_failure      : 1; //!< [СЭС–Д219] Сеть 115В: Неисправность ППО генератора 1
   uint16_t u115_ppo_gen2_failure      : 1; //!< [СЭС–Д220] Сеть 115В: Неисправность ППО генератора 2
   uint16_t u115_ppo_gen3_failure      : 1; //!< [СЭС–Д221] Сеть 115В: Неисправность ППО генератора 3
   uint16_t u115_ppo_gen4_failure      : 1; //!< [СЭС–Д222] Сеть 115В: Неисправность ППО генератора 4
   uint16_t u115_ppo_gen1_low_pressure : 1; //!< [СЭС–Д227] Сеть 115В: ППО генератора 1 (Р мало) отключи
   uint16_t u115_ppo_gen2_low_pressure : 1; //!< [СЭС–Д228] Сеть 115В: ППО генератора 2 (Р мало) отключи
} sas_flag_word_1_b_t;

//! Слово 2 сигналов СЭС
typedef struct sas_flag_word_2_b_t {
   uint16_t u115_ppo_gen3_low_pressure : 1; //!< [СЭС–Д229] Сеть 115В: ППО генератора 3 (Р мало) отключи
   uint16_t u115_ppo_gen4_low_pressure : 1; //!< [СЭС–Д230] Сеть 115В: ППО генератора 4 (Р мало) отключи
   uint16_t u115_rap_on                : 1; //!< [СЭС-Д234] Сеть 115В: РАП включен
   uint16_t u115_vsu_on                : 1; //!< [СЭС-Д235] Сеть 115В: Генератор ВСУ включен
   uint16_t u115_conv1_on              : 1; //!< [СЭС-Д236] Сеть 115В: Преобразователь 1 включен
   uint16_t u115_conv3_on              : 1; //!< [СЭС-Д238] Сеть 115В: Преобразователь 3 включен
   uint16_t u115_conv1_connected       : 1; //!< [СЭС-Д239] Сеть 115В: Преобразователь 1 подключен к шине преобразователя 1
   uint16_t u115_conv3_connected_l     : 1; //!< [СЭС-Д241] Сеть 115В: Преобразователь 3 подключен к шине преобразователя 3 левой
   uint16_t u115_conv3_connected_r     : 1; //!< [СЭС-Д242] Сеть 115В: Преобразователь 3 подключен к шине преобразователя 3 правой
   uint16_t u115_emrg_connected_l      : 1; //!< [СЭС-Д243] Сеть 115В: Аварийная левая шина подключена
   uint16_t u115_emrg_connected_r      : 1; //!< [СЭС-Д244] Сеть 115В: Аварийная правая шина подключена
   uint16_t u115_gen1_turned_off       : 1; //!< [СЭС-Л001] Сеть 115В: Запоминание сигнала отключения генератора 1 при его отказе
   uint16_t u115_gen2_turned_off       : 1; //!< [СЭС-Л002] Сеть 115В: Запоминание сигнала отключения генератора 2 при его отказе
   uint16_t u115_gen3_turned_off       : 1; //!< [СЭС-Л003] Сеть 115В: Запоминание сигнала отключения генератора 3 при его отказе
   uint16_t u115_gen4_turned_off       : 1; //!< [СЭС-Л004] Сеть 115В: Запоминание сигнала отключения генератора 4 при его отказе
   uint16_t u115_vsu_turned_off        : 1; //!< [СЭС-Л005] Сеть 115В: Запоминание сигнала отключения генератора ВСУ при его отказе
} sas_flag_word_2_b_t;

//! Слово 3 сигналов СЭС
typedef struct sas_flag_word_3_b_t {
   uint16_t u27_gen1_on         : 1; //!< [СЭС-Д305] Сеть 27В: Генератор 1 включен
   uint16_t u27_gen2_on         : 1; //!< [СЭС-Д306] Сеть 27В: Генератор 2 включен
   uint16_t u27_gen3_on         : 1; //!< [СЭС-Д307] Сеть 27В: Генератор 3 включен
   uint16_t u27_gen4_on         : 1; //!< [СЭС-Д308] Сеть 27В: Генератор 4 включен
   uint16_t u27_turn_off_gen1   : 1; //!< [СЭС-Д313] Сеть 27В: Генератор 1 отключи
   uint16_t u27_turn_off_gen2   : 1; //!< [СЭС-Д314] Сеть 27В: Генератор 2 отключи
   uint16_t u27_turn_off_gen3   : 1; //!< [СЭС-Д315] Сеть 27В: Генератор 3 отключи
   uint16_t u27_turn_off_gen4   : 1; //!< [СЭС-Д316] Сеть 27В: Генератор 4 отключи
   uint16_t u27_batt1_overheat  : 1; //!< [СЭС-Д317] Сеть 27В: Аккумулятора 1 перегрев
   uint16_t u27_batt2_overheat  : 1; //!< [СЭС-Д318] Сеть 27В: Аккумулятора 2 перегрев
   uint16_t u27_batt1_on        : 1; //!< [СЭС-Д319] Сеть 27В: Аккумулятор 1 включен
   uint16_t u27_batt2_on        : 1; //!< [СЭС-Д320] Сеть 27В: Аккумулятор 2 включен
   uint16_t u27_rap1_on         : 1; //!< [СЭС-Д326] Сеть 27В: РАП1 включен
   uint16_t u27_rap2_on         : 1; //!< [СЭС-Д327] Сеть 27В: РАП2 включен
   uint16_t u27_vsu_on          : 1; //!< [СЭС-Д328] Сеть 27В: Генератор ВСУ включен
   uint16_t u27_vsu_active      : 1; //!< [СЭС-Д329] Сеть 27В: Генератор ВСУ работает
} sas_flag_word_3_b_t;

//! Слово 4 сигналов СЭС
typedef struct sas_flag_word_4_b_t {
   uint16_t u27_main1_connected    : 1; //!< [СЭС-Д330] Сеть 27В: Основные шины 1 объединены
   uint16_t u27_main2_connected    : 1; //!< [СЭС-Д331] Сеть 27В: Основные шины 2 объединены
   uint16_t u27_emrg_connected     : 1; //!< [СЭС-Д332] Сеть 27В: Аварийные шины объединены
   uint16_t u27_onoff1_connected_l : 1; //!< [СЭС-Д333] Сеть 27В: Отключаемые шины 1 левого борта подключены
   uint16_t u27_onoff2_connected_l : 1; //!< [СЭС-Д334] Сеть 27В: Отключаемые шины 2 левого борта подключены
   uint16_t u27_onoff1_connected_r : 1; //!< [СЭС-Д335] Сеть 27В: Отключаемые шины 1 правого борта подключены
   uint16_t u27_onoff2_connected_r : 1; //!< [СЭС-Д336] Сеть 27В: Отключаемые шины 2 правого борта подключены
   uint16_t u27_bus_disconnected   : 1; //!< [СЭС-Д337] Сеть 27В: Основные и аварийные шины левой и правой сети разделены
   uint16_t u27_ground_mode        : 1; //!< [СЭС-Д346] Сеть 27В: Режим "земля"
   uint16_t                        : 7; //!< Резерв
} sas_flag_word_4_b_t;

//! Слово 1 сигналов ТОРМ
typedef struct torm_flag_word_1_b_t {
   uint16_t flag_401              : 1; //!< [ТОРМ-Д401] Резерв
   uint16_t brakes_pair_failure   : 1; //!< [ТОРМ-Д402] Одна пара тормозов отказ при включенных основных тормозах
   uint16_t brakes_on             : 1; //!< [ТОРМ-Д403] Тормоза основные включены
   uint16_t brakes_start_on       : 1; //!< [ТОРМ-Д404] Стартовый тормоз включен
   uint16_t brakes_slight_off     : 1; //!< [ТОРМ-Д405] Автоматическое торможение СЛАБО, торможение основной системы не включено
   uint16_t brakes_slight_on      : 1; //!< [ТОРМ-Д406] Автоматическое торможение СЛАБО, основная система
   uint16_t brakes_low_off        : 1; //!< [ТОРМ-Д407] Автоматическое торможение ПОНИЖ, торможение основной системы не включено
   uint16_t brakes_low_on         : 1; //!< [ТОРМ-Д408] Автоматическое торможение ПОНИЖ, основная система
   uint16_t brakes_normal_off     : 1; //!< [ТОРМ-Д409] Автоматическое торможение НОРМ, торможение основной системы не включено
   uint16_t brakes_normal_on      : 1; //!< [ТОРМ-Д410] Автоматическое торможение НОРМ, основная система
   uint16_t brakes_auto_off       : 1; //!< [ТОРМ-Д411] Автоматическое торможение отключено от основной системы
   uint16_t forcing_ready         : 1; //!< [ТОРМ-Д418] Готовность к включению форсированного торможения, основная система
   uint16_t forcing_on            : 1; //!< [ТОРМ-Д419] Форсированное торможение включено, основная система
   uint16_t main_brakes_failure_2 : 1; //!< [ТОРМ-Д420] Отказ основной системы тормозов (отказ подсистемы)
   uint16_t                       : 2; //!< Резерв
} torm_flag_word_1_b_t;

//! Слово 2 сигналов ТОРМ
typedef struct torm_flag_word_2_b_t {
   uint16_t flag_601            : 1; //!< [ТОРМ-Д601] Резерв
   uint16_t brakes_pair_failure : 1; //!< [ТОРМ-Д602] Одна пара тормозов отказ при включенных резервных тормозах
   uint16_t flag_603            : 1; //!< [ТОРМ-Д603] Резерв
   uint16_t parking_on          : 1; //!< [ТОРМ-Д604] Стояночный тормоз включен
   uint16_t brakes_slight_off   : 1; //!< [ТОРМ-Д605] Автоматическое торможение СЛАБО, торможение резервной системы не включено
   uint16_t brakes_slight_on    : 1; //!< [ТОРМ-Д606] Автоматическое торможение СЛАБО, резервная система
   uint16_t brakes_low_off      : 1; //!< [ТОРМ-Д607] Автоматическое торможение ПОНИЖ, торможение резервной системы не включено
   uint16_t brakes_low_on       : 1; //!< [ТОРМ-Д608] Автоматическое торможение ПОНИЖ, резервная система
   uint16_t brakes_normal_off   : 1; //!< [ТОРМ-Д609] Автоматическое торможение НОРМ, торможение резервной системы не включено
   uint16_t brakes_normal_on    : 1; //!< [ТОРМ-Д610] Автоматическое торможение НОРМ, резервная система
   uint16_t brakes_auto_off     : 1; //!< [ТОРМ-Д611] Автоматическое торможение отключено от резервной системы
   uint16_t forcing_ready       : 1; //!< [ТОРМ-Д618] Готовность к включению форсированного торможения, резервная система
   uint16_t forcing_on          : 1; //!< [ТОРМ-Д619] Форсированное торможение включено, резервная система
   uint16_t                     : 3; //!< Резерв
} torm_flag_word_2_b_t;

//! Слово 1 сигналов ТОПЛ
typedef struct topl_flag_word_1_b_t {
   uint16_t valve_b1l_opened         : 1; //!< [ТОПЛ-Д008] Открытие заправочного крана бака Б1Л
   uint16_t valve_b1l_closed         : 1; //!< [ТОПЛ-Д009] Закрытие заправочного крана бака Б1Л
   uint16_t valve_b1l_fail_open      : 1; //!< [ТОПЛ-Д010] Ложное открытие заправочного крана бака Б1Л
   uint16_t valve_b1l_fail_close     : 1; //!< [ТОПЛ-Д011] Ложное закрытие заправочного крана бака Б1Л
   uint16_t valve_b1l_fail_vis_open  : 1; //!< [ТОПЛ-Д012] Ложная индикация открытия заправочного крана бака Б1Л
   uint16_t valve_b1l_fail_vis_close : 1; //!< [ТОПЛ-Д013] Ложная индикация закрытия заправочного крана бака Б1Л
   uint16_t valve_b1l_not_vis_open   : 1; //!< [ТОПЛ-Д014] Отказ индикации открытия заправочного крана бака Б1Л
   uint16_t valve_b1l_not_vis_close  : 1; //!< [ТОПЛ-Д015] Отказ индикации закрытия заправочного крана бака Б1Л
   uint16_t valve_b1r_opened         : 1; //!< [ТОПЛ-Д016] Открытие заправочного крана бака Б1П
   uint16_t valve_b1r_closed         : 1; //!< [ТОПЛ-Д017] Закрытие заправочного крана бака Б1П
   uint16_t valve_b1r_fail_open      : 1; //!< [ТОПЛ-Д018] Ложное открытие заправочного крана бака Б1П
   uint16_t valve_b1r_fail_close     : 1; //!< [ТОПЛ-Д019] Ложное закрытие заправочного крана бака Б1П
   uint16_t valve_b1r_fail_vis_open  : 1; //!< [ТОПЛ-Д020] Ложная индикация открытия заправочного крана бака Б1П
   uint16_t valve_b1r_fail_vis_close : 1; //!< [ТОПЛ-Д021] Ложная индикация закрытия заправочного крана бака Б1П
   uint16_t valve_b1r_not_vis_open   : 1; //!< [ТОПЛ-Д022] Отказ индикации открытия заправочного крана бака Б1П
   uint16_t valve_b1r_not_vis_close  : 1; //!< [ТОПЛ-Д023] Отказ индикации закрытия заправочного крана бака Б1П
} topl_flag_word_1_b_t;

//! Слово 2 сигналов ТОПЛ
typedef struct topl_flag_word_2_b_t {
   uint16_t valve_b2l_opened         : 1; //!< [ТОПЛ-Д024] Открытие заправочного крана бака Б2Л
   uint16_t valve_b2l_closed         : 1; //!< [ТОПЛ-Д025] Закрытие заправочного крана бака Б2Л
   uint16_t valve_b2l_fail_open      : 1; //!< [ТОПЛ-Д026] Ложное открытие заправочного крана бака Б2Л
   uint16_t valve_b2l_fail_close     : 1; //!< [ТОПЛ-Д027] Ложное закрытие заправочного крана бака Б2Л
   uint16_t valve_b2l_fail_vis_open  : 1; //!< [ТОПЛ-Д028] Ложная индикация открытия заправочного крана бака Б2Л
   uint16_t valve_b2l_fail_vis_close : 1; //!< [ТОПЛ-Д029] Ложная индикация закрытия заправочного крана бака Б2Л
   uint16_t valve_b2l_not_vis_open   : 1; //!< [ТОПЛ-Д030] Отказ индикации открытия заправочного крана бака Б2Л
   uint16_t valve_b2l_not_vis_close  : 1; //!< [ТОПЛ-Д031] Отказ индикации закрытия заправочного крана бака Б2Л
   uint16_t valve_b2r_opened         : 1; //!< [ТОПЛ-Д032] Открытие заправочного крана бака Б2П
   uint16_t valve_b2r_closed         : 1; //!< [ТОПЛ-Д033] Закрытие заправочного крана бака Б2П
   uint16_t valve_b2r_fail_open      : 1; //!< [ТОПЛ-Д034] Ложное открытие заправочного крана бака Б2П
   uint16_t valve_b2r_fail_close     : 1; //!< [ТОПЛ-Д035] Ложное закрытие заправочного крана бака Б2П
   uint16_t valve_b2r_fail_vis_open  : 1; //!< [ТОПЛ-Д036] Ложная индикация открытия заправочного крана бака Б2П
   uint16_t valve_b2r_fail_vis_close : 1; //!< [ТОПЛ-Д037] Ложная индикация закрытия заправочного крана бака Б2П
   uint16_t valve_b2r_not_vis_open   : 1; //!< [ТОПЛ-Д038] Отказ индикации открытия заправочного крана бака Б2П
   uint16_t valve_b2r_not_vis_close  : 1; //!< [ТОПЛ-Д039] Отказ индикации закрытия заправочного крана бака Б2П
} topl_flag_word_2_b_t;

//! Слово 3 сигналов ТОПЛ
typedef struct topl_flag_word_3_b_t {
   uint16_t valve_b3l_opened         : 1; //!< [ТОПЛ-Д040] Открытие заправочного крана бака Б3Л
   uint16_t valve_b3l_closed         : 1; //!< [ТОПЛ-Д041] Закрытие заправочного крана бака Б3Л
   uint16_t valve_b3l_fail_open      : 1; //!< [ТОПЛ-Д042] Ложное открытие заправочного крана бака Б3Л
   uint16_t valve_b3l_fail_close     : 1; //!< [ТОПЛ-Д043] Ложное закрытие заправочного крана бака Б3Л
   uint16_t valve_b3l_fail_vis_open  : 1; //!< [ТОПЛ-Д044] Ложная индикация открытия заправочного крана бака Б3Л
   uint16_t valve_b3l_fail_vis_close : 1; //!< [ТОПЛ-Д045] Ложная индикация закрытия заправочного крана бака Б3Л
   uint16_t valve_b3l_not_vis_open   : 1; //!< [ТОПЛ-Д046] Отказ индикации открытия заправочного крана бака Б3Л
   uint16_t valve_b3l_not_vis_close  : 1; //!< [ТОПЛ-Д047] Отказ индикации закрытия заправочного крана бака Б3Л
   uint16_t valve_b3r_opened         : 1; //!< [ТОПЛ-Д048] Открытие заправочного крана бака Б3П
   uint16_t valve_b3r_closed         : 1; //!< [ТОПЛ-Д049] Закрытие заправочного крана бака Б3П
   uint16_t valve_b3r_fail_open      : 1; //!< [ТОПЛ-Д050] Ложное открытие заправочного крана бака Б3П
   uint16_t valve_b3r_fail_close     : 1; //!< [ТОПЛ-Д051] Ложное закрытие заправочного крана бака Б3П
   uint16_t valve_b3r_fail_vis_open  : 1; //!< [ТОПЛ-Д052] Ложная индикация открытия заправочного крана бака Б3П
   uint16_t valve_b3r_fail_vis_close : 1; //!< [ТОПЛ-Д053] Ложная индикация закрытия заправочного крана бака Б3П
   uint16_t valve_b3r_not_vis_open   : 1; //!< [ТОПЛ-Д054] Отказ индикации открытия заправочного крана бака Б3П
   uint16_t valve_b3r_not_vis_close  : 1; //!< [ТОПЛ-Д055] Отказ индикации закрытия заправочного крана бака Б3П
} topl_flag_word_3_b_t;

//! Слово 4 сигналов ТОПЛ
typedef struct topl_flag_word_4_b_t {
   uint16_t valve_b4l_opened         : 1; //!< [ТОПЛ-Д056] Открытие заправочного крана бака Б4Л
   uint16_t valve_b4l_closed         : 1; //!< [ТОПЛ-Д057] Закрытие заправочного крана бака Б4Л
   uint16_t valve_b4l_fail_open      : 1; //!< [ТОПЛ-Д058] Ложное открытие заправочного крана бака Б4Л
   uint16_t valve_b4l_fail_close     : 1; //!< [ТОПЛ-Д059] Ложное закрытие заправочного крана бака Б4Л
   uint16_t valve_b4l_fail_vis_open  : 1; //!< [ТОПЛ-Д060] Ложная индикация открытия заправочного крана бака Б4Л
   uint16_t valve_b4l_fail_vis_close : 1; //!< [ТОПЛ-Д061] Ложная индикация закрытия заправочного крана бака Б4Л
   uint16_t valve_b4l_not_vis_open   : 1; //!< [ТОПЛ-Д062] Отказ индикации открытия заправочного крана бака Б4Л
   uint16_t valve_b4l_not_vis_close  : 1; //!< [ТОПЛ-Д063] Отказ индикации закрытия заправочного крана бака Б4Л
   uint16_t valve_b4r_opened         : 1; //!< [ТОПЛ-Д064] Открытие заправочного крана бака Б4П
   uint16_t valve_b4r_closed         : 1; //!< [ТОПЛ-Д065] Закрытие заправочного крана бака Б4П
   uint16_t valve_b4r_fail_open      : 1; //!< [ТОПЛ-Д066] Ложное открытие заправочного крана бака Б4П
   uint16_t valve_b4r_fail_close     : 1; //!< [ТОПЛ-Д067] Ложное закрытие заправочного крана бака Б4П
   uint16_t valve_b4r_fail_vis_open  : 1; //!< [ТОПЛ-Д068] Ложная индикация открытия заправочного крана бака Б4П
   uint16_t valve_b4r_fail_vis_close : 1; //!< [ТОПЛ-Д069] Ложная индикация закрытия заправочного крана бака Б4П
   uint16_t valve_b4r_not_vis_open   : 1; //!< [ТОПЛ-Д070] Отказ индикации открытия заправочного крана бака Б4П
   uint16_t valve_b4r_not_vis_close  : 1; //!< [ТОПЛ-Д071] Отказ индикации закрытия заправочного крана бака Б4П
} topl_flag_word_4_b_t;

//! Слово 5 сигналов ТОПЛ
typedef struct topl_flag_word_5_b_t {
   uint16_t valve_b5_opened          : 1; //!< [ТОПЛ-Д072] Открытие заправочного крана бака Б5
   uint16_t valve_b5_closed          : 1; //!< [ТОПЛ-Д073] Закрытие заправочного крана бака Б5
   uint16_t valve_b5_fail_open       : 1; //!< [ТОПЛ-Д074] Ложное открытие заправочного крана бака Б5
   uint16_t valve_b5_fail_close      : 1; //!< [ТОПЛ-Д075] Ложное закрытие заправочного крана бака Б5
   uint16_t valve_b5_fail_vis_open   : 1; //!< [ТОПЛ-Д076] Ложная индикация открытия заправочного крана бака Б5
   uint16_t valve_b5_fail_vis_close  : 1; //!< [ТОПЛ-Д077] Ложная индикация закрытия заправочного крана бака Б5
   uint16_t valve_b5_not_vis_open    : 1; //!< [ТОПЛ-Д078] Отказ индикации открытия заправочного крана бака Б5
   uint16_t valve_b5_not_vis_close   : 1; //!< [ТОПЛ-Д079] Отказ индикации закрытия заправочного крана бака Б5
   uint16_t valve_b6_opened          : 1; //!< [ТОПЛ-Д080] Открытие заправочного крана бака Б6
   uint16_t valve_b6_closed          : 1; //!< [ТОПЛ-Д081] Закрытие заправочного крана бака Б6
   uint16_t valve_b6_fail_open       : 1; //!< [ТОПЛ-Д082] Ложное открытие заправочного крана бака Б6
   uint16_t valve_b6_fail_close      : 1; //!< [ТОПЛ-Д083] Ложное закрытие заправочного крана бака Б6
   uint16_t valve_b6_fail_vis_open   : 1; //!< [ТОПЛ-Д084] Ложная индикация открытия заправочного крана бака Б6
   uint16_t valve_b6_fail_vis_close  : 1; //!< [ТОПЛ-Д085] Ложная индикация закрытия заправочного крана бака Б6
   uint16_t valve_b6_not_vis_open    : 1; //!< [ТОПЛ-Д086] Отказ индикации открытия заправочного крана бака Б6
   uint16_t valve_b6_not_vis_close   : 1; //!< [ТОПЛ-Д087] Отказ индикации закрытия заправочного крана бака Б6
} topl_flag_word_5_b_t;

//! Слово 6 сигналов ТОПЛ
typedef struct topl_flag_word_6_b_t {
   uint16_t valve_rb1_opened         : 1; //!< [ТОПЛ-Д088] Открытие заправочного крана бака РБ1
   uint16_t valve_rb1_closed         : 1; //!< [ТОПЛ-Д089] Закрытие заправочного крана бака РБ1
   uint16_t valve_rb1_fail_open      : 1; //!< [ТОПЛ-Д090] Ложное открытие заправочного крана бака РБ1
   uint16_t valve_rb1_fail_close     : 1; //!< [ТОПЛ-Д091] Ложное закрытие заправочного крана бака РБ1
   uint16_t valve_rb1_fail_vis_open  : 1; //!< [ТОПЛ-Д092] Ложная индикация открытия заправочного крана бака РБ1
   uint16_t valve_rb1_fail_vis_close : 1; //!< [ТОПЛ-Д093] Ложная индикация закрытия заправочного крана бака РБ1
   uint16_t valve_rb1_not_vis_open   : 1; //!< [ТОПЛ-Д094] Отказ индикации открытия заправочного крана бака РБ1
   uint16_t valve_rb1_not_vis_close  : 1; //!< [ТОПЛ-Д095] Отказ индикации закрытия заправочного крана бака РБ1
   uint16_t valve_rb2_opened         : 1; //!< [ТОПЛ-Д096] Открытие заправочного крана бака РБ2
   uint16_t valve_rb2_closed         : 1; //!< [ТОПЛ-Д097] Закрытие заправочного крана бака РБ2
   uint16_t valve_rb2_fail_open      : 1; //!< [ТОПЛ-Д098] Ложное открытие заправочного крана бака РБ2
   uint16_t valve_rb2_fail_close     : 1; //!< [ТОПЛ-Д099] Ложное закрытие заправочного крана бака РБ2
   uint16_t valve_rb2_fail_vis_open  : 1; //!< [ТОПЛ-Д100] Ложная индикация открытия заправочного крана бака РБ2
   uint16_t valve_rb2_fail_vis_close : 1; //!< [ТОПЛ-Д101] Ложная индикация закрытия заправочного крана бака РБ2
   uint16_t valve_rb2_not_vis_open   : 1; //!< [ТОПЛ-Д102] Отказ индикации открытия заправочного крана бака РБ2
   uint16_t valve_rb2_not_vis_close  : 1; //!< [ТОПЛ-Д103] Отказ индикации закрытия заправочного крана бака РБ2
} topl_flag_word_6_b_t;

//! Слово 7 сигналов ТОПЛ
typedef struct topl_flag_word_7_b_t {
   uint16_t valve_rb3_opened         : 1; //!< [ТОПЛ-Д104] Открытие заправочного крана бака РБ3
   uint16_t valve_rb3_closed         : 1; //!< [ТОПЛ-Д105] Закрытие заправочного крана бака РБ3
   uint16_t valve_rb3_fail_open      : 1; //!< [ТОПЛ-Д106] Ложное открытие заправочного крана бака РБ3
   uint16_t valve_rb3_fail_close     : 1; //!< [ТОПЛ-Д107] Ложное закрытие заправочного крана бака РБ3
   uint16_t valve_rb3_fail_vis_open  : 1; //!< [ТОПЛ-Д108] Ложная индикация открытия заправочного крана бака РБ3
   uint16_t valve_rb3_fail_vis_close : 1; //!< [ТОПЛ-Д109] Ложная индикация закрытия заправочного крана бака РБ3
   uint16_t valve_rb3_not_vis_open   : 1; //!< [ТОПЛ-Д110] Отказ индикации открытия заправочного крана бака РБ3
   uint16_t valve_rb3_not_vis_close  : 1; //!< [ТОПЛ-Д111] Отказ индикации закрытия заправочного крана бака РБ3
   uint16_t valve_rb4_opened         : 1; //!< [ТОПЛ-Д112] Открытие заправочного крана бака РБ4
   uint16_t valve_rb4_closed         : 1; //!< [ТОПЛ-Д113] Закрытие заправочного крана бака РБ4
   uint16_t valve_rb4_fail_open      : 1; //!< [ТОПЛ-Д114] Ложное открытие заправочного крана бака РБ4
   uint16_t valve_rb4_fail_close     : 1; //!< [ТОПЛ-Д115] Ложное закрытие заправочного крана бака РБ4
   uint16_t valve_rb4_fail_vis_open  : 1; //!< [ТОПЛ-Д116] Ложная индикация открытия заправочного крана бака РБ4
   uint16_t valve_rb4_fail_vis_close : 1; //!< [ТОПЛ-Д117] Ложная индикация закрытия заправочного крана бака РБ4
   uint16_t valve_rb4_not_vis_open   : 1; //!< [ТОПЛ-Д118] Отказ индикации открытия заправочного крана бака РБ4
   uint16_t valve_rb4_not_vis_close  : 1; //!< [ТОПЛ-Д119] Отказ индикации закрытия заправочного крана бака РБ4
} topl_flag_word_7_b_t;

//! Слово 8 сигналов ТОПЛ
typedef struct topl_flag_word_8_b_t {
   uint16_t valve_kml_opened      : 1; //!< [ТОПЛ-Д120] Открытие крана КМЛ
   uint16_t valve_kml_fail_open   : 1; //!< [ТОПЛ-Д121] Ложное открытие крана КМЛ
   uint16_t valve_kml_fail_close  : 1; //!< [ТОПЛ-Д122] Ложное закрытие крана КМЛ
   uint16_t valve_kmr_opened      : 1; //!< [ТОПЛ-Д123] Открытие крана КМП
   uint16_t valve_kmr_fail_open   : 1; //!< [ТОПЛ-Д124] Ложное открытие крана КМП
   uint16_t valve_kmr_fail_close  : 1; //!< [ТОПЛ-Д125] Ложное закрытие крана КМП
   uint16_t valve_kpp1_opened     : 1; //!< [ТОПЛ-Д126] Открытие крана перекрестного питания КПП1
   uint16_t valve_kpp1_fail_open  : 1; //!< [ТОПЛ-Д127] Ложное открытие крана перекрестного питания КПП1
   uint16_t valve_kpp1_fail_close : 1; //!< [ТОПЛ-Д128] Ложное закрытие крана перекрестного питания КПП1
   uint16_t valve_kpp2_opened     : 1; //!< [ТОПЛ-Д129] Открытие крана перекрестного питания КПП2
   uint16_t valve_kpp2_fail_open  : 1; //!< [ТОПЛ-Д130] Ложное открытие крана перекрестного питания КПП2
   uint16_t valve_kpp2_fail_close : 1; //!< [ТОПЛ-Д131] Ложное закрытие крана перекрестного питания КПП2
   uint16_t valve_kpp3_opened     : 1; //!< [ТОПЛ-Д132] Открытие крана перекрестного питания КПП3
   uint16_t valve_kpp3_fail_open  : 1; //!< [ТОПЛ-Д133] Ложное открытие крана перекрестного питания КПП3
   uint16_t valve_kpp3_fail_close : 1; //!< [ТОПЛ-Д134] Ложное закрытие крана перекрестного питания КПП3
   uint16_t valve_kpp4_opened     : 1; //!< [ТОПЛ-Д135] Открытие крана перекрестного питания КПП4
} topl_flag_word_8_b_t;

//! Слово 9 сигналов ТОПЛ
typedef struct topl_flag_word_9_b_t {
   uint16_t valve_kpp4_fail_open  : 1; //!< [ТОПЛ-Д136] Ложное открытие крана перекрестного питания КПП4
   uint16_t valve_kpp4_fail_close : 1; //!< [ТОПЛ-Д137] Ложное закрытие крана перекрестного питания КПП4
   uint16_t valve_pk1_opened_kv   : 1; //!< [ТОПЛ-Д140] КВ ОТКР пожарного крана ПК1
   uint16_t valve_pk2_opened_kv   : 1; //!< [ТОПЛ-Д144] КВ ОТКР пожарного крана ПК2
   uint16_t valve_pk3_opened_kv   : 1; //!< [ТОПЛ-Д148] КВ ОТКР пожарного крана ПК3
   uint16_t valve_pk4_opened_kv   : 1; //!< [ТОПЛ-Д152] КВ ОТКР пожарного крана ПК4
   uint16_t b1l_pump1_on_press    : 1; //!< [ТОПЛ-Д154] Наличие давления за насосом №1 бака Б1Л
   uint16_t b1l_pump1_fail_start  : 1; //!< [ТОПЛ-Д155] Ложное включение насоса №1 бака Б1Л.
   uint16_t b1l_pump1_not_started : 1; //!< [ТОПЛ-Д156] Невключение насоса №1 бака Б1Л.
   uint16_t b1l_pump2_on_press    : 1; //!< [ТОПЛ-Д157] Наличие давления за насосом №2 бака Б1Л
   uint16_t b1l_pump2_fail_start  : 1; //!< [ТОПЛ-Д158] Ложное включение насоса №2 бака Б1Л
   uint16_t b1l_pump2_not_started : 1; //!< [ТОПЛ-Д159] Невключение насоса №2 бака Б1Л
   uint16_t b1r_pump1_on_press    : 1; //!< [ТОПЛ-Д160] Наличие давления за насосом №1 бака Б1П
   uint16_t b1r_pump1_fail_start  : 1; //!< [ТОПЛ-Д161] Ложное включение насоса №1 бака Б1П
   uint16_t b1r_pump1_not_started : 1; //!< [ТОПЛ-Д162] Невключение насоса №1 бака Б1П
   uint16_t b1r_pump2_on_press    : 1; //!< [ТОПЛ-Д163] Наличие давления за насосом №2 бака Б1П
} topl_flag_word_9_b_t;

//! Слово 10 сигналов ТОПЛ
typedef struct topl_flag_word_10_b_t {
   uint16_t b1r_pump2_fail_start  : 1; //!< [ТОПЛ-Д164] Ложное включение насоса №2 бака Б1П
   uint16_t b1r_pump2_not_started : 1; //!< [ТОПЛ-Д165] Невключение насоса №2 бака Б1П
   uint16_t b2l_pump1_on_press    : 1; //!< [ТОПЛ-Д166] Наличие давления за насосом №1 бака Б2Л
   uint16_t b2l_pump1_fail_start  : 1; //!< [ТОПЛ-Д167] Ложное включение насоса №1 бака Б2Л
   uint16_t b2l_pump1_not_started : 1; //!< [ТОПЛ-Д168] Невключение насоса №1 бака Б2Л
   uint16_t b2l_pump2_on_press    : 1; //!< [ТОПЛ-Д169] Наличие давления за насосом №2 бака Б2Л
   uint16_t b2l_pump2_fail_start  : 1; //!< [ТОПЛ-Д170] Ложное включение насоса №2 бака Б2Л
   uint16_t b2l_pump2_not_started : 1; //!< [ТОПЛ-Д171] Невключение насоса №2 бака Б2Л
   uint16_t b2r_pump1_on_press    : 1; //!< [ТОПЛ-Д172] Наличие давления за насосом №1 бака Б2П
   uint16_t b2r_pump1_fail_start  : 1; //!< [ТОПЛ-Д173] Ложное включение насоса №1 бака Б2П
   uint16_t b2r_pump1_not_started : 1; //!< [ТОПЛ-Д174] Невключение насоса №1 бака Б2П
   uint16_t b2r_pump2_on_press    : 1; //!< [ТОПЛ-Д175] Наличие давления за насосом №2 бака Б2П
   uint16_t b2r_pump2_fail_start  : 1; //!< [ТОПЛ-Д176] Ложное включение насоса №2 бака Б2П
   uint16_t b2r_pump2_not_started : 1; //!< [ТОПЛ-Д177] Невключение насоса №2 бака Б2П
   uint16_t b3l_pump1_on_press    : 1; //!< [ТОПЛ-Д178] Наличие давления за насосом №1 бака Б3Л
   uint16_t b3l_pump1_fail_start  : 1; //!< [ТОПЛ-Д179] Ложное включение насоса №1 бака Б3Л
} topl_flag_word_10_b_t;

//! Слово 11 сигналов ТОПЛ
typedef struct topl_flag_word_11_b_t {
   uint16_t b3l_pump1_not_started : 1; //!< [ТОПЛ-Д180] Невключение насоса №1 бака Б3Л
   uint16_t b3l_pump2_on_press    : 1; //!< [ТОПЛ-Д181] Наличие давления за насосом №2 бака Б3Л
   uint16_t b3l_pump2_fail_start  : 1; //!< [ТОПЛ-Д182] Ложное включение насоса №2 бака Б3Л
   uint16_t b3l_pump2_not_started : 1; //!< [ТОПЛ-Д183] Невключение насоса №2 бака Б3Л
   uint16_t b3l_pump3_on_press    : 1; //!< [ТОПЛ-Д184] Наличие давления за насосом №3 бака Б3Л
   uint16_t b3l_pump3_fail_start  : 1; //!< [ТОПЛ-Д185] Ложное включение насоса №3 бака Б3Л
   uint16_t b3l_pump3_not_started : 1; //!< [ТОПЛ-Д186] Невключение насоса №3 бака Б3Л
   uint16_t b3r_pump1_on_press    : 1; //!< [ТОПЛ-Д187] Наличие давления за насосом №1 бака Б3П
   uint16_t b3r_pump1_fail_start  : 1; //!< [ТОПЛ-Д188] Ложное включение насоса №1 бака Б3П
   uint16_t b3r_pump1_not_started : 1; //!< [ТОПЛ-Д189] Невключение насоса №1 бака Б3П
   uint16_t b3r_pump2_on_press    : 1; //!< [ТОПЛ-Д190] Наличие давления за насосом №2 бака Б3П
   uint16_t b3r_pump2_fail_start  : 1; //!< [ТОПЛ-Д191] Ложное включение насоса №2 бака Б3П
   uint16_t b3r_pump2_not_started : 1; //!< [ТОПЛ-Д192] Невключение насоса №2 бака Б3П
   uint16_t b3r_pump3_on_press    : 1; //!< [ТОПЛ-Д193] Наличие давления за насосом №3 бака Б3П
   uint16_t b3r_pump3_fail_start  : 1; //!< [ТОПЛ-Д194] Ложное включение насоса №3 бака Б3П
   uint16_t b3r_pump3_not_started : 1; //!< [ТОПЛ-Д195] Невключение насоса №3 бака Б3П
} topl_flag_word_11_b_t;

//! Слово 12 сигналов ТОПЛ
typedef struct topl_flag_word_12_b_t {
   uint16_t b4l_pump1_on_press    : 1; //!< [ТОПЛ-Д196] Наличие давления за насосом №1 бака Б4Л
   uint16_t b4l_pump1_fail_start  : 1; //!< [ТОПЛ-Д197] Ложное включение насоса №1 бака Б4Л
   uint16_t b4l_pump1_not_started : 1; //!< [ТОПЛ-Д198] Невключение насоса №1 бака Б4Л
   uint16_t b4l_pump2_on_press    : 1; //!< [ТОПЛ-Д199] Наличие давления за насосом №2 бака Б4Л
   uint16_t b4l_pump2_fail_start  : 1; //!< [ТОПЛ-Д200] Ложное включение насоса №2 бака Б4Л
   uint16_t b4l_pump2_not_started : 1; //!< [ТОПЛ-Д201] Невключение насоса №2 бака Б4Л
   uint16_t b4r_pump1_on_press    : 1; //!< [ТОПЛ-Д202] Наличие давления за насосом №1 бака Б4П
   uint16_t b4r_pump1_fail_start  : 1; //!< [ТОПЛ-Д203] Ложное включение насоса №1 бака Б4П
   uint16_t b4r_pump1_not_started : 1; //!< [ТОПЛ-Д204] Невключение насоса №1 бака Б4П
   uint16_t b4r_pump2_on_press    : 1; //!< [ТОПЛ-Д205] Наличие давления за насосом №2 бака Б4П
   uint16_t b4r_pump2_fail_start  : 1; //!< [ТОПЛ-Д206] Ложное включение насоса №2 бака Б4П
   uint16_t b4r_pump2_not_started : 1; //!< [ТОПЛ-Д207] Невключение насоса №2 бака Б4П
   uint16_t b5_pump1_on_press     : 1; //!< [ТОПЛ-Д208] Наличие давления за насосом №1 бака Б5
   uint16_t b5_pump1_fail_start   : 1; //!< [ТОПЛ-Д209] Ложное включение насоса №1 бака Б5
   uint16_t b5_pump1_not_started  : 1; //!< [ТОПЛ-Д210] Невключение насоса №1 бака Б5
   uint16_t b5_pump2_on_press     : 1; //!< [ТОПЛ-Д211] Наличие давления за насосом №2 бака Б5
} topl_flag_word_12_b_t;

//! Слово 13 сигналов ТОПЛ
typedef struct topl_flag_word_13_b_t {
   uint16_t b5_pump2_fail_start   : 1; //!< [ТОПЛ-Д212] Ложное включение насоса №2 бака Б5
   uint16_t b5_pump2_not_started  : 1; //!< [ТОПЛ-Д213] Невключение насоса №2 бака Б5
   uint16_t b6_pump1_on_press     : 1; //!< [ТОПЛ-Д214] Наличие давления за насосом №1 бака Б6
   uint16_t b6_pump1_fail_start   : 1; //!< [ТОПЛ-Д215] Ложное включение насоса №1 бака Б6
   uint16_t b6_pump1_not_started  : 1; //!< [ТОПЛ-Д216] Невключение насоса №1 бака Б6
   uint16_t b6_pump2_on_press     : 1; //!< [ТОПЛ-Д217] Наличие давления за насосом №2 бака Б6
   uint16_t b6_pump2_fail_start   : 1; //!< [ТОПЛ-Д218] Ложное включение насоса №2 бака Б6
   uint16_t b6_pump2_not_started  : 1; //!< [ТОПЛ-Д219] Невключение насоса №2 бака Б6
   uint16_t rb1_pump1_on_press    : 1; //!< [ТОПЛ-Д220] Наличие давления за насосом №1 бака РБ1
   uint16_t rb1_pump1_fail_start  : 1; //!< [ТОПЛ-Д221] Ложное включение насоса №1 бака РБ1
   uint16_t rb1_pump1_not_started : 1; //!< [ТОПЛ-Д222] Невключение насоса №1 бака РБ1
   uint16_t rb1_pump2_on_press    : 1; //!< [ТОПЛ-Д223] Наличие давления за насосом №2 бака РБ1
   uint16_t rb1_pump2_fail_start  : 1; //!< [ТОПЛ-Д224] Ложное включение насоса №2 бака РБ1
   uint16_t rb1_pump2_not_started : 1; //!< [ТОПЛ-Д225] Невключение насоса №2 бака РБ1
   uint16_t rb2_pump1_on_press    : 1; //!< [ТОПЛ-Д226] Наличие давления за насосом №1 бака РБ2
   uint16_t rb2_pump1_fail_start  : 1; //!< [ТОПЛ-Д227] Ложное включение насоса №1 бака РБ2
} topl_flag_word_13_b_t;

//! Слово 14 сигналов ТОПЛ
typedef struct topl_flag_word_14_b_t {
   uint16_t rb2_pump1_not_started : 1; //!< [ТОПЛ-Д228] Невключение насоса №1 бака РБ2
   uint16_t rb2_pump2_on_press    : 1; //!< [ТОПЛ-Д229] Наличие давления за насосом №2 бака РБ2
   uint16_t rb2_pump2_fail_start  : 1; //!< [ТОПЛ-Д230] Ложное включение насоса №2 бака РБ2
   uint16_t rb2_pump2_not_started : 1; //!< [ТОПЛ-Д231] Невключение насоса №2 бака РБ2
   uint16_t rb3_pump1_on_press    : 1; //!< [ТОПЛ-Д232] Наличие давления за насосом №1 бака РБ3
   uint16_t rb3_pump1_fail_start  : 1; //!< [ТОПЛ-Д233] Ложное включение насоса №1 бака РБ3
   uint16_t rb3_pump1_not_started : 1; //!< [ТОПЛ-Д234] Невключение насоса №1 бака РБ3
   uint16_t rb3_pump2_on_press    : 1; //!< [ТОПЛ-Д235] Наличие давления за насосом №2 бака РБ3
   uint16_t rb3_pump2_fail_start  : 1; //!< [ТОПЛ-Д236] Ложное включение насоса №2 бака РБ3
   uint16_t rb3_pump2_not_started : 1; //!< [ТОПЛ-Д237] Невключение насоса №2 бака РБ3
   uint16_t rb4_pump1_on_press    : 1; //!< [ТОПЛ-Д238] Наличие давления за насосом №1 бака РБ4
   uint16_t rb4_pump1_fail_start  : 1; //!< [ТОПЛ-Д239] Ложное включение насоса №1 бака РБ4
   uint16_t rb4_pump1_not_started : 1; //!< [ТОПЛ-Д240] Невключение насоса №1 бака РБ4
   uint16_t rb4_pump2_on_press    : 1; //!< [ТОПЛ-Д241] Наличие давления за насосом №2 бака РБ4
   uint16_t rb4_pump2_fail_start  : 1; //!< [ТОПЛ-Д242] Ложное включение насоса №2 бака РБ4
   uint16_t rb4_pump2_not_started : 1; //!< [ТОПЛ-Д243] Невключение насоса №2 бака РБ4
} topl_flag_word_14_b_t;

//! Слово 15 сигналов ТОПЛ
typedef struct topl_flag_word_15_b_t {
   uint16_t b1l_pump1_bal_on_press : 1; //!< [ТОПЛ-Д244] Наличие давления за балансировочным насосом №1 бака Б1Л
   uint16_t b1l_pump2_bal_on_press : 1; //!< [ТОПЛ-Д245] Наличие давления за балансировочным насосом №2 бака Б1Л
   uint16_t b1l_pump3_bal_on_press : 1; //!< [ТОПЛ-Д246] Наличие давления за балансировочным насосом №3 бака Б1Л
   uint16_t b1r_pump1_bal_on_press : 1; //!< [ТОПЛ-Д247] Наличие давления за балансировочным насосом №1 бака Б1П
   uint16_t b1r_pump2_bal_on_press : 1; //!< [ТОПЛ-Д248] Наличие давления за балансировочным насосом №2 бака Б1П
   uint16_t b1r_pump3_bal_on_press : 1; //!< [ТОПЛ-Д249] Наличие давления за балансировочным насосом №3 бака Б1П
   uint16_t b5_pump1_bal_on_press  : 1; //!< [ТОПЛ-Д250] Наличие давления за балансировочным насосом №1 бака Б5
   uint16_t b5_pump2_bal_on_press  : 1; //!< [ТОПЛ-Д251] Наличие давления за балансировочным насосом №2 бака Б5
   uint16_t b5_pump3_bal_on_press  : 1; //!< [ТОПЛ-Д252] Наличие давления за балансировочным насосом №3 бака Б5
   uint16_t b6_pump1_bal_on_press  : 1; //!< [ТОПЛ-Д253] Наличие давления за балансировочным насосом №1 бака Б6
   uint16_t b6_pump2_bal_on_press  : 1; //!< [ТОПЛ-Д254] Наличие давления за балансировочным насосом №2 бака Б6
   uint16_t b6_pump3_bal_on_press  : 1; //!< [ТОПЛ-Д255] Наличие давления за балансировочным насосом №3 бака Б6
   uint16_t level12_rb1            : 1; //!< [ТОПЛ-Д281] Остаток топлива 12т РБ1
   uint16_t level12_rb2            : 1; //!< [ТОПЛ-Д282] Остаток топлива 12т РБ2
   uint16_t level12_rb3            : 1; //!< [ТОПЛ-Д283] Остаток топлива 12т РБ3
   uint16_t level12_rb4            : 1; //!< [ТОПЛ-Д284] Остаток топлива 12т РБ4
} topl_flag_word_15_b_t;

//! Слово 16 сигналов ТОПЛ
typedef struct topl_flag_word_16_b_t {
   uint16_t valve_rod_take_control : 1; //!< [ТОПЛ-Д286] Штангой управляй
   uint16_t rod_out                : 1; //!< [ТОПЛ-Д289] Штанга выпущена
   uint16_t rod_off                : 1; //!< [ТОПЛ-Д290] Штанга убрана
   uint16_t air_switcher_on        : 1; //!< [ТОПЛ-Д295] Переключатель заправки в положении "ВОЗДУХ"
   uint16_t rb1_pump3_on_press     : 1; //!< [ТОПЛ-Д296] Наличие давления за насосом № 3 бака РБ1
   uint16_t rb1_pump3_fail_start   : 1; //!< [ТОПЛ-Д297] Ложное включение насоса № 3 бака РБ1
   uint16_t rb1_pump3_not_started  : 1; //!< [ТОПЛ-Д298] Невключение насоса № 3 бака РБ1
   uint16_t rb2_pump3_on_press     : 1; //!< [ТОПЛ-Д299] Наличие давления за насосом № 3 бака РБ2
   uint16_t rb2_pump3_fail_start   : 1; //!< [ТОПЛ-Д300] Ложное включение насоса № 3 бака РБ2
   uint16_t rb2_pump3_not_started  : 1; //!< [ТОПЛ-Д301] Невключение насоса № 3 бака РБ2
   uint16_t rb3_pump3_on_press     : 1; //!< [ТОПЛ-Д302] Наличие давления за насосом № 3 бака РБ3
   uint16_t rb3_pump3_fail_start   : 1; //!< [ТОПЛ-Д303] Ложное включение насоса № 3 бака РБ3
   uint16_t rb3_pump3_not_started  : 1; //!< [ТОПЛ-Д304] Невключение насоса № 3 бака РБ3
   uint16_t rb4_pump3_on_press     : 1; //!< [ТОПЛ-Д305] Наличие давления за насосом № 3 бака РБ4
   uint16_t rb4_pump3_fail_start   : 1; //!< [ТОПЛ-Д306] Ложное включение насоса № 3 бака РБ4
   uint16_t rb4_pump3_not_started  : 1; //!< [ТОПЛ-Д307] Невключение насоса № 3 бака РБ4
} topl_flag_word_16_b_t;

//! Слово сигналов шасси
typedef struct gears_flag_word_b_t {
   uint16_t comp_r1   : 1; //!< [ШАСС-Д001] Опора правая обжата (канал 1)
   uint16_t comp_r2   : 1; //!< [ШАСС-Д002] Опора правая обжата (канал 2)
   uint16_t out_r     : 1; //!< [ШАСС-Д003] Опора правая выпущена на подкосе
   uint16_t out_r_mbs : 1; //!< [ШАСС-Д004] Опора правая выпущена на МБС
   uint16_t off_r     : 1; //!< [ШАСС-Д005] Опора правая убрана
   uint16_t closed_r  : 1; //!< [ШАСС-Д006] Створки правой опоры закрыты
   uint16_t comp_l1   : 1; //!< [ШАСС-Д007] Опора левая обжата (канал 1)
   uint16_t comp_l2   : 1; //!< [ШАСС-Д008] Опора левая обжата (канал 2)
   uint16_t out_l     : 1; //!< [ШАСС-Д009] Опора левая выпущена на подкосе
   uint16_t out_l_mbs : 1; //!< [ШАСС-Д010] Опора левая выпущена на МБС
   uint16_t off_l     : 1; //!< [ШАСС-Д011] Опора левая убрана
   uint16_t closed_l  : 1; //!< [ШАСС-Д012] Створки левой опоры закрыты
   uint16_t out_f     : 1; //!< [ШАСС-Д013] Опора передняя выпущена
   uint16_t off_f     : 1; //!< [ШАСС-Д014] Опора передняя убрана
   uint16_t closed_f  : 1; //!< [ШАСС-Д015] Створки передней опоры закрыты
   uint16_t imitation : 1; //!< [ШАСС-Д019] Имитация "шасси не обжато" (сигнал ДВ/С)
} gears_flag_word_b_t;

//! Номера используемых ИНС/СВС
typedef struct ins_svs_numbers_b_t {
   uint16_t ins_number_k : 2; //!< [УПР-А002] Номер используемой ИНС для командира и навигатора (0 - нет данных) //(min:0 max:3)
   uint16_t ins_number_p : 2; //!< [УПР-А002] Номер используемой ИНС для помощника и оператора (0 - нет данных) //(min:0 max:3)
   uint16_t svs_number_k : 2; //!< [УПР-А003] Номер используемой СВС для командира и навигатора (0 - нет данных) //(min:0 max:3)
   uint16_t svs_number_p : 2; //!< [УПР-А003] Номер используемой СВС для помощника и оператора (0 - нет данных) //(min:0 max:3)
   uint16_t              : 8; //!< Резерв
} ins_svs_numbers_b_t;

//! Слово 1 достоверностей СВС/АБСУ/РТС
typedef struct svs_absu_rts_valid_word_1_b_t {
   uint16_t absu_alpha            : 1; //!< Д[АБСУ-А001] Достоверность угла атаки истинного
   uint16_t svs_altitude_abs_k    : 1; //!< Д[СВС-А001] Достоверность высоты абсолютной Набс для командира и навигатора
   uint16_t svs_altitude_abs_p    : 1; //!< Д[СВС-А001] Достоверность высоты абсолютной Набс для помощника и оператора
   uint16_t svs_indicated_speed_k : 1; //!< Д[СВС-А002] Достоверность приборной скорости для командира и навигатора
   uint16_t svs_indicated_speed_p : 1; //!< Д[СВС-А002] Достоверность приборной скорости для помощника и оператора
   uint16_t svs_mach_k            : 1; //!< Д[СВС-А003] Достоверность числа Маха для командира и навигатора
   uint16_t svs_mach_p            : 1; //!< Д[СВС-А003] Достоверность числа Маха для помощника и оператора
   uint16_t svs_altitude_qnh_k    : 1; //!< Д[СВС-А004] Достоверность высоты относительной НQNH для командира и навигатора
   uint16_t svs_altitude_qnh_p    : 1; //!< Д[СВС-А004] Достоверность высоты относительной НQNH для помощника и оператора
   uint16_t svs_altitude_qfe_k    : 1; //!< Д[СВС-А005] Достоверность высоты относительной НQFE для командира и навигатора
   uint16_t svs_altitude_qfe_p    : 1; //!< Д[СВС-А005] Достоверность высоты относительной НQFE для помощника и оператора
   uint16_t svs_pressure_qnh      : 1; //!< Д[СВС-А006] Достоверность барокоррекции QNH
   uint16_t svs_pressure_qfe      : 1; //!< Д[СВС-А007] Достоверность барокоррекции QFE
   uint16_t svs_vy_k              : 1; //!< Д[СВС-А008] Достоверность вертикальной скорости для командира и навигатора
   uint16_t svs_vy_p              : 1; //!< Д[СВС-А008] Достоверность вертикальной скорости для помощника и оператора
   uint16_t svs_temperature       : 1; //!< Д[СВС-А010] Достоверность температуры наружного воздуха
} svs_absu_rts_valid_word_1_b_t;

//! Слово 2 достоверностей СВС/АБСУ/РТС
typedef struct svs_absu_rts_valid_word_2_b_t {
   uint16_t svs_true_speed_k       : 1; //!< Д[СВС-А011] Достоверность скорости воздушной истинной для командира и навигатора
   uint16_t svs_true_speed_p       : 1; //!< Д[СВС-А011] Достоверность скорости воздушной истинной для помощника и оператора
   uint16_t vor1_azimuth           : 1; //!< Д[VIM-А001] Достоверность азимута на маяк VOR1 магнитного
   uint16_t vor1_frequency         : 1; //!< Д[VIM-А002] Достоверность частоты настройки на маяк VOR1
   uint16_t vor2_azimuth           : 1; //!< Д[VIM-А003] Достоверность азимута на маяк VOR2 магнитного
   uint16_t vor2_frequency         : 1; //!< Д[VIM-А004] Достоверность частоты настройки на маяк VOR2
   uint16_t ils1_frequency         : 1; //!< Д[VIM-А005] Достоверность частоты настройки ILS1
   uint16_t ils1_delta_x           : 1; //!< Д[VIM-А006] Достоверность отклонения от курса посадки ILS1
   uint16_t ils1_delta_y           : 1; //!< Д[VIM-А007] Достоверность отклонения от глиссады снижения ILS1
   uint16_t ils2_frequency         : 1; //!< Д[VIM-А005] Достоверность частоты настройки ILS2
   uint16_t ils2_delta_x           : 1; //!< Д[VIM-А006] Достоверность отклонения от курса посадки ILS2
   uint16_t ils2_delta_y           : 1; //!< Д[VIM-А007] Достоверность отклонения от глиссады снижения ILS2
   uint16_t dme1_distance          : 1; //!< Д[DME-А001] Достоверность дальности до радиомаяка DME1
   uint16_t dme1_frequency         : 1; //!< Д[DME-А002] Достоверность частоты настройки радиомаяка DME1
   uint16_t dme2_distance          : 1; //!< Д[DME-А003] Достоверность дальности до радиомаяка DME2
   uint16_t dme2_frequency         : 1; //!< Д[DME-А004] Достоверность частоты настройки радиомаяка DME2
} svs_absu_rts_valid_word_2_b_t;

//! Слово 3 достоверностей СВС/АБСУ/РТС
typedef struct svs_absu_rts_valid_word_3_b_t {
   uint16_t ark_bearing            : 1; //!< Д[АРК-А001] Достоверность курсового угла радиостанции АРК
   uint16_t ark_frequency          : 1; //!< Д[АРК-А002] Достоверность частоты настройки АРК
   uint16_t rvm_altitude_k         : 1; //!< Д[РВМ-А001] Достоверность радиовысоты малых высот для командира и навигатора
   uint16_t rvm_altitude_p         : 1; //!< Д[РВМ-А001] Достоверность радиовысоты малых высот для помощника и оператора
   uint16_t rvb_altitude           : 1; //!< Д[РВБ-А001] Достоверность радиовысоты больших высот
   uint16_t rsbn_delta_y_1         : 1; //!< Д[РСБН-А002] Достоверность отклонения от глиссады снижения (канал 1)
   uint16_t rsbn_delta_x_1         : 1; //!< Д[РСБН-А003] Достоверность отклонения от курса посадки (канал 1)
   uint16_t rsbn_delta_y_2         : 1; //!< Д[РСБН-А002] Достоверность отклонения от глиссады снижения (канал 2)
   uint16_t rsbn_delta_x_2         : 1; //!< Д[РСБН-А003] Достоверность отклонения от курса посадки (канал 2)
   uint16_t rsbn_distance          : 1; //!< Д[РСБН-А004] Достоверность дальности самолета от РСБН
   uint16_t rsbn_azimuth           : 1; //!< Д[РСБН-А005] Достоверность азимута на маяк РСБН истинного
   uint16_t rsbn_channel_number_np : 1; //!< Д[РСБН-А006] Достоверность номера частотно-кодового канала РСБН НП
   uint16_t rsbn_channel_number_ms : 1; //!< Д[РСБН-А006] Достоверность номера частотно-кодового канала РСБН МС
   uint16_t rsbn_delta_rpk         : 1; //!< Д[РСБН-А007] Достоверность отклонения от пеленга до взаимодействующего ЛА
   uint16_t rsbn_distance_ms       : 1; //!< Д[РСБН-А008] Достоверность дальности до взаимодействующего ЛА
   uint16_t                        : 1; //!< Резерв
} svs_absu_rts_valid_word_3_b_t;

//! Слово 1 достоверностей БЦВМ
typedef struct bcvm_valid_word_1_b_t {
   uint16_t magn_course       : 1; //!< Д[БЦВМ-А003] Достоверность курса магнитного
   uint16_t true_course       : 1; //!< Д[БЦВМ-А004] Достоверность курса истинного
   uint16_t magn_pu_selected  : 1; //!< Д[БЦВМ-А005] Достоверность магнитного заданного путевого угла или заданного курса
   uint16_t true_pu           : 1; //!< Д[БЦВМ-А007] Достоверность путевого угла истинного
   uint16_t delta_z           : 1; //!< Д[БЦВМ-А008] Достоверность ЛБУ
   uint16_t magn_pu           : 1; //!< Д[БЦВМ-А009] Достоверность путевого угла магнитного
   uint16_t waypoint_distance : 1; //!< Д[БЦВМ-А010] Достоверность расстояния до очередного ППМ
   uint16_t waypoint_time     : 1; //!< Д[БЦВМ-А011] Достоверность времени пролета очередного ППМ
   uint16_t azimuth_selected  : 1; //!< Д[БЦВМ-А012] Достоверность азимута заданного VOR магнитного или РСБН истинного
   uint16_t echelon           : 1; //!< Д[БЦВМ-А013] Достоверность высоты эшелона
   uint16_t altitude_delta    : 1; //!< Д[БЦВМ-А014] Достоверность отклонения от заданной высоты полета
   uint16_t runway_course     : 1; //!< Д[БЦВМ-А015] Достоверность курса ВПП
   uint16_t v1_continued      : 1; //!< Д[БЦВМ-А016] Достоверность скорости принятия решения на разбеге V1 (продолженной)
   uint16_t v1                : 1; //!< Д[БЦВМ-А017] Достоверность скорости принятия решения на разбеге V1 (прерванной)
   uint16_t vr                : 1; //!< Д[БЦВМ-А018] Достоверность скорости начала подъема передней стойки шасси VR
   uint16_t v2                : 1; //!< Д[БЦВМ-А019] Достоверность безопасной скорости на взлете V2
} bcvm_valid_word_1_b_t;

//! Слово 2 достоверностей БЦВМ
typedef struct bcvm_valid_word_2_b_t {
   uint16_t altitude_min      : 1; //!< Д[БЦВМ-А021] Достоверность минимально безопасной высоты
   uint16_t wind_angle        : 1; //!< Д[БЦВМ-А022] Достоверность направления ветра метеорологическое
   uint16_t wind_speed        : 1; //!< Д[БЦВМ-А023] Достоверность скорости ветра
   uint16_t w                 : 1; //!< Д[БЦВМ-А024] Достоверность скорости путевой
   uint16_t fuel_distance     : 1; //!< Д[БЦВМ-А025] Достоверность расстояния, оставшегося по запасу топлива
   uint16_t fuel_time_e       : 1; //!< Д[БЦВМ-А026] Достоверность времени, оставшегося по запасу топлива
   uint16_t azimuth_delta     : 1; //!< Д[БЦВМ-А027] Достоверность отклонения от линии заданного азимута VOR/РСБН
   uint16_t drift_angle       : 1; //!< Д[БЦВМ-А028] Достоверность угла сноса
   uint16_t waypoint_name     : 1; //!< Д[БЦВМ-А029] Достоверность идентификатора очередного ППМ
   uint16_t latitude          : 1; //!< Д[БЦВМ-А030] Достоверность географической широты местоположения объекта
   uint16_t longitude         : 1; //!< Д[БЦВМ-А031] Достоверность географической долготы местоположения объекта
   uint16_t waypoint_time_est : 1; //!< Д[БЦВМ-А033] Достоверность времени полета, оставшегося до очередного ППМ
   uint16_t route_number      : 1; //!< Д[БЦВМ-А034] Достоверность номера маршрута
   uint16_t current_time      : 1; //!< Д[БЦВМ-А036] Достоверность времени текущего
   uint16_t declination       : 1; //!< Д[БЦВМ-А037] Достоверность магнитного склонения
   uint16_t dtmsa             : 1; //!< Д[БЦВМ-А039] Достоверность отклонения от стандарта атмосферы по температуре
} bcvm_valid_word_2_b_t;

//! Слово 3 достоверностей БЦВМ
typedef struct bcvm_valid_word_3_b_t {
   uint16_t true_pu_selected      : 1; //!< Д[БЦВМ-А040] Достоверность истинного заданного путевого угла или заданного курса
   uint16_t landing_speed_40      : 1; //!< Д[БЦВМ-А041] Достоверность скорости снижения по глиссаде с закрылками 40°
   uint16_t landing_speed_25      : 1; //!< Д[БЦВМ-А042] Достоверность скорости снижения по глиссаде с закрылками 25°
   uint16_t runway_orto_s         : 1; //!< Д[БЦВМ-А043] Достоверность ортодромической дальности до торца ВПП взлета (посадки)
   uint16_t runway_orto_z         : 1; //!< Д[БЦВМ-А044] Достоверность бокового отклонения от прямой выхода на торец ВПП взлета (посадки)
   uint16_t speed_correction      : 1; //!< Д[БЦВМ-А046] Достоверность изменения скорости при выходе в заданную точку в заданное время
   uint16_t redundant_time        : 1; //!< Д[БЦВМ-А047] Достоверность изменения времени при выходе в заданную точку в заданное время
   uint16_t takeoff_run           : 1; //!< Д[БЦВМ-А048] Достоверность потребной длины разбега на взлете
   uint16_t landing_run_tp        : 1; //!< Д[БЦВМ-А049] Достоверность потребной длины пробега при посадке с тормозным парашютом
   uint16_t landing_run           : 1; //!< Д[БЦВМ-А050] Достоверность потребной длины пробега при посадке без тормозного парашюта
   uint16_t landing_runway_length : 1; //!< Д[БЦВМ-А051] Достоверность длины ВПП посадки
   uint16_t takeoff_runway_length : 1; //!< Д[БЦВМ-А052] Достоверность длины ВПП взлета
   uint16_t                       : 4; //!< Резерв
} bcvm_valid_word_3_b_t;

//! Слово 1 достоверностей ДВ (по одному двигателю)
typedef struct dv_valid_word_1_b_t {
   uint16_t start_time            : 1; //!< Д[ДВ-А001] Достоверность времени запуска двигателя
   uint16_t afterburn_time_land   : 1; //!< Д[ДВ-А002] Достоверность оставшегося времени работы форсажа на взлете
   uint16_t afterburn_time_in_air : 1; //!< Д[ДВ-А003] Достоверность оставшегося времени работы форсажа в полете
   uint16_t rud_ud_k              : 1; //!< Д[ДВ-А004] Достоверность положения РУД от УД для командира и навигатора
   uint16_t rud_ud_p              : 1; //!< Д[ДВ-А004] Достоверность положения РУД от УД для помощника и оператора
   uint16_t rud_sku_k             : 1; //!< Д[ДВ-А005] Достоверность положения РУД от СКУ для командира и навигатора
   uint16_t rud_sku_p             : 1; //!< Д[ДВ-А005] Достоверность положения РУД от СКУ для помощника и оператора
   uint16_t n2_k                  : 1; //!< Д[ДВ-А006] Достоверность значения оборотов ротора ВД для командира и навигатора
   uint16_t n2_p                  : 1; //!< Д[ДВ-А006] Достоверность значения оборотов ротора ВД для помощника и оператора
   uint16_t n2_max_danger         : 1; //!< Д[ДВ-А007] Достоверность опасного значения оборотов ротора НД
   uint16_t n1_ud_k               : 1; //!< Д[ДВ-А008] Достоверность значения оборотов ротора НД (от УД) для командира и навигатора
   uint16_t n1_ud_p               : 1; //!< Д[ДВ-А008] Достоверность значения оборотов ротора НД (от УД) для командира и навигатора
   uint16_t n1_sku_k              : 1; //!< Д[ДВ-А009] Достоверность значения оборотов ротора НД (от СКУ) для помощника и оператора
   uint16_t n1_sku_p              : 1; //!< Д[ДВ-А009] Достоверность значения оборотов ротора НД (от СКУ) для помощника и оператора
   uint16_t n1_max_danger         : 1; //!< Д[ДВ-А010] Достоверность опасного значения оборотов ротора НД
   uint16_t tg_ud                 : 1; //!< Д[ДВ-А012] Достоверность температуры газа в турбине (от УД)
} dv_valid_word_1_b_t;

//! Слово 2 достоверностей ДВ (по одному двигателю)
typedef struct dv_valid_word_2_b_t {
   uint16_t tg_sku              : 1; //!< Д[ДВ-А013] Достоверность температуры газа в турбине (от СКУ)
   uint16_t tg_max_danger_ud    : 1; //!< Д[ДВ-А014] Достоверность опасной температуры газа в турбине (от УД)
   uint16_t tg_max              : 1; //!< Д[ДВ-А015] Достоверность повышенной температуры газа в турбине
   uint16_t n_sd_k              : 1; //!< Д[ДВ-А017] Достоверность значения оборотов ротора СД для командира и навигатора
   uint16_t n_sd_p              : 1; //!< Д[ДВ-А017] Достоверность значения оборотов ротора СД для помощника и оператора
   uint16_t n_sd_max            : 1; //!< Д[ДВ-А018] Достоверность предельного значения оборотов ротора СД
   uint16_t inlet_wedge_angle   : 1; //!< Д[ДВ-А019] Достоверность положения панелей клина ВЗ
   uint16_t inlet_restart_angle : 1; //!< Д[ДВ-А020] Достоверность положения створки перепуска ВЗ
   uint16_t vibration_vpo       : 1; //!< Д[ДВ-А021] Достоверность вибрации передней опоры
   uint16_t vibration_vot       : 1; //!< Д[ДВ-А022] Достоверность вибрации опоры турбины
   uint16_t vibration_vfk       : 1; //!< Д[ДВ-А023] Достоверность вибрации форсажной камеры
   uint16_t vibration_vpo_max   : 1; //!< Д[ДВ-А024] Достоверность повышенной вибрации передней опоры
   uint16_t vibration_vot_max   : 1; //!< Д[ДВ-А025] Достоверность повышенной вибрации опоры турбины
   uint16_t vibration_vfk_max   : 1; //!< Д[ДВ-А026] Достоверность повышенной вибрации форсажной камеры
   uint16_t oil_pressure        : 1; //!< Д[ДВ-А027] Достоверность давления масла на входе в двигатель
   uint16_t oil_pressure_min    : 1; //!< Д[ДВ-А028] Достоверность пониженного давления масла на входе в двигатель
} dv_valid_word_2_b_t;

//! Слово 3 достоверностей ДВ (по одному двигателю)
typedef struct dv_valid_word_3_b_t {
   uint16_t oil_temperature_in      : 1; //!< Д[ДВ-А030] Достоверность температуры масла на входе в двигатель
   uint16_t oil_temperature_in_max  : 1; //!< Д[ДВ-А031] Достоверность повышенной температуры масла на входе в двигатель
   uint16_t oil_temperature_out     : 1; //!< Д[ДВ-А032] Достоверность температуры масла на выходе из опоры турбины
   uint16_t oil_temperature_out_max : 1; //!< Д[ДВ-А033] Достоверность повышенной температуры масла на выходе из опоры турбины
   uint16_t nozzle_angle            : 1; //!< Д[ДВ-А034] Достоверность положения реактивного сопла
   uint16_t air_pressure_turb       : 1; //!< Д[ДВ-А035] Достоверность давления в объединенной полости опор турбины
   uint16_t n1_max                  : 1; //!< Д[ДВ-А036] Достоверность предельного значения оборотов ротора НД
   uint16_t bearing_temperature_n1  : 1; //!< Д[ДВ-А037] Достоверность температуры подшипников ротора НД
   uint16_t bearing_temperature_sd  : 1; //!< Д[ДВ-А038] Достоверность температуры подшипников ротора CД
   uint16_t bearing_temperature_n2  : 1; //!< Д[ДВ-А039] Достоверность температуры подшипников ротора ВД
   uint16_t oil_level               : 1; //!< Д[ДВ-А040] Достоверность количества масла в маслобаке
   uint16_t oil_level_min           : 1; //!< Д[ДВ-А041] Достоверность пониженного количества масла в маслобаке
   uint16_t oil_level_max           : 1; //!< Д[ДВ-А042] Достоверность предельного количества масла в маслобаке
   uint16_t fuel_pressure           : 1; //!< Д[ДВ-А043] Достоверность давления топлива перед форсунками основной КС
   uint16_t fuel_temperature_tmt    : 1; //!< Д[ДВ-А044] Достоверность температуры топлива за ТМТ
   uint16_t tg_max_danger_sku       : 1; //!< Д[ДВ-А045] Достоверность опасной температуры газа в турбине (от СКУ)
} dv_valid_word_3_b_t;

//! Слово 4 достоверностей ДВ
typedef struct dv_valid_word_4_b_t {
   uint16_t dv1_inlet_wedge_angle_set   : 1; //!< Д[ДВ1-А046] Достоверность программного положения клина
   uint16_t dv1_inlet_restart_angle_set : 1; //!< Д[ДВ1-А047] Достоверность программного положения створки
   uint16_t dv1_air_temperature         : 1; //!< Д[ДВ1-А048/ДВ1-А049] Достоверность температуры воздуха на входе в ДВ/ВЗ
   uint16_t dv1_sku_failure             : 1; //!< [ДВ1] Нет данных от ЭЦР-32СКУ
   uint16_t dv2_inlet_wedge_angle_set   : 1; //!< Д[ДВ2-А046] Достоверность программного положения клина
   uint16_t dv2_inlet_restart_angle_set : 1; //!< Д[ДВ2-А047] Достоверность программного положения створки
   uint16_t dv2_air_temperature         : 1; //!< Д[ДВ2-А048/ДВ2-А049] Достоверность температуры воздуха на входе в ДВ/ВЗ
   uint16_t dv2_sku_failure             : 1; //!< [ДВ2] Нет данных от ЭЦР-32СКУ
   uint16_t dv3_inlet_wedge_angle_set   : 1; //!< Д[ДВ3-А046] Достоверность программного положения клина
   uint16_t dv3_inlet_restart_angle_set : 1; //!< Д[ДВ3-А047] Достоверность программного положения створки
   uint16_t dv3_air_temperature         : 1; //!< Д[ДВ3-А048/ДВ3-А049] Достоверность температуры воздуха на входе в ДВ/ВЗ
   uint16_t dv3_sku_failure             : 1; //!< [ДВ3] Нет данных от ЭЦР-32СКУ
   uint16_t dv4_inlet_wedge_angle_set   : 1; //!< Д[ДВ4-А046] Достоверность программного положения клина
   uint16_t dv4_inlet_restart_angle_set : 1; //!< Д[ДВ4-А047] Достоверность программного положения створки
   uint16_t dv4_air_temperature         : 1; //!< Д[ДВ4-А048/ДВ4-А049] Достоверность температуры воздуха на входе в ДВ/ВЗ
   uint16_t dv4_sku_failure             : 1; //!< [ДВ4] Нет данных от ЭЦР-32СКУ
} dv_valid_word_4_b_t;

//! Слово 1 достоверностей ИНС/АНС
typedef struct ins_ans_valid_word_1_b_t {
   uint16_t ins_roll_k      : 1; //!< Д[ИНС-А001] Достоверность угла крена для командира и навигатора
   uint16_t ins_roll_p      : 1; //!< Д[ИНС-А001] Достоверность угла крена для помощника и оператора
   uint16_t ins_pitch_k     : 1; //!< Д[ИНС-А002] Достоверность угла тангажа для командира и навигатора
   uint16_t ins_pitch_p     : 1; //!< Д[ИНС-А002] Достоверность угла тангажа для помощника и оператора
   uint16_t ins_nz          : 1; //!< Д[ИНС-А003] Достоверность ускорения вдоль поперечной оси объекта (боковой перегрузки)
   uint16_t ins_ny_k        : 1; //!< Д[ИНС-А004] Достоверность нормального ускорения (нормальной перегрузки) для командира и навигатора
   uint16_t ins_ny_p        : 1; //!< Д[ИНС-А004] Достоверность нормального ускорения (нормальной перегрузки) для помощника и оператора
   uint16_t ins_nx          : 1; //!< Д[ИНС-А009] Достоверность горизонтального ускорения вдоль траектории движения
   uint16_t ins_latitude_k  : 1; //!< Д[ИНС-А010] Достоверность географической широты местоположения объекта для командира и навигатора
   uint16_t ins_latitude_p  : 1; //!< Д[ИНС-А010] Достоверность географической широты местоположения объекта для помощника и оператора
   uint16_t ins_longitude_k : 1; //!< Д[ИНС-А011] Достоверность географической долготы местоположения объекта для командира и навигатора
   uint16_t ins_longitude_p : 1; //!< Д[ИНС-А011] Достоверность географической долготы местоположения объекта для помощника и оператора
   uint16_t ins_true_pu_k   : 1; //!< Д[ИНС-А012] Достоверность путевого угла истинного для командира и навигатора
   uint16_t ins_true_pu_p   : 1; //!< Д[ИНС-А012] Достоверность путевого угла истинного для помощника и оператора
   uint16_t ins_magn_pu_k   : 1; //!< Д[ИНС-А013] Достоверность путевого угла магнитного для командира и навигатора
   uint16_t ins_magn_pu_p   : 1; //!< Д[ИНС-А013] Достоверность путевого угла магнитного для помощника и оператора
} ins_ans_valid_word_1_b_t;

//! Слово 2 достоверностей ИНС/АНС
typedef struct ins_ans_valid_word_2_b_t {
   uint16_t ins_magn_course_k : 1; //!< Д[ИНС-А014] Достоверность курса магнитного для командира и навигатора
   uint16_t ins_magn_course_p : 1; //!< Д[ИНС-А014] Достоверность курса магнитного для помощника и оператора
   uint16_t ins_true_course_k : 1; //!< Д[ИНС-А015] Достоверность курса истинного для командира и навигатора
   uint16_t ins_true_course_p : 1; //!< Д[ИНС-А015] Достоверность курса истинного для помощника и оператора
   uint16_t ins_drift_angle   : 1; //!< Д[ИНС-А016] Достоверность угла сноса
   uint16_t ans_latitude      : 1; //!< Д[АНС-А001] Достоверность географической широты местоположения объекта
   uint16_t ans_longitude     : 1; //!< Д[АНС-А002] Достоверность географической долготы местоположения объекта
   uint16_t ans_true_course   : 1; //!< Д[АНС-А003] Достоверность курса истинного
   uint16_t ans_roll          : 1; //!< Д[АНС-А004] Достоверность угла крена
   uint16_t ans_pitch         : 1; //!< Д[АНС-А005] Достоверность угла тангажа
   uint16_t ans_w             : 1; //!< Д[АНС-А006] Достоверность путевой скорости
   uint16_t                   : 5; //!< Резерв
} ins_ans_valid_word_2_b_t;

//! Слово достоверностей ПКР
typedef struct pkr_valid_word_b_t {
   uint16_t speed_max      : 1; //!< Д[ПКР-А001] Достоверность максимально допустимой приборной скорости
   uint16_t speed_min      : 1; //!< Д[ПКР-А002] Достоверность минимально допустимой приборной скорости
   uint16_t roll_max       : 1; //!< Д[ПКР-А003] Достоверность допустимого угла крена
   uint16_t ny_max         : 1; //!< Д[ПКР-А004] Достоверность максимально допустимой нормальной перегрузки
   uint16_t ny_min         : 1; //!< Д[ПКР-А005] Достоверность минимально допустимой нормальной перегрузки
   uint16_t alpha_max      : 1; //!< Д[ПКР-А006] Достоверность максимально допустимого угла атаки
   uint16_t alpha_min      : 1; //!< Д[ПКР-А007] Достоверность минимально допустимого угла атаки
   uint16_t path_angle_pot : 1; //!< Д[ПКР-А008] Достоверность потенциального угла наклона траектории
   uint16_t path_angle     : 1; //!< Д[ПКР-А009] Достоверность угла наклона траектории
   uint16_t mach_max       : 1; //!< Д[ПКР-А010] Достоверность максимально допустимого числа Маха
   uint16_t                : 6; //!< Резерв
} pkr_valid_word_b_t;

//! Слово достоверностей ПУИ
typedef struct pui_valid_word_b_t {
   uint16_t vpr                 : 1;  //!< Д[ПУИ-А001] Достоверность высоты принятия решения/высоты опасной
   uint16_t mvs                 : 1;  //!< Д[ПУИ-А002] Достоверность минимальной высоты снижения
   uint16_t vpr_edited          : 1;  //!< Д[ПУИ-А003] Достоверность высоты принятия решения/высоты опасной выставляемой
   uint16_t mvs_edited          : 1;  //!< Д[ПУИ-А004] Достоверность минимальной высоты снижения выставляемой
   uint16_t pressure_qnh_edited : 1;  //!< Д[ПУИ-А005] Достоверность барокоррекции QNH выставляемой
   uint16_t pressure_qfe_edited : 1;  //!< Д[ПУИ-А006] Достоверность барокоррекции QFE выставляемой
   uint16_t                     : 10; //!< Резерв
} pui_valid_word_b_t;

//! Слово достоверностей САУ/СМК
typedef struct sau_smk_valid_word_b_t {
   uint16_t sau_director_x          : 1; //!< Д[САУ-А001] Достоверность команды директорной по крену
   uint16_t sau_director_y          : 1; //!< Д[САУ-А002] Достоверность команды директорной по тангажу
   uint16_t sau_course_selected     : 1; //!< Д[САУ-А003] Достоверность заданного курса/путевого угла
   uint16_t sau_altitude_selected   : 1; //!< Д[САУ-А004] Достоверность заданной барометрической высоты
   uint16_t sau_speed_selected      : 1; //!< Д[САУ-А005] Достоверность заданной приборной скорости
   uint16_t sau_vy_selected         : 1; //!< Д[САУ-А006] Достоверность заданной вертикальной скорости
   uint16_t sau_mach_selected       : 1; //!< Д[САУ-А007] Достоверность заданного числа Маха
   uint16_t sau_path_angle_selected : 1; //!< Д[САУ-А008] Достоверность заданного угла наклона траектории
   uint16_t smk_wing                : 1; //!< Д[СМК-А013] Достоверность положения трансмиссии консолей крыла
   uint16_t smk_flap_right          : 1; //!< Д[СМК-А014] Достоверность положения правого закрылка
   uint16_t smk_flap_left           : 1; //!< Д[СМК-А015] Достоверность положения левого закрылка
   uint16_t smk_ruk                 : 1; //!< Д[СМК-А016] Достоверность положения рукоятки управления крылом
   uint16_t smk_slat_right          : 1; //!< Д[СМК-А018] Достоверность положения правого предкрылка
   uint16_t smk_slat_left           : 1; //!< Д[СМК-А019] Достоверность положения левого предкрылка
   uint16_t smk_wing_left           : 1; //!< Д[СМК-А120] Достоверность положения левой консоли крыла
   uint16_t smk_wing_right          : 1; //!< Д[СМК-А121] Достоверность положения правой консоли крыла
} sau_smk_valid_word_b_t;

//! Слово сигналов и достоверностей СНС
typedef struct sns_flag_valid_word_b_t {
   uint16_t landing           : 1; //!< [СНС-Д001] Режим работы СНС - посадка
   uint16_t delta_x_valid     : 1; //!< Д[СНС-А001] Достоверность отклонения от курса посадки
   uint16_t delta_y_valid     : 1; //!< Д[СНС-А002] Достоверность отклонения от глиссады снижения
   uint16_t latitude_valid    : 1; //!< Д[СНС-А003] Достоверность географической широты местоположения объекта
   uint16_t longitude_valid   : 1; //!< Д[СНС-А004] Достоверность географической долготы местоположения объекта
   uint16_t distance_valid    : 1; //!< Д[СНС-А005] Достоверность горизонтальной дальности до порога ВПП посадки
   uint16_t channel_num_valid : 1; //!< Д[СНС-А006] Достоверность кода частотного канала
   uint16_t                   : 9; //!< Резерв
} sns_flag_valid_word_b_t;

//! Слово достоверностей СУР
typedef struct sur_valid_word_b_t {
   uint16_t course_balance  : 1; //!< Д[СУР-А001] Достоверность сигнала балансировки по курсу
   uint16_t pitch_balance   : 1; //!< Д[СУР-А002] Достоверность суммарного сигнала балансировки по тангажу
   uint16_t fin             : 1; //!< Д[СУР-А003] Достоверность положения киля
   uint16_t stab            : 1; //!< Д[СУР-А004] Достоверность положения стабилизатора
   uint16_t interceptor_r12 : 1; //!< Д[СУР-А006] Достоверность положения секции I и II правых интерцепторов
   uint16_t interceptor_r34 : 1; //!< Д[СУР-А007] Достоверность положения секции III и IV правых интерцепторов
   uint16_t interceptor_r56 : 1; //!< Д[СУР-А008] Достоверность положения секции V и VI правых интерцепторов
   uint16_t interceptor_l12 : 1; //!< Д[СУР-А009] Достоверность положения секции I и II  левого интерцептора
   uint16_t interceptor_l34 : 1; //!< Д[СУР-А010] Достоверность положения секции III и IV левого интерцептора
   uint16_t interceptor_l56 : 1; //!< Д[СУР-А011] Достоверность положения секции V и VI левого интерцептора
   uint16_t flaperon_left   : 1; //!< Д[СУР-А020] Достоверность положения левого флаперона
   uint16_t flaperon_right  : 1; //!< Д[СУР-А021] Достоверность положения правого флаперона
   uint16_t roll_balance    : 1; //!< Д[СУР-А022] Достоверность сигнала балансировки по крену
   uint16_t                 : 3; //!< Резерв
} sur_valid_word_b_t;

//! Слово 1 достоверностей СЭС
typedef struct sas_valid_word_1_b_t {
   uint16_t u115_voltage_gen1_1 : 1; //!< Д[СЭС-А201] Сеть 115В: Достоверность напряжения сети генератора 1, фаза A
   uint16_t u115_voltage_gen1_2 : 1; //!< Д[СЭС-А202] Сеть 115В: Достоверность напряжения сети генератора 1, фаза B
   uint16_t u115_voltage_gen1_3 : 1; //!< Д[СЭС-А203] Сеть 115В: Достоверность напряжения сети генератора 1, фаза C
   uint16_t u115_voltage_gen2_1 : 1; //!< Д[СЭС-А204] Сеть 115В: Достоверность напряжения сети генератора 2, фаза A
   uint16_t u115_voltage_gen2_2 : 1; //!< Д[СЭС-А205] Сеть 115В: Достоверность напряжения сети генератора 2, фаза B
   uint16_t u115_voltage_gen2_3 : 1; //!< Д[СЭС-А206] Сеть 115В: Достоверность напряжения сети генератора 2, фаза C
   uint16_t u115_voltage_gen3_1 : 1; //!< Д[СЭС-А207] Сеть 115В: Достоверность напряжения сети генератора 3, фаза A
   uint16_t u115_voltage_gen3_2 : 1; //!< Д[СЭС-А208] Сеть 115В: Достоверность напряжения сети генератора 3, фаза B
   uint16_t u115_voltage_gen3_3 : 1; //!< Д[СЭС-А209] Сеть 115В: Достоверность напряжения сети генератора 3, фаза C
   uint16_t u115_voltage_gen4_1 : 1; //!< Д[СЭС-А210] Сеть 115В: Достоверность напряжения сети генератора 4, фаза A
   uint16_t u115_voltage_gen4_2 : 1; //!< Д[СЭС-А211] Сеть 115В: Достоверность напряжения сети генератора 4, фаза B
   uint16_t u115_voltage_gen4_3 : 1; //!< Д[СЭС-А212] Сеть 115В: Достоверность напряжения сети генератора 4, фаза C
   uint16_t u115_current_rap_1  : 1; //!< Д[СЭС-А213] Сеть 115В: Достоверность тока РАП, фаза A
   uint16_t u115_current_rap_2  : 1; //!< Д[СЭС-А214] Сеть 115В: Достоверность тока РАП, фаза B
   uint16_t u115_current_rap_3  : 1; //!< Д[СЭС-А215] Сеть 115В: Достоверность тока РАП, фаза C
   uint16_t u115_current_vsu_1  : 1; //!< Д[СЭС-А216] Сеть 115В: Достоверность тока генератора ВСУ, фаза A
} sas_valid_word_1_b_t;

//! Слово 2 достоверностей СЭС
typedef struct sas_valid_word_2_b_t {
   uint16_t u115_current_vsu_2   : 1; //!< Д[СЭС-А217] Сеть 115В: Достоверность тока генератора ВСУ, фаза B
   uint16_t u115_current_vsu_3   : 1; //!< Д[СЭС-А218] Сеть 115В: Достоверность тока генератора ВСУ, фаза C
   uint16_t u115_frequency_gen1  : 1; //!< Д[СЭС-А219] Сеть 115В: Достоверность частоты сети генератора 1
   uint16_t u115_frequency_gen2  : 1; //!< Д[СЭС-А220] Сеть 115В: Достоверность частоты сети генератора 2
   uint16_t u115_frequency_gen3  : 1; //!< Д[СЭС-А221] Сеть 115В: Достоверность частоты сети генератора 3
   uint16_t u115_frequency_gen4  : 1; //!< Д[СЭС-А222] Сеть 115В: Достоверность частоты сети генератора 4
   uint16_t u115_voltage_emrg1_1 : 1; //!< Д[СЭС-А223] Сеть 115В: Достоверность напряжения аварийной сети 1, фаза A
   uint16_t u115_voltage_emrg1_2 : 1; //!< Д[СЭС-А224] Сеть 115В: Достоверность напряжения аварийной сети 1, фаза В
   uint16_t u115_voltage_emrg1_3 : 1; //!< Д[СЭС-А225] Сеть 115В: Достоверность напряжения аварийной сети 1, фаза С
   uint16_t u115_voltage_emrg2_1 : 1; //!< Д[СЭС-А226] Сеть 115В: Достоверность напряжения аварийной сети 2, фаза А
   uint16_t u115_voltage_emrg2_2 : 1; //!< Д[СЭС-А227] Сеть 115В: Достоверность напряжения аварийной сети 2, фаза В
   uint16_t u115_voltage_emrg2_3 : 1; //!< Д[СЭС-А228] Сеть 115В: Достоверность напряжения аварийной сети 2, фаза С
   uint16_t u115_frequency_emrg1 : 1; //!< Д[СЭС-А229] Сеть 115В: Достоверность частоты аварийной сети 1
   uint16_t u115_frequency_emrg2 : 1; //!< Д[СЭС-А230] Сеть 115В: Достоверность частоты аварийной сети 2
   uint16_t                      : 2; //!< Резерв
} sas_valid_word_2_b_t;

//! Слово 3 достоверностей СЭС
typedef struct sas_valid_word_3_b_t {
   uint16_t u115_voltage_conv1_1    : 1; //!< Д[СЭС-А231] Сеть 115В: Достоверность напряжения на шине преобразователя 1, фаза А
   uint16_t u115_voltage_conv1_2    : 1; //!< Д[СЭС-А232] Сеть 115В: Достоверность напряжения на шине преобразователя 1, фаза В
   uint16_t u115_voltage_conv1_3    : 1; //!< Д[СЭС-А233] Сеть 115В: Достоверность напряжения на шине преобразователя 1, фаза С
   uint16_t u115_flag_234           : 1; //!< Д[СЭС-А234] Сеть 115В: Резерв
   uint16_t u115_flag_235           : 1; //!< Д[СЭС-А235] Сеть 115В: Резерв
   uint16_t u115_flag_236           : 1; //!< Д[СЭС-А236] Сеть 115В: Резерв
   uint16_t u115_voltage_conv3l_1   : 1; //!< Д[СЭС-А237] Сеть 115В: Достоверность напряжения на шине преобразователя 3 левой, фаза А
   uint16_t u115_voltage_conv3r_1   : 1; //!< Д[СЭС-А238] Сеть 115В: Достоверность напряжения на шине преобразователя 3 правой, фаза А
   uint16_t u115_frequency_conv1    : 1; //!< Д[СЭС-А239] Сеть 115В: Достоверность частоты на шине преобразователя 1
   uint16_t u115_flag_240           : 1; //!< Д[СЭС-А240] Сеть 115В: Резерв
   uint16_t u115_frequency_conv3    : 1; //!< Д[СЭС-А241] Сеть 115В: Достоверность частоты на шине преобразователя 3
   uint16_t u115_converter1_voltage : 1; //!< Д[СЭС-А242] Сеть 115В: Достоверность напряжения преобразователя 1
   uint16_t u115_flag_243           : 1; //!< Д[СЭС-А243] Сеть 115В: Резерв
   uint16_t u115_converter3_voltage : 1; //!< Д[СЭС-А244] Сеть 115В: Достоверность напряжения преобразователя 3
   uint16_t                         : 2; //!< Резерв
} sas_valid_word_3_b_t;

//! Слово 4 достоверностей СЭС
typedef struct sas_valid_word_4_b_t {
   uint16_t u27_current_battery_rap_1 : 1; //!< Д[СЭС-А301] Сеть 27В: Достоверность тока аккумулятора 1, РАП1
   uint16_t u27_current_battery_rap_2 : 1; //!< Д[СЭС-А302] Сеть 27В: Достоверность тока аккумулятора 2, РАП2
   uint16_t u27_voltage_battery_1     : 1; //!< Д[СЭС-А303] Сеть 27В: Достоверность напряжения аккумулятора 1
   uint16_t u27_voltage_battery_2     : 1; //!< Д[СЭС-А304] Сеть 27В: Достоверность напряжения аккумулятора 2
   uint16_t u27_current_vsu           : 1; //!< Д[СЭС-А305] Сеть 27В: Достоверность тока генератора ВСУ
   uint16_t u27_flag_306              : 1; //!< Д[СЭС-А306] Сеть 27В: Резерв
   uint16_t u27_flag_307              : 1; //!< Д[СЭС-А307] Сеть 27В: Резерв
   uint16_t u27_voltage_l_main1       : 1; //!< Д[СЭС-А308] Сеть 27В: Достоверность напряжения шины основной 1 левой сети
   uint16_t u27_voltage_l_main2       : 1; //!< Д[СЭС-А309] Сеть 27В: Достоверность напряжения шины основной 2 левой сети
   uint16_t u27_voltage_l_emrg1       : 1; //!< Д[СЭС-А310] Сеть 27В: Достоверность напряжения шины аварийной 1 левой сети
   uint16_t u27_voltage_r_main1       : 1; //!< Д[СЭС-А311] Сеть 27В: Достоверность напряжения шины основной 1 правой сети
   uint16_t u27_voltage_r_main2       : 1; //!< Д[СЭС-А312] Сеть 27В: Достоверность напряжения шины основной 2 правой сети
   uint16_t u27_voltage_r_emrg2       : 1; //!< Д[СЭС-А313] Сеть 27В: Достоверность напряжения шины аварийной 2 правой сети
   uint16_t                           : 3; //!< Резерв
} sas_valid_word_4_b_t;

//! Слово достоверностей ТОРМ
typedef struct torm_valid_word_b_t {
   uint16_t pressure_lf_1      : 1; //!< Д[ТОРМ-А401] Достоверность давления в тормозах передней пары левой тележки (основная подсистема)
   uint16_t pressure_lm_1      : 1; //!< Д[ТОРМ-А402] Достоверность давления в тормозах средней пары левой тележки (основная подсистема)
   uint16_t pressure_lr_1      : 1; //!< Д[ТОРМ-А403] Достоверность давления в тормозах задней пары левой тележки (основная подсистема)
   uint16_t pressure_rf_1      : 1; //!< Д[ТОРМ-А404] Достоверность давления в тормозах передней пары правой тележки (основная подсистема)
   uint16_t pressure_rm_1      : 1; //!< Д[ТОРМ-А405] Достоверность давления в тормозах средней пары правой тележки (основная подсистема)
   uint16_t pressure_rr_1      : 1; //!< Д[ТОРМ-А406] Достоверность давления в тормозах задней пары правой тележки (основная подсистема)
   uint16_t pressure_lf_2      : 1; //!< Д[ТОРМ-А601] Достоверность давления в тормозах передней пары левой тележки (резервная подсистема)
   uint16_t pressure_lm_2      : 1; //!< Д[ТОРМ-А602] Достоверность давления в тормозах средней пары левой тележки (резервная подсистема)
   uint16_t pressure_lr_2      : 1; //!< Д[ТОРМ-А603] Достоверность давления в тормозах задней пары левой тележки (резервная подсистема)
   uint16_t pressure_rf_2      : 1; //!< Д[ТОРМ-А604] Достоверность давления в тормозах передней пары правой тележки (резервная подсистема)
   uint16_t pressure_rm_2      : 1; //!< Д[ТОРМ-А605] Достоверность давления в тормозах средней пары правой тележки (резервная подсистема)
   uint16_t pressure_rr_2      : 1; //!< Д[ТОРМ-А606] Достоверность давления в тормозах задней пары правой тележки (резервная подсистема)
   uint16_t pressure_acc_fluid : 1; //!< Д[ТОРМ-А607] Достоверность давления жидкости в гидроаккумуляторе
   uint16_t pressure_acc_nitro : 1; //!< Д[ТОРМ-А608] Достоверность давления азота в гидроаккумуляторе
   uint16_t                    : 2; //!< Резерв
} torm_valid_word_b_t;

//! Слово 1 достоверностей ТОПЛ
typedef struct topl_valid_word_1_b_t {
   uint16_t fuel_selected      : 1; //!< Д[ТОПЛ-А001] Достоверность значения на задатчике заправки
   uint16_t centering_selected : 1; //!< Д[ТОПЛ-А002] Достоверность заданной центровки
   uint16_t centering          : 1; //!< Д[ТОПЛ-А003] Достоверность фактической центровки самолета
   uint16_t fuel_total         : 1; //!< Д[ТОПЛ-А004] Достоверность общего количества топлива по всем бакам
   uint16_t fuel_1l            : 1; //!< Д[ТОПЛ-А005] Достоверность количества топлива в баке Б1Л
   uint16_t fuel_1r            : 1; //!< Д[ТОПЛ-А006] Достоверность количества топлива в баке Б1П
   uint16_t fuel_2l            : 1; //!< Д[ТОПЛ-А007] Достоверность количества топлива в баке Б2Л
   uint16_t fuel_2r            : 1; //!< Д[ТОПЛ-А008] Достоверность количества топлива в баке Б2П
   uint16_t fuel_4             : 1; //!< Д[ТОПЛ-А009] Достоверность количества топлива в баке Б4
   uint16_t fuel_3l            : 1; //!< Д[ТОПЛ-А010] Достоверность количества топлива в баке Б3Л
   uint16_t fuel_3r            : 1; //!< Д[ТОПЛ-А011] Достоверность количества топлива в баке Б3П
   uint16_t fuel_5             : 1; //!< Д[ТОПЛ-А012] Достоверность количества топлива в баке Б5
   uint16_t fuel_6             : 1; //!< Д[ТОПЛ-А013] Достоверность количества топлива в баке Б6
   uint16_t fuel_rb1           : 1; //!< Д[ТОПЛ-А014] Достоверность количества топлива в баке РБ1
   uint16_t fuel_rb2           : 1; //!< Д[ТОПЛ-А015] Достоверность количества топлива в баке РБ2
   uint16_t fuel_rb3           : 1; //!< Д[ТОПЛ-А016] Достоверность количества топлива в баке РБ3
} topl_valid_word_1_b_t;

//! Слово 2 достоверностей ТОПЛ
typedef struct topl_valid_word_2_b_t {
   uint16_t fuel_rb4            : 1; //!< Д[ТОПЛ-А017] Достоверность количества топлива в баке РБ4
   uint16_t fuel_pressure       : 1; //!< Д[ТОПЛ-А018] Достоверность давления в приемнике топлива (заправки)
   uint16_t weight              : 1; //!< Д[ТОПЛ-А019] Достоверность суммарной массы самолета
   uint16_t fuel_total_dz_start : 1; //!< Д[ТОПЛ-А021] Достоверность общего количества топлива в момент начала заправки
   uint16_t fuel_3l_reserve     : 1; //!< Д[ТОПЛ-А022] Достоверность запаса топлива в резервном отсеке бака Б3Л
   uint16_t fuel_3r_reserve     : 1; //!< Д[ТОПЛ-А023] Достоверность запаса топлива в резервном отсеке бака Б3П
   uint16_t fuel_rb1_reserve    : 1; //!< Д[ТОПЛ-А024] Достоверность запаса топлива в резервном отсеке бака РБ1
   uint16_t fuel_rb2_reserve    : 1; //!< Д[ТОПЛ-А025] Достоверность запаса топлива в резервном отсеке бака РБ2
   uint16_t fuel_rb3_reserve    : 1; //!< Д[ТОПЛ-А026] Достоверность запаса топлива в резервном отсеке бака РБ3
   uint16_t fuel_rb4_reserve    : 1; //!< Д[ТОПЛ-А027] Достоверность запаса топлива в резервном отсеке бака РБ4
   uint16_t                     : 6; //!< Резерв
} topl_valid_word_2_b_t;

//! Слово достоверностей ФОВБ
typedef struct fovb_valid_word_b_t {
   uint16_t speed_min : 1;  //!< [ФОВБ-А001] Достоверность рекомендуемой приборной скорости минимальной
   uint16_t speed_max : 1;  //!< [ФОВБ-А002] Достоверность рекомендуемой приборной скорости максимальной
   uint16_t rate_min  : 1;  //!< [ФОВБ-А003] Достоверность рекомендуемой вертикальной скорости минимальной
   uint16_t rate_max  : 1;  //!< [ФОВБ-А004] Достоверность рекомендуемой вертикальной скорости максимальной
   uint16_t           : 12; //!< Резерв
} fovb_valid_word_b_t;

//! Слово состояния МКИО (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mkio_status_word_b_t {
   uint16_t mkio1_1_valid : 1; //!< Наличие данных о состоянии МКИО-1.1 (БИС ИМ1)
   uint16_t mkio1_2_valid : 1; //!< Наличие данных о состоянии МКИО-1.2 (БЦВМ ИМ2)
   uint16_t mkio2_valid   : 1; //!< Наличие данных о состоянии МКИО-2 (БЦВМ1 ИМ1)
   uint16_t mkio3_1_valid : 1; //!< Наличие данных о состоянии МКИО-3.1 (БИС ИМ6)
   uint16_t mkio3_2_valid : 1; //!< Наличие данных о состоянии МКИО-3.2 (БЦВМ ИМ2)
   uint16_t mkio4_1_valid : 1; //!< Наличие данных о состоянии МКИО-4.1 (КВИ)
   uint16_t mkio4_2_valid : 1; //!< Наличие данных о состоянии МКИО-4.2 (КВИ)
   uint16_t mkio5_valid   : 1; //!< Наличие данных о состоянии МКИО-5 (БИС ИМ2)
   uint16_t mkio6_valid   : 1; //!< Наличие данных о состоянии МКИО-6 (БИС ИМ5)
   uint16_t mkio7_valid   : 1; //!< Наличие данных о состоянии МКИО-7 (БИС ИМ3)
   uint16_t mkio8_valid   : 1; //!< Наличие данных о состоянии МКИО-8 (БИС ИМ4)
   uint16_t mkio9_valid   : 1; //!< Наличие данных о состоянии МКИО-9 (БИС ИМ3)
   uint16_t mkio10_valid  : 1; //!< Наличие данных о состоянии МКИО-10 (БИС ИМ4)
   uint16_t               : 3; //!< Резерв
} mfci_in_blocks_mkio_status_word_b_t;

//! Слово 1 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_1_b_t {
   uint16_t integral : 2; //!< Интегральное состояние //(min:0 max:3)
   uint16_t unit01   : 2; //!< Состояние модуля № 1 (МВ100-02-12 ММП1) //(min:0 max:3)
   uint16_t unit02   : 2; //!< Состояние модуля № 2 (МВ100-01) //(min:0 max:3)
   uint16_t unit03   : 2; //!< Состояние модуля № 3 (МВ101-01 ИМ1) //(min:0 max:3)
   uint16_t unit04   : 2; //!< Состояние модуля № 4 (МВ101-01 ИМ2) //(min:0 max:3)
   uint16_t unit05   : 2; //!< Состояние модуля № 5 (МВ101-01 ИМ3) //(min:0 max:3)
   uint16_t unit06   : 2; //!< Состояние модуля № 6 (МВ101-01 ИМ4) //(min:0 max:3)
   uint16_t unit07   : 2; //!< Состояние модуля № 7 (МВ101-01 ИМ5) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_1_b_t;

//! Слово 2 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_2_b_t {
   uint16_t unit08 : 2; //!< Состояние модуля № 8 (МВ101-01 ИМ6) //(min:0 max:3)
   uint16_t unit09 : 2; //!< Состояние модуля № 9 (МВ100-01) //(min:0 max:3)
   uint16_t unit10 : 2; //!< Состояние модуля № 10 (МВ100-02-12 ММП2) //(min:0 max:3)
   uint16_t unit11 : 2; //!< Состояние модуля № 11 (МС102) //(min:0 max:3)
   uint16_t unit12 : 2; //!< Состояние модуля № 12 (МС102) //(min:0 max:3)
   uint16_t unit13 : 2; //!< Состояние модуля № 13 (МН100) //(min:0 max:3)
   uint16_t unit14 : 2; //!< Состояние модуля № 14 (МН100) //(min:0 max:3)
   uint16_t pkr    : 2; //!< Состояние ПКР-70 //(min:0 max:3)
} mfci_in_blocks_bis_status_word_2_b_t;

//! Слово 3 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_3_b_t {
   uint16_t mmp1_bis_spacewire   : 2; //!< Состояние связи с другим БИС SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bcvm1_spacewire : 2; //!< Состояние связи с БЦВМ-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bcvm2_spacewire : 2; //!< Состояние связи с БЦВМ-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_kvi1_spacewire  : 2; //!< Состояние связи с КВИ-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_kvi2_spacewire  : 2; //!< Состояние связи с КВИ-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bgs1_spacewire  : 2; //!< Состояние связи с БГС-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bgs2_spacewire  : 2; //!< Состояние связи с БГС-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_sbi_spacewire   : 2; //!< Состояние связи с СБИ SpaceWire (на ММП1) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_3_b_t;

//! Слово 4 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_4_b_t {
   uint16_t mmp2_bis_spacewire   : 2; //!< Состояние связи с другим БИС SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bcvm1_spacewire : 2; //!< Состояние связи с БЦВМ-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bcvm2_spacewire : 2; //!< Состояние связи с БЦВМ-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_kvi1_spacewire  : 2; //!< Состояние связи с КВИ-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_kvi2_spacewire  : 2; //!< Состояние связи с КВИ-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bgs1_spacewire  : 2; //!< Состояние связи с БГС-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bgs2_spacewire  : 2; //!< Состояние связи с БГС-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_sbi_spacewire   : 2; //!< Состояние связи с СБИ SpaceWire (на ММП2) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_4_b_t;

//! Слово 5 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_5_b_t {
   uint16_t koi                    : 2; //!< Состояние НО (КОИ) //(min:0 max:3)
   uint16_t sv                     : 2; //!< Состояние НО (СВ) //(min:0 max:3)
   uint16_t bigs                   : 2; //!< Состояние БИГС (ДИСП1) //(min:0 max:3)
   uint16_t mfpu1_mkio1_1_bus1     : 1; //!< Исправность связи с ОУ МФПУ-1 МКИО-1.1A (ИМ1)
   uint16_t mfpu1_mkio1_1_bus2     : 1; //!< Исправность связи с ОУ МФПУ-1 МКИО-1.1B (ИМ1)
   uint16_t mfpu2_mkio1_1_bus1     : 1; //!< Исправность связи с ОУ МФПУ-2 МКИО-1.1A (ИМ1)
   uint16_t mfpu2_mkio1_1_bus2     : 1; //!< Исправность связи с ОУ МФПУ-2 МКИО-1.1B (ИМ1)
   uint16_t mfpu3_mkio1_1_bus1     : 1; //!< Исправность связи с ОУ МФПУ-3 МКИО-1.1A (ИМ1)
   uint16_t mfpu3_mkio1_1_bus2     : 1; //!< Исправность связи с ОУ МФПУ-3 МКИО-1.1B (ИМ1)
   uint16_t bcvm1_mkio1_1_bus1     : 1; //!< Исправность связи с ОУ БЦВМ-1 МКИО-1.1A (ИМ1)
   uint16_t bcvm1_mkio1_1_bus2     : 1; //!< Исправность связи с ОУ БЦВМ-1 МКИО-1.1B (ИМ1)
   uint16_t bcvm2_mkio1_1_bus1     : 1; //!< Исправность связи с ОУ БЦВМ-2 МКИО-1.1A (ИМ1)
   uint16_t bcvm2_mkio1_1_bus2     : 1; //!< Исправность связи с ОУ БЦВМ-2 МКИО-1.1B (ИМ1)
} mfci_in_blocks_bis_status_word_5_b_t;

//! Слово 6 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_6_b_t {
   uint16_t bvd1_mkio1_1_bus1   : 1; //!< Исправность связи с ОУ БВД-1 МКИО-1.1A (ИМ1)
   uint16_t bvd1_mkio1_1_bus2   : 1; //!< Исправность связи с ОУ БВД-1 МКИО-1.1B (ИМ1)
   uint16_t bvd2_mkio1_1_bus1   : 1; //!< Исправность связи с ОУ БВД-2 МКИО-1.1A (ИМ1)
   uint16_t bvd2_mkio1_1_bus2   : 1; //!< Исправность связи с ОУ БВД-2 МКИО-1.1B (ИМ1)
   uint16_t bgs1_mkio3_1_bus1   : 1; //!< Исправность связи с ОУ БГС-1 МКИО-3.1A (ИМ6)
   uint16_t bgs1_mkio3_1_bus2   : 1; //!< Исправность связи с ОУ БГС-1 МКИО-3.1B (ИМ6)
   uint16_t bgs2_mkio3_1_bus1   : 1; //!< Исправность связи с ОУ БГС-2 МКИО-3.1A (ИМ6)
   uint16_t bgs2_mkio3_1_bus2   : 1; //!< Исправность связи с ОУ БГС-2 МКИО-3.1B (ИМ6)
   uint16_t mfci01_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-1 МКИО-3.1A (ИМ6)
   uint16_t mfci01_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-1 МКИО-3.1B (ИМ6)
   uint16_t mfci02_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-2 МКИО-3.1A (ИМ6)
   uint16_t mfci02_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-2 МКИО-3.1B (ИМ6)
   uint16_t mfci03_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-3 МКИО-3.1A (ИМ6)
   uint16_t mfci03_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-3 МКИО-3.1B (ИМ6)
   uint16_t mfci04_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-4 МКИО-3.1A (ИМ6)
   uint16_t mfci04_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-4 МКИО-3.1B (ИМ6)
} mfci_in_blocks_bis_status_word_6_b_t;

//! Слово 7 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_7_b_t {
   uint16_t mfci05_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-5 МКИО-3.1A (ИМ6)
   uint16_t mfci05_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-5 МКИО-3.1B (ИМ6)
   uint16_t mfci06_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-6 МКИО-3.1A (ИМ6)
   uint16_t mfci06_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-6 МКИО-3.1B (ИМ6)
   uint16_t mfci07_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-7 МКИО-3.1A (ИМ6)
   uint16_t mfci07_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-7 МКИО-3.1B (ИМ6)
   uint16_t mfci08_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-8 МКИО-3.1A (ИМ6)
   uint16_t mfci08_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-8 МКИО-3.1B (ИМ6)
   uint16_t mfci09_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-9 МКИО-3.1A (ИМ6)
   uint16_t mfci09_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-9 МКИО-3.1B (ИМ6)
   uint16_t mfci10_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-10 МКИО-3.1A (ИМ6)
   uint16_t mfci10_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-10 МКИО-3.1B (ИМ6)
   uint16_t mfci11_mkio3_1_bus1 : 1; //!< Исправность связи с ОУ МФЦИ-11 МКИО-3.1A (ИМ6)
   uint16_t mfci11_mkio3_1_bus2 : 1; //!< Исправность связи с ОУ МФЦИ-11 МКИО-3.1B (ИМ6)
   uint16_t                     : 2; //!< Резерв
} mfci_in_blocks_bis_status_word_7_b_t;

//! Слово 8 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_8_b_t {
   uint16_t absu1_mkio5_bus1   : 1; //!< Исправность связи с ОУ АБСУ-К1 МКИО-5A (ИМ2)
   uint16_t absu1_mkio5_bus2   : 1; //!< Исправность связи с ОУ АБСУ-К1 МКИО-5B (ИМ2)
   uint16_t absu3_mkio5_bus1   : 1; //!< Исправность связи с ОУ АБСУ-К3 МКИО-5A (ИМ2)
   uint16_t absu3_mkio5_bus2   : 1; //!< Исправность связи с ОУ АБСУ-К3 МКИО-5B (ИМ2)
   uint16_t a312_np_mkio5_bus1 : 1; //!< Исправность связи с ОУ РСБН А-312-043Е МКИО-5A (ИМ2)
   uint16_t a312_np_mkio5_bus2 : 1; //!< Исправность связи с ОУ РСБН А-312-043Е МКИО-5B (ИМ2)
   uint16_t a312_ms_mkio5_bus1 : 1; //!< Исправность связи с ОУ РСБН А-312-054 МКИО-5A (ИМ2)
   uint16_t a312_ms_mkio5_bus2 : 1; //!< Исправность связи с ОУ РСБН А-312-054 МКИО-5B (ИМ2)
   uint16_t bins1_mkio5_bus1   : 1; //!< Исправность связи с ОУ БИНС-1 МКИО-5A (ИМ2)
   uint16_t bins1_mkio5_bus2   : 1; //!< Исправность связи с ОУ БИНС-1 МКИО-5B (ИМ2)
   uint16_t bins3_mkio5_bus1   : 1; //!< Исправность связи с ОУ БИНС-3 МКИО-5A (ИМ2)
   uint16_t bins3_mkio5_bus2   : 1; //!< Исправность связи с ОУ БИНС-3 МКИО-5B (ИМ2)
   uint16_t sns_mkio5_bus1     : 1; //!< Исправность связи с ОУ ПНАП-ПЛА МКИО-5A (ИМ2)
   uint16_t sns_mkio5_bus2     : 1; //!< Исправность связи с ОУ ПНАП-ПЛА МКИО-5B (ИМ2)
   uint16_t pui1_mkio5_bus1    : 1; //!< Исправность связи с ОУ ПУИ-1 МКИО-5A (ИМ2)
   uint16_t pui1_mkio5_bus2    : 1; //!< Исправность связи с ОУ ПУИ-1 МКИО-5B (ИМ2)
} mfci_in_blocks_bis_status_word_8_b_t;

//! Слово 9 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_9_b_t {
   uint16_t absu2_mkio6_bus1 : 1; //!< Исправность связи с ОУ АБСУ-К2 МКИО-6A (ИМ5)
   uint16_t absu2_mkio6_bus2 : 1; //!< Исправность связи с ОУ АБСУ-К2 МКИО-6B (ИМ5)
   uint16_t absu4_mkio6_bus1 : 1; //!< Исправность связи с ОУ АБСУ-К4 МКИО-6A (ИМ5)
   uint16_t absu4_mkio6_bus2 : 1; //!< Исправность связи с ОУ АБСУ-К4 МКИО-6B (ИМ5)
   uint16_t bins2_mkio6_bus1 : 1; //!< Исправность связи с ОУ БИНС-2 МКИО-6A (ИМ5)
   uint16_t bins2_mkio6_bus2 : 1; //!< Исправность связи с ОУ БИНС-2 МКИО-6B (ИМ5)
   uint16_t ans_mkio6_bus1   : 1; //!< Исправность связи с ОУ АНС МКИО-6A (ИМ5)
   uint16_t ans_mkio6_bus2   : 1; //!< Исправность связи с ОУ АНС МКИО-6B (ИМ5)
   uint16_t diss_mkio6_bus1  : 1; //!< Исправность связи с ОУ ДИСС МКИО-6A (ИМ5)
   uint16_t diss_mkio6_bus2  : 1; //!< Исправность связи с ОУ ДИСС МКИО-6B (ИМ5)
   uint16_t pui2_mkio6_bus1  : 1; //!< Исправность связи с ОУ ПУИ-2 МКИО-6A (ИМ5)
   uint16_t pui2_mkio6_bus2  : 1; //!< Исправность связи с ОУ ПУИ-2 МКИО-6B (ИМ5)
   uint16_t                  : 4; //!< Резерв
} mfci_in_blocks_bis_status_word_9_b_t;

//! Слово 10 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_10_b_t {
   uint16_t svr_mkio7_bus1   : 1; //!< Исправность связи с ОУ СВР МКИО-7A (ИМ3)
   uint16_t svr_mkio7_bus2   : 1; //!< Исправность связи с ОУ СВР МКИО-7B (ИМ3)
   uint16_t msrp_mkio7_bus1  : 1; //!< Исправность связи с ОУ МСРП МКИО-7A (ИМ3)
   uint16_t msrp_mkio7_bus2  : 1; //!< Исправность связи с ОУ МСРП МКИО-7B (ИМ3)
   uint16_t bask1_mkio7_bus1 : 1; //!< Исправность связи с ОУ БАСК РМА-1 МКИО-7A (ИМ3)
   uint16_t bask1_mkio7_bus2 : 1; //!< Исправность связи с ОУ БАСК РМА-1 МКИО-7B (ИМ3)
   uint16_t bask2_mkio7_bus1 : 1; //!< Исправность связи с ОУ БАСК РМА-2 МКИО-7A (ИМ3)
   uint16_t bask2_mkio7_bus2 : 1; //!< Исправность связи с ОУ БАСК РМА-2 МКИО-7B (ИМ3)
   uint16_t bks_mkio7_bus1   : 1; //!< Исправность связи с ОУ БКС С-505 МКИО-7A (ИМ3)
   uint16_t bks_mkio7_bus2   : 1; //!< Исправность связи с ОУ БКС С-505 МКИО-7B (ИМ3)
   uint16_t kvr_mkio8_bus1   : 1; //!< Исправность связи с ОУ КВР МКИО-8A (ИМ4)
   uint16_t kvr_mkio8_bus2   : 1; //!< Исправность связи с ОУ КВР МКИО-8B (ИМ4)
   uint16_t vs_mkio8_bus1    : 1; //!< Исправность связи с ОУ НВ ВС-3416 МКИО-8A (ИМ4)
   uint16_t vs_mkio8_bus2    : 1; //!< Исправность связи с ОУ НВ ВС-3416 МКИО-8B (ИМ4)
   uint16_t nv70_mkio8_bus1  : 1; //!< Исправность связи с ОУ НВ-70-3406 МКИО-8A (ИМ4)
   uint16_t nv70_mkio8_bus2  : 1; //!< Исправность связи с ОУ НВ-70-3406 МКИО-8B (ИМ4)
} mfci_in_blocks_bis_status_word_10_b_t;

//! Слово 11 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_11_b_t {
   uint16_t l500_mkio8_bus1 : 1; //!< Исправность связи с ОУ Л-500 МКИО-8A (ИМ4)
   uint16_t l500_mkio8_bus2 : 1; //!< Исправность связи с ОУ Л-500 МКИО-8B (ИМ4)
   uint16_t ubvr_mkio8_bus1 : 1; //!< Исправность связи с ОУ УБВР К134 МКИО-8A (ИМ4)
   uint16_t ubvr_mkio8_bus2 : 1; //!< Исправность связи с ОУ УБВР К134 МКИО-8B (ИМ4)
   uint16_t mup1_mkio8_bus1 : 1; //!< Исправность связи с ОУ МУП-1 МКИО-8A (ИМ4)
   uint16_t mup1_mkio8_bus2 : 1; //!< Исправность связи с ОУ МУП-1 МКИО-8B (ИМ4)
   uint16_t mup2_mkio8_bus1 : 1; //!< Исправность связи с ОУ МУП-2 МКИО-8A (ИМ4)
   uint16_t mup2_mkio8_bus2 : 1; //!< Исправность связи с ОУ МУП-2 МКИО-8B (ИМ4)
   uint16_t uks1_mkio9_bus1 : 1; //!< Исправность связи с ОУ УКС-1 МКИО-9A (ИМ3)
   uint16_t uks1_mkio9_bus2 : 1; //!< Исправность связи с ОУ УКС-1 МКИО-9B (ИМ3)
   uint16_t uks2_mkio9_bus1 : 1; //!< Исправность связи с ОУ УКС-2 МКИО-9A (ИМ3)
   uint16_t uks2_mkio9_bus2 : 1; //!< Исправность связи с ОУ УКС-2 МКИО-9B (ИМ3)
   uint16_t uks3_mkio9_bus1 : 1; //!< Исправность связи с ОУ УКС-3 МКИО-9A (ИМ3)
   uint16_t uks3_mkio9_bus2 : 1; //!< Исправность связи с ОУ УКС-3 МКИО-9B (ИМ3)
   uint16_t uks4_mkio9_bus1 : 1; //!< Исправность связи с ОУ УКС-4 МКИО-9A (ИМ3)
   uint16_t uks4_mkio9_bus2 : 1; //!< Исправность связи с ОУ УКС-4 МКИО-9B (ИМ3)
} mfci_in_blocks_bis_status_word_11_b_t;

//! Слово 12 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_12_b_t {
   uint16_t kskv2_mkio9_bus1      : 1; //!< Исправность связи с ОУ КСКВ-К2 МКИО-9A (ИМ3)
   uint16_t kskv2_mkio9_bus2      : 1; //!< Исправность связи с ОУ КСКВ-К2 МКИО-9B (ИМ3)
   uint16_t bupt245_1_mkio9_bus1  : 1; //!< Исправность связи с ОУ БУПТ-245Ц-1 МКИО-9A (ИМ3)
   uint16_t bupt245_1_mkio9_bus2  : 1; //!< Исправность связи с ОУ БУПТ-245Ц-1 МКИО-9B (ИМ3)
   uint16_t kskv1_mkio10_bus1     : 1; //!< Исправность связи с ОУ КСКВ-К1 МКИО-10A (ИМ4)
   uint16_t kskv1_mkio10_bus2     : 1; //!< Исправность связи с ОУ КСКВ-К1 МКИО-10B (ИМ4)
   uint16_t bupt245_2_mkio10_bus1 : 1; //!< Исправность связи с ОУ БУПТ-245Ц-2 МКИО-10A (ИМ4)
   uint16_t bupt245_2_mkio10_bus2 : 1; //!< Исправность связи с ОУ БУПТ-245Ц-2 МКИО-10B (ИМ4)
   uint16_t uks1_mkio10_bus1      : 1; //!< Исправность связи с ОУ УКС-1 МКИО-10A (ИМ4)
   uint16_t uks1_mkio10_bus2      : 1; //!< Исправность связи с ОУ УКС-1 МКИО-10B (ИМ4)
   uint16_t uks2_mkio10_bus1      : 1; //!< Исправность связи с ОУ УКС-2 МКИО-10A (ИМ4)
   uint16_t uks2_mkio10_bus2      : 1; //!< Исправность связи с ОУ УКС-2 МКИО-10B (ИМ4)
   uint16_t uks3_mkio10_bus1      : 1; //!< Исправность связи с ОУ УКС-3 МКИО-10A (ИМ4)
   uint16_t uks3_mkio10_bus2      : 1; //!< Исправность связи с ОУ УКС-3 МКИО-10B (ИМ4)
   uint16_t uks4_mkio10_bus1      : 1; //!< Исправность связи с ОУ УКС-4 МКИО-10A (ИМ4)
   uint16_t uks4_mkio10_bus2      : 1; //!< Исправность связи с ОУ УКС-4 МКИО-10B (ИМ4)
} mfci_in_blocks_bis_status_word_12_b_t;

//! Слово 13 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_13_b_t {
   uint16_t bau_mkio10_bus1 : 1; //!< Исправность связи с ОУ БЭУ-Р3 МКИО-10A (ИМ4)
   uint16_t bau_mkio10_bus2 : 1; //!< Исправность связи с ОУ БЭУ-Р3 МКИО-10B (ИМ4)
   uint16_t sev1_a429       : 2; //!< Состояние связи с СЕВ С-021-05 к1 Arinc-429 (ИМ1) //(min:0 max:3)
   uint16_t esud2_ud1_a429  : 2; //!< Состояние связи с ЭСУД-2 УД к1 Arinc-429 (ИМ1) //(min:0 max:3)
   uint16_t esud2_sku1_a429 : 2; //!< Состояние связи с ЭСУД-2 СКУ к1 Arinc-429 (ИМ1) //(min:0 max:3)
   uint16_t esud4_ud1_a429  : 2; //!< Состояние связи с ЭСУД-4 УД к1 Arinc-429 (ИМ1) //(min:0 max:3)
   uint16_t esud4_sku1_a429 : 2; //!< Состояние связи с ЭСУД-4 СКУ к1 Arinc-429 (ИМ1) //(min:0 max:3)
   uint16_t vim1_a429       : 2; //!< Состояние связи с VIM-1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t kutc1_a429      : 2; //!< Состояние связи с КУТЦ к1 Arinc-429 (ИМ2) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_13_b_t;

//! Слово 14 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_14_b_t {
   uint16_t a053_1_a429     : 2; //!< Состояние связи с А-053-1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t ab14m_a429      : 2; //!< Состояние связи с АБ-14М Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t svs1_a429       : 2; //!< Состояние связи с СВС-1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t sd75m1_a429     : 2; //!< Состояние связи с СД-75-1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t esud1_ud1_a429  : 2; //!< Состояние связи с ЭСУД-1 УД к1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t esud1_sku1_a429 : 2; //!< Состояние связи с ЭСУД-1 СКУ к1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t esud3_ud1_a429  : 2; //!< Состояние связи с ЭСУД-3 УД к1 Arinc-429 (ИМ2) //(min:0 max:3)
   uint16_t esud3_sku1_a429 : 2; //!< Состояние связи с ЭСУД-3 СКУ к1 Arinc-429 (ИМ2) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_14_b_t;

//! Слово 15 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_15_b_t {
   uint16_t svs3_a429   : 2; //!< Состояние связи с СВС-3 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t ng3240_a429 : 2; //!< Состояние связи с НГ-3240 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t sus1_a429   : 2; //!< Состояние связи с СУС-14А-1 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t sus2_a429   : 2; //!< Состояние связи с СУС-14А-2 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t spmk1_a429  : 2; //!< Состояние связи с СПМК-1 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t spmk2_a429  : 2; //!< Состояние связи с СПМК-2 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t spk1_a429   : 2; //!< Состояние связи с СПК-1 Arinc-429 (ИМ3) //(min:0 max:3)
   uint16_t spk2_a429   : 2; //!< Состояние связи с СПК-2 Arinc-429 (ИМ3) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_15_b_t;

//! Слово 16 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_16_b_t {
   uint16_t esud2_ud2_a429  : 2; //!< Состояние связи с ЭСУД-2 УД к2 Arinc-429 (ИМ4) //(min:0 max:3)
   uint16_t esud2_sku2_a429 : 2; //!< Состояние связи с ЭСУД-2 СКУ к2 Arinc-429 (ИМ4) //(min:0 max:3)
   uint16_t esud4_ud2_a429  : 2; //!< Состояние связи с ЭСУД-4 УД к2 Arinc-429 (ИМ4) //(min:0 max:3)
   uint16_t esud4_sku2_a429 : 2; //!< Состояние связи с ЭСУД-4 СКУ к2 Arinc-429 (ИМ4) //(min:0 max:3)
   uint16_t esud1_ud2_a429  : 2; //!< Состояние связи с ЭСУД-1 УД к2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t esud1_sku2_a429 : 2; //!< Состояние связи с ЭСУД-1 СКУ к2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t esud3_ud2_a429  : 2; //!< Состояние связи с ЭСУД-3 УД к2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t esud3_sku2_a429 : 2; //!< Состояние связи с ЭСУД-3 СКУ к2 Arinc-429 (ИМ5) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_16_b_t;

//! Слово 17 состояния БИС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bis_status_word_17_b_t {
   uint16_t vim2_a429   : 2; //!< Состояние связи с VIM-2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t kutc2_a429  : 2; //!< Состояние связи с КУТЦ к2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t sd75m2_a429 : 2; //!< Состояние связи с СД-75-2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t svs2_a429   : 2; //!< Состояние связи с СВС-2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t a053_2_a429 : 2; //!< Состояние связи с А-053-2 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t a075_a429   : 2; //!< Состояние связи с А-075 Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t ark_a429    : 2; //!< Состояние связи с АРК Arinc-429 (ИМ5) //(min:0 max:3)
   uint16_t sev2_a429   : 2; //!< Состояние связи с СЕВ С-021-05 к2 Arinc-429 (ИМ6) //(min:0 max:3)
} mfci_in_blocks_bis_status_word_17_b_t;

//! Слово 1 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_1_b_t {
   uint16_t integral : 2; //!< Интегральное состояние //(min:0 max:3)
   uint16_t unit01   : 2; //!< Состояние модуля № 1 (МВ100-02-11 ММП1) //(min:0 max:3)
   uint16_t unit02   : 2; //!< Состояние модуля № 2 (МВ102-01) //(min:0 max:3)
   uint16_t unit03   : 2; //!< Состояние модуля № 3 (МВ100-01) //(min:0 max:3)
   uint16_t unit04   : 2; //!< Состояние модуля № 4 (МВ100-01) //(min:0 max:3)
   uint16_t unit05   : 2; //!< Состояние модуля № 5 (МВ101-01 ИМ1) //(min:0 max:3)
   uint16_t unit06   : 2; //!< Состояние модуля № 6 (МВ101-01 ИМ2) //(min:0 max:3)
   uint16_t unit07   : 2; //!< Состояние модуля № 7 (МВ100-01) //(min:0 max:3)
} mfci_in_blocks_bcvm_status_word_1_b_t;

//! Слово 2 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_2_b_t {
   uint16_t unit08         : 2; //!< Состояние модуля № 8 (МВ101-01) //(min:0 max:3)
   uint16_t unit09         : 2; //!< Состояние модуля № 9 (МВ100-01) //(min:0 max:3)
   uint16_t unit10         : 2; //!< Состояние модуля № 10 (МВ100-02-11 ММП2) //(min:0 max:3)
   uint16_t unit11         : 2; //!< Состояние модуля № 11 (МС102) //(min:0 max:3)
   uint16_t unit12         : 2; //!< Состояние модуля № 12 (МС102) //(min:0 max:3)
   uint16_t unit13         : 2; //!< Состояние модуля № 13 (МН100) //(min:0 max:3)
   uint16_t unit14         : 2; //!< Состояние модуля № 14 (МН100) //(min:0 max:3)
   uint16_t bks_mkio2_bus1 : 1; //!< Исправность связи с ОУ БКС С-505 МКИО-2A (ИМ1)
   uint16_t bks_mkio2_bus2 : 1; //!< Исправность связи с ОУ БКС С-505 МКИО-2B (ИМ1)
} mfci_in_blocks_bcvm_status_word_2_b_t;

//! Слово 3 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_3_b_t {
   uint16_t mmp1_bcvm_spacewire : 2; //!< Состояние связи c другим БЦВМ SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bis1_spacewire : 2; //!< Состояние связи c БИС-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bis2_spacewire : 2; //!< Состояние связи c БИС-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_kvi1_spacewire : 2; //!< Состояние связи c КВИ-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_kvi2_spacewire : 2; //!< Состояние связи c КВИ-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bgs1_spacewire : 2; //!< Состояние связи c БГС-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bgs2_spacewire : 2; //!< Состояние связи c БГС-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_sbi_spacewire  : 2; //!< Состояние связи c СБИ SpaceWire (на ММП1) //(min:0 max:3)
} mfci_in_blocks_bcvm_status_word_3_b_t;

//! Слово 4 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_4_b_t {
   uint16_t mmp2_bcvm_spacewire : 2; //!< Состояние связи c другим БЦВМ SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bis1_spacewire : 2; //!< Состояние связи c БИС-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bis2_spacewire : 2; //!< Состояние связи c БИС-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_kvi1_spacewire : 2; //!< Состояние связи c КВИ-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_kvi2_spacewire : 2; //!< Состояние связи c КВИ-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bgs1_spacewire : 2; //!< Состояние связи c БГС-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bgs2_spacewire : 2; //!< Состояние связи c БГС-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_sbi_spacewire  : 2; //!< Состояние связи c СБИ SpaceWire (на ММП2) //(min:0 max:3)
} mfci_in_blocks_bcvm_status_word_4_b_t;

//! Слово 5 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_5_b_t {
   uint16_t mmp1_bvd1_spacewire    : 2; //!< Состояние связи c БВД-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bvd2_spacewire    : 2; //!< Состояние связи c БВД-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp2_bvd1_spacewire    : 2; //!< Состояние связи c БВД-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bvd2_spacewire    : 2; //!< Состояние связи c БВД-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mfpu1_mkio1_2_bus1     : 1; //!< Исправность связи с ОУ МФПУ-1 МКИО-1.2A (ИМ2)
   uint16_t mfpu1_mkio1_2_bus2     : 1; //!< Исправность связи с ОУ МФПУ-1 МКИО-1.2B (ИМ2)
   uint16_t mfpu2_mkio1_2_bus1     : 1; //!< Исправность связи с ОУ МФПУ-2 МКИО-1.2A (ИМ2)
   uint16_t mfpu2_mkio1_2_bus2     : 1; //!< Исправность связи с ОУ МФПУ-2 МКИО-1.2B (ИМ2)
   uint16_t mfpu3_mkio1_2_bus1     : 1; //!< Исправность связи с ОУ МФПУ-3 МКИО-1.2A (ИМ2)
   uint16_t mfpu3_mkio1_2_bus2     : 1; //!< Исправность связи с ОУ МФПУ-3 МКИО-1.2B (ИМ2)
   uint16_t board19da_mkio1_2_bus1 : 1; //!< Исправность связи с ОУ 19-ДА МКИО-1.2A (ИМ2)
   uint16_t board19da_mkio1_2_bus2 : 1; //!< Исправность связи с ОУ 19-ДА МКИО-1.2B (ИМ2)
} mfci_in_blocks_bcvm_status_word_5_b_t;

//! Слово 6 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_6_b_t {
   uint16_t bis1_mkio1_2_bus1 : 1; //!< Исправность связи с ОУ БИС-1 МКИО-1.2A (ИМ2)
   uint16_t bis1_mkio1_2_bus2 : 1; //!< Исправность связи с ОУ БИС-1 МКИО-1.2B (ИМ2)
   uint16_t bis2_mkio1_2_bus1 : 1; //!< Исправность связи с ОУ БИС-2 МКИО-1.2A (ИМ2)
   uint16_t bis2_mkio1_2_bus2 : 1; //!< Исправность связи с ОУ БИС-2 МКИО-1.2B (ИМ2)
   uint16_t bis1_mkio2_bus1   : 1; //!< Исправность связи с ОУ БИС-1 МКИО-2A (ИМ1)
   uint16_t bis1_mkio2_bus2   : 1; //!< Исправность связи с ОУ БИС-1 МКИО-2B (ИМ1)
   uint16_t bis2_mkio2_bus1   : 1; //!< Исправность связи с ОУ БИС-2 МКИО-2A (ИМ1)
   uint16_t bis2_mkio2_bus2   : 1; //!< Исправность связи с ОУ БИС-2 МКИО-2B (ИМ1)
   uint16_t kvi1_mkio2_bus1   : 1; //!< Исправность связи с ОУ КВИ-1 МКИО-2A (ИМ1)
   uint16_t kvi1_mkio2_bus2   : 1; //!< Исправность связи с ОУ КВИ-1 МКИО-2B (ИМ1)
   uint16_t kvi2_mkio2_bus1   : 1; //!< Исправность связи с ОУ КВИ-2 МКИО-2A (ИМ1)
   uint16_t kvi2_mkio2_bus2   : 1; //!< Исправность связи с ОУ КВИ-2 МКИО-2B (ИМ1)
   uint16_t bvd1_mkio2_bus1   : 1; //!< Исправность связи с ОУ БВД-1 МКИО-2A (ИМ1)
   uint16_t bvd1_mkio2_bus2   : 1; //!< Исправность связи с ОУ БВД-1 МКИО-2B (ИМ1)
   uint16_t bvd2_mkio2_bus1   : 1; //!< Исправность связи с ОУ БВД-2 МКИО-2A (ИМ1)
   uint16_t bvd2_mkio2_bus2   : 1; //!< Исправность связи с ОУ БВД-2 МКИО-2B (ИМ1)
} mfci_in_blocks_bcvm_status_word_6_b_t;

//! Слово 7 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_7_b_t {
   uint16_t board19da_mkio2_bus1 : 1; //!< Исправность связи с ОУ 19-ДА МКИО-2A (ИМ1)
   uint16_t board19da_mkio2_bus2 : 1; //!< Исправность связи с ОУ 19-ДА МКИО-2B (ИМ1)
   uint16_t bgs1_mkio3_2_bus1    : 1; //!< Исправность связи с ОУ БГС-1 МКИО-3.2A (ИМ2)
   uint16_t bgs1_mkio3_2_bus2    : 1; //!< Исправность связи с ОУ БГС-1 МКИО-3.2B (ИМ2)
   uint16_t bgs2_mkio3_2_bus1    : 1; //!< Исправность связи с ОУ БГС-2 МКИО-3.2A (ИМ2)
   uint16_t bgs2_mkio3_2_bus2    : 1; //!< Исправность связи с ОУ БГС-2 МКИО-3.2B (ИМ2)
   uint16_t mfci01_mkio3_2_bus1  : 1; //!< Исправность связи с ОУ МФЦИ-1 МКИО-3.2A (ИМ2)
   uint16_t mfci01_mkio3_2_bus2  : 1; //!< Исправность связи с ОУ МФЦИ-1 МКИО-3.2B (ИМ2)
   uint16_t mfci02_mkio3_2_bus1  : 1; //!< Исправность связи с ОУ МФЦИ-2 МКИО-3.2A (ИМ2)
   uint16_t mfci02_mkio3_2_bus2  : 1; //!< Исправность связи с ОУ МФЦИ-2 МКИО-3.2B (ИМ2)
   uint16_t mfci03_mkio3_2_bus1  : 1; //!< Исправность связи с ОУ МФЦИ-3 МКИО-3.2A (ИМ2)
   uint16_t mfci03_mkio3_2_bus2  : 1; //!< Исправность связи с ОУ МФЦИ-3 МКИО-3.2B (ИМ2)
   uint16_t mfci04_mkio3_2_bus1  : 1; //!< Исправность связи с ОУ МФЦИ-4 МКИО-3.2A (ИМ2)
   uint16_t mfci04_mkio3_2_bus2  : 1; //!< Исправность связи с ОУ МФЦИ-4 МКИО-3.2B (ИМ2)
   uint16_t mfci05_mkio3_2_bus1  : 1; //!< Исправность связи с ОУ МФЦИ-5 МКИО-3.2A (ИМ2)
   uint16_t mfci05_mkio3_2_bus2  : 1; //!< Исправность связи с ОУ МФЦИ-5 МКИО-3.2B (ИМ2)
} mfci_in_blocks_bcvm_status_word_7_b_t;

//! Слово 8 состояния БЦВМ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bcvm_status_word_8_b_t {
   uint16_t mfci06_mkio3_2_bus1     : 1; //!< Исправность связи с ОУ МФЦИ-6 МКИО-3.2A (ИМ2)
   uint16_t mfci06_mkio3_2_bus2     : 1; //!< Исправность связи с ОУ МФЦИ-6 МКИО-3.2B (ИМ2)
   uint16_t mfci07_mkio3_2_bus1     : 1; //!< Исправность связи с ОУ МФЦИ-7 МКИО-3.2A (ИМ2)
   uint16_t mfci07_mkio3_2_bus2     : 1; //!< Исправность связи с ОУ МФЦИ-7 МКИО-3.2B (ИМ2)
   uint16_t mfci08_mkio3_2_bus1     : 1; //!< Исправность связи с ОУ МФЦИ-8 МКИО-3.2A (ИМ2)
   uint16_t mfci08_mkio3_2_bus2     : 1; //!< Исправность связи с ОУ МФЦИ-8 МКИО-3.2B (ИМ2)
   uint16_t mfci09_mkio3_2_bus1     : 1; //!< Исправность связи с ОУ МФЦИ-9 МКИО-3.2A (ИМ2)
   uint16_t mfci09_mkio3_2_bus2     : 1; //!< Исправность связи с ОУ МФЦИ-9 МКИО-3.2B (ИМ2)
   uint16_t mfci10_mkio3_2_bus1     : 1; //!< Исправность связи с ОУ МФЦИ-10 МКИО-3.2A (ИМ2)
   uint16_t mfci10_mkio3_2_bus2     : 1; //!< Исправность связи с ОУ МФЦИ-10 МКИО-3.2B (ИМ2)
   uint16_t mfci11_mkio3_2_bus1     : 1; //!< Исправность связи с ОУ МФЦИ-11 МКИО-3.2A (ИМ2)
   uint16_t mfci11_mkio3_2_bus2     : 1; //!< Исправность связи с ОУ МФЦИ-11 МКИО-3.2B (ИМ2)
   uint16_t u83t0214m1_mkio1_2_bus1 : 1; //!< Исправность связи с ОУ 83т0214М-1 МКИО-1.2A (ИМ2)
   uint16_t u83t0214m1_mkio1_2_bus2 : 1; //!< Исправность связи с ОУ 83т0214М-1 МКИО-1.2B (ИМ2)
   uint16_t                         : 2; //!< Резерв
} mfci_in_blocks_bcvm_status_word_8_b_t;

//! Слово 1 состояния БВД (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bvd_status_word_1_b_t {
   uint16_t integral     : 2;  //!< Интегральное состояние //(min:0 max:3)
   uint16_t mv102_3      : 1;  //!< Исправность МВ102-03
   uint16_t mv101_4_1    : 1;  //!< Исправность МВ101-04 (МВ106-04) № 1
   uint16_t mv101_4_2    : 1;  //!< Исправность МВ101-04 (МВ106-04) № 2
   uint16_t crc_mismatch : 1;  //!< Отличие интегральных контрольных сумм БВД-1 и БВД-2
   uint16_t              : 10; //!< Резерв
} mfci_in_blocks_bvd_status_word_1_b_t;

//! Слово 2 состояния БВД (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bvd_status_word_2_b_t {
   uint16_t mmp_bgs1_spacewire  : 2; //!< Состояние связи с БГС-1 SpaceWire //(min:0 max:3)
   uint16_t mmp_bgs2_spacewire  : 2; //!< Состояние связи с БГС-2 SpaceWire //(min:0 max:3)
   uint16_t mmp_bcvm1_spacewire : 2; //!< Состояние связи с БЦВМ-1 SpaceWire //(min:0 max:3)
   uint16_t mmp_bcvm2_spacewire : 2; //!< Состояние связи с БЦВМ-2 SpaceWire //(min:0 max:3)
   uint16_t mmp_kvi1_spacewire  : 2; //!< Состояние связи с КВИ-1 SpaceWire //(min:0 max:3)
   uint16_t mmp_kvi2_spacewire  : 2; //!< Состояние связи с КВИ-2 SpaceWire //(min:0 max:3)
   uint16_t                     : 4; //!< Резерв
} mfci_in_blocks_bvd_status_word_2_b_t;

//! Слово 3 состояния БВД (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bvd_status_word_3_b_t {
   uint16_t cassette1      : 1; //!< Исправность НД 1
   uint16_t cassette2      : 1; //!< Исправность НД 2
   uint16_t cassette3      : 1; //!< Исправность НД 3
   uint16_t cassette4      : 1; //!< Исправность НД 4
   uint16_t cassette1_type : 3; //!< Тип НД 1 (0 - НД отсутствует, 1 - КТ-1, 2 - К-36М, 3 - К-32Г, 4 - К-64М) //(min:0 max:4)
   uint16_t cassette2_type : 3; //!< Тип НД 2 (0 - НД отсутствует, 1 - КТ-1, 2 - К-36М, 3 - К-32Г, 4 - К-64М) //(min:0 max:4)
   uint16_t cassette3_type : 3; //!< Тип НД 3 (0 - НД отсутствует, 1 - КТ-1, 2 - К-36М, 3 - К-32Г, 4 - К-64М) //(min:0 max:4)
   uint16_t cassette4_type : 3; //!< Тип НД 4 (0 - НД отсутствует, 1 - КТ-1, 2 - К-36М, 3 - К-32Г, 4 - К-64М) //(min:0 max:4)
} mfci_in_blocks_bvd_status_word_3_b_t;

//! Слово состояния УКС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_uks_status_word_b_t {
   uint16_t uks1_integral  : 2; //!< УКС-1 Интегральное состояние //(min:0 max:3)
   uint16_t uks1_msrp_a429 : 2; //!< УКС-1 Состояние связи с МСРП Arinc-429 (МСПР->УКС) //(min:0 max:3)
   uint16_t uks2_integral  : 2; //!< УКС-2 Интегральное состояние //(min:0 max:3)
   uint16_t uks2_msrp_a429 : 2; //!< УКС-2 Состояние связи с МСРП Arinc-429 (МСПР->УКС) //(min:0 max:3)
   uint16_t uks3_integral  : 2; //!< УКС-3 Интегральное состояние //(min:0 max:3)
   uint16_t uks3_msrp_a429 : 2; //!< УКС-3 Состояние связи с МСРП Arinc-429 (МСПР->УКС) //(min:0 max:3)
   uint16_t uks4_integral  : 2; //!< УКС-4 Интегральное состояние //(min:0 max:3)
   uint16_t uks4_msrp_a429 : 2; //!< УКС-4 Состояние связи с МСРП Arinc-429 (МСПР->УКС) //(min:0 max:3)
} mfci_in_blocks_uks_status_word_b_t;

//! Слово состояния МФПУ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfpu_status_word_b_t {
   uint16_t mfpu1_integral   : 2; //!< МФПУ-1 Интегральное состояние //(min:0 max:3)
   uint16_t mfpu1_buttons    : 1; //!< МФПУ-1 Исправность кнопок
   uint16_t mfpu1_brightness : 1; //!< МФПУ-1 Исправность регулировки яркости
   uint16_t mfpu2_integral   : 2; //!< МФПУ-2 Интегральное состояние //(min:0 max:3)
   uint16_t mfpu2_buttons    : 1; //!< МФПУ-2 Исправность кнопок
   uint16_t mfpu2_brightness : 1; //!< МФПУ-2 Исправность регулировки яркости
   uint16_t mfpu3_integral   : 2; //!< МФПУ-3 Интегральное состояние //(min:0 max:3)
   uint16_t mfpu3_buttons    : 1; //!< МФПУ-3 Исправность кнопок
   uint16_t mfpu3_brightness : 1; //!< МФПУ-3 Исправность регулировки яркости
   uint16_t                  : 4; //!< Резерв
} mfci_in_blocks_mfpu_status_word_b_t;

//! Слово 1 состояния БГС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bgs_status_word_1_b_t {
   uint16_t integral : 2; //!< Интегральное состояние //(min:0 max:3)
   uint16_t unit01   : 2; //!< Состояние модуля № 1 (МВ102-02-11 ММП) //(min:0 max:3)
   uint16_t unit02   : 2; //!< Состояние модуля № 2 (МК100) //(min:0 max:3)
   uint16_t unit03   : 2; //!< Состояние модуля № 3 (МГ100 МГ1) //(min:0 max:3)
   uint16_t unit04   : 2; //!< Состояние модуля № 4 (МГ100 МГ2) //(min:0 max:3)
   uint16_t unit05   : 2; //!< Состояние модуля № 5 (МГ100 МГ3) //(min:0 max:3)
   uint16_t unit06   : 2; //!< Состояние модуля № 6 (МГ100 МГ4) //(min:0 max:3)
   uint16_t unit07   : 2; //!< Состояние модуля № 7 (МГ100 МГ5) //(min:0 max:3)
} mfci_in_blocks_bgs_status_word_1_b_t;

//! Слово 2 состояния БГС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bgs_status_word_2_b_t {
   uint16_t unit08 : 2; //!< Состояние модуля № 8 (МГ100 МГ6) //(min:0 max:3)
   uint16_t unit09 : 2; //!< Состояние модуля № 9 (МК100) //(min:0 max:3)
   uint16_t unit10 : 2; //!< Состояние модуля № 10 (МВ101-01 ИМ1) //(min:0 max:3)
   uint16_t unit11 : 2; //!< Состояние модуля № 11 (МС102-01) //(min:0 max:3)
   uint16_t unit12 : 2; //!< Состояние модуля № 12 (МС102-01) //(min:0 max:3)
   uint16_t unit13 : 2; //!< Состояние модуля № 13 (МН100) //(min:0 max:3)
   uint16_t unit14 : 2; //!< Состояние модуля № 14 (МН100) //(min:0 max:3)
   uint16_t        : 2; //!< Резерв
} mfci_in_blocks_bgs_status_word_2_b_t;

//! Слово 3 состояния БГС (для кадра БЛОКИ)
typedef struct mfci_in_blocks_bgs_status_word_3_b_t {
   uint16_t bis1_spacewire  : 2; //!< Состояние связи c БИС-1 SpaceWire //(min:0 max:3)
   uint16_t bis2_spacewire  : 2; //!< Состояние связи c БИС-2 SpaceWire //(min:0 max:3)
   uint16_t bcvm1_spacewire : 2; //!< Состояние связи c БЦВМ-1 SpaceWire //(min:0 max:3)
   uint16_t bcvm2_spacewire : 2; //!< Состояние связи c БЦВМ-2 SpaceWire //(min:0 max:3)
   uint16_t bvd1_spacewire  : 2; //!< Состояние связи c БВД-1 SpaceWire //(min:0 max:3)
   uint16_t bvd2_spacewire  : 2; //!< Состояние связи c БВД-2 SpaceWire //(min:0 max:3)
   uint16_t kvr_a818        : 1; //!< Исправность связи c КВР-70М Arinc-818
   uint16_t nv_a818         : 1; //!< Исправность связи c НВ-70М Arinc-818
   uint16_t svr_a818        : 1; //!< Исправность связи c СВР Arinc-818
   uint16_t                 : 1; //!< Резерв
} mfci_in_blocks_bgs_status_word_3_b_t;

//! Слово 1 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_1_b_t {
   uint16_t mfci1_integral : 2; //!< Интегральное состояние МФЦИ-1 //(min:0 max:3)
   uint16_t mfci2_integral : 2; //!< Интегральное состояние МФЦИ-2 //(min:0 max:3)
   uint16_t mfci3_integral : 2; //!< Интегральное состояние МФЦИ-3 //(min:0 max:3)
   uint16_t mfci4_integral : 2; //!< Интегральное состояние МФЦИ-4 //(min:0 max:3)
   uint16_t mfci5_integral : 2; //!< Интегральное состояние МФЦИ-5 //(min:0 max:3)
   uint16_t mfci6_integral : 2; //!< Интегральное состояние МФЦИ-6 //(min:0 max:3)
   uint16_t mfci7_integral : 2; //!< Интегральное состояние МФЦИ-7 //(min:0 max:3)
   uint16_t mfci8_integral : 2; //!< Интегральное состояние МФЦИ-8 //(min:0 max:3)
} mfci_in_blocks_mfci_status_word_1_b_t;

//! Слово 2 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_2_b_t {
   uint16_t mfci9_integral  : 2; //!< Интегральное состояние МФЦИ-9 //(min:0 max:3)
   uint16_t mfci10_integral : 2; //!< Интегральное состояние МФЦИ-10 //(min:0 max:3)
   uint16_t mfci11_integral : 2; //!< Интегральное состояние МФЦИ-11 //(min:0 max:3)
   uint16_t mfci1_mv        : 1; //!< Исправность МВ МФЦИ-1 (МС24)
   uint16_t mfci2_mv        : 1; //!< Исправность МВ МФЦИ-2 (МС24)
   uint16_t mfci3_mv        : 1; //!< Исправность МВ МФЦИ-3 (МС24)
   uint16_t mfci4_mv        : 1; //!< Исправность МВ МФЦИ-4 (МС24)
   uint16_t mfci5_mv        : 1; //!< Исправность МВ МФЦИ-5 (МС24)
   uint16_t mfci6_mv        : 1; //!< Исправность МВ МФЦИ-6 (МС24)
   uint16_t mfci7_mv        : 1; //!< Исправность МВ МФЦИ-7 (МС24)
   uint16_t mfci8_mv        : 1; //!< Исправность МВ МФЦИ-8 (МС24)
   uint16_t mfci9_mv        : 1; //!< Исправность МВ МФЦИ-9 (МС24)
   uint16_t mfci10_mv       : 1; //!< Исправность МВ МФЦИ-10 (МС24)
} mfci_in_blocks_mfci_status_word_2_b_t;

//! Слово 3 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_3_b_t {
   uint16_t mfci11_mv   : 1; //!< Исправность МВ МФЦИ-11 (МС24)
   uint16_t mfci1_mg24  : 1; //!< Исправность МГ24 МФЦИ-1 (МС25)
   uint16_t mfci2_mg24  : 1; //!< Исправность МГ24 МФЦИ-2 (МС25)
   uint16_t mfci3_mg24  : 1; //!< Исправность МГ24 МФЦИ-3 (МС25)
   uint16_t mfci4_mg24  : 1; //!< Исправность МГ24 МФЦИ-4 (МС25)
   uint16_t mfci5_mg24  : 1; //!< Исправность МГ24 МФЦИ-5 (МС25)
   uint16_t mfci6_mg24  : 1; //!< Исправность МГ24 МФЦИ-6 (МС25)
   uint16_t mfci7_mg24  : 1; //!< Исправность МГ24 МФЦИ-7 (МС25)
   uint16_t mfci8_mg24  : 1; //!< Исправность МГ24 МФЦИ-8 (МС25)
   uint16_t mfci9_mg24  : 1; //!< Исправность МГ24 МФЦИ-9 (МС25)
   uint16_t mfci10_mg24 : 1; //!< Исправность МГ24 МФЦИ-10 (МС25)
   uint16_t mfci11_mg24 : 1; //!< Исправность МГ24 МФЦИ-11 (МС25)
   uint16_t mfci1_mg428 : 1; //!< Исправность МГ428 МФЦИ-1 (МС428)
   uint16_t mfci2_mg428 : 1; //!< Исправность МГ428 МФЦИ-2 (МС428)
   uint16_t mfci3_mg428 : 1; //!< Исправность МГ428 МФЦИ-3 (МС428)
   uint16_t mfci4_mg428 : 1; //!< Исправность МГ428 МФЦИ-4 (МС428)
} mfci_in_blocks_mfci_status_word_3_b_t;

//! Слово 4 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_4_b_t {
   uint16_t mfci5_mg428  : 1; //!< Исправность МГ428 МФЦИ-5 (МС428)
   uint16_t mfci6_mg428  : 1; //!< Исправность МГ428 МФЦИ-6 (МС428)
   uint16_t mfci7_mg428  : 1; //!< Исправность МГ428 МФЦИ-7 (МС428)
   uint16_t mfci8_mg428  : 1; //!< Исправность МГ428 МФЦИ-8 (МС428)
   uint16_t mfci9_mg428  : 1; //!< Исправность МГ428 МФЦИ-9 (МС428)
   uint16_t mfci10_mg428 : 1; //!< Исправность МГ428 МФЦИ-10 (МС428)
   uint16_t mfci11_mg428 : 1; //!< Исправность МГ428 МФЦИ-11 (МС428)
   uint16_t mfci1_mn     : 1; //!< Исправность МН100 МФЦИ-1
   uint16_t mfci2_mn     : 1; //!< Исправность МН100 МФЦИ-2
   uint16_t mfci3_mn     : 1; //!< Исправность МН100 МФЦИ-3
   uint16_t mfci4_mn     : 1; //!< Исправность МН100 МФЦИ-4
   uint16_t mfci5_mn     : 1; //!< Исправность МН100 МФЦИ-5
   uint16_t mfci6_mn     : 1; //!< Исправность МН100 МФЦИ-6
   uint16_t mfci7_mn     : 1; //!< Исправность МН100 МФЦИ-7
   uint16_t mfci8_mn     : 1; //!< Исправность МН100 МФЦИ-8
   uint16_t mfci9_mn     : 1; //!< Исправность МН100 МФЦИ-9
} mfci_in_blocks_mfci_status_word_4_b_t;

//! Слово 5 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_5_b_t {
   uint16_t mfci10_mn        : 1; //!< Исправность МН100 МФЦИ-10
   uint16_t mfci11_mn        : 1; //!< Исправность МН100 МФЦИ-11
   uint16_t mfci1_buttons    : 1; //!< Исправность кнопок МФЦИ-1
   uint16_t mfci2_buttons    : 1; //!< Исправность кнопок МФЦИ-2
   uint16_t mfci3_buttons    : 1; //!< Исправность кнопок МФЦИ-3
   uint16_t mfci4_buttons    : 1; //!< Исправность кнопок МФЦИ-4
   uint16_t mfci5_buttons    : 1; //!< Исправность кнопок МФЦИ-5
   uint16_t mfci6_buttons    : 1; //!< Исправность кнопок МФЦИ-6
   uint16_t mfci7_buttons    : 1; //!< Исправность кнопок МФЦИ-7
   uint16_t mfci8_buttons    : 1; //!< Исправность кнопок МФЦИ-8
   uint16_t mfci9_buttons    : 1; //!< Исправность кнопок МФЦИ-9
   uint16_t mfci10_buttons   : 1; //!< Исправность кнопок МФЦИ-10
   uint16_t mfci11_buttons   : 1; //!< Исправность кнопок МФЦИ-11
   uint16_t mfci1_brightness : 1; //!< Исправность регулировки яркости МФЦИ-1
   uint16_t mfci2_brightness : 1; //!< Исправность регулировки яркости МФЦИ-2
   uint16_t mfci3_brightness : 1; //!< Исправность регулировки яркости МФЦИ-3
} mfci_in_blocks_mfci_status_word_5_b_t;

//! Слово 6 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_6_b_t {
   uint16_t mfci4_brightness  : 1; //!< Исправность регулировки яркости МФЦИ-4
   uint16_t mfci5_brightness  : 1; //!< Исправность регулировки яркости МФЦИ-5
   uint16_t mfci6_brightness  : 1; //!< Исправность регулировки яркости МФЦИ-6
   uint16_t mfci7_brightness  : 1; //!< Исправность регулировки яркости МФЦИ-7
   uint16_t mfci8_brightness  : 1; //!< Исправность регулировки яркости МФЦИ-8
   uint16_t mfci9_brightness  : 1; //!< Исправность регулировки яркости МФЦИ-9
   uint16_t mfci10_brightness : 1; //!< Исправность регулировки яркости МФЦИ-10
   uint16_t mfci11_brightness : 1; //!< Исправность регулировки яркости МФЦИ-11
   uint16_t mfci1_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-1
   uint16_t mfci2_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-2
   uint16_t mfci3_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-3
   uint16_t mfci4_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-4
   uint16_t mfci5_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-5
   uint16_t mfci6_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-6
   uint16_t mfci7_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-7
   uint16_t mfci8_contrast    : 1; //!< Исправность регулировки контрастности МФЦИ-8
} mfci_in_blocks_mfci_status_word_6_b_t;

//! Слово 7 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_7_b_t {
   uint16_t mfci9_contrast   : 1; //!< Исправность регулировки контрастности МФЦИ-9
   uint16_t mfci10_contrast  : 1; //!< Исправность регулировки контрастности МФЦИ-10
   uint16_t mfci11_contrast  : 1; //!< Исправность регулировки контрастности МФЦИ-11
   uint16_t mfci1_bgs1_a818  : 1; //!< Исправность связи МФЦИ-1 с БГС-1 Arinc-818
   uint16_t mfci2_bgs1_a818  : 1; //!< Исправность связи МФЦИ-2 с БГС-1 Arinc-818
   uint16_t mfci3_bgs1_a818  : 1; //!< Исправность связи МФЦИ-3 с БГС-1 Arinc-818
   uint16_t mfci4_bgs1_a818  : 1; //!< Исправность связи МФЦИ-4 с БГС-1 Arinc-818
   uint16_t mfci5_bgs1_a818  : 1; //!< Исправность связи МФЦИ-5 с БГС-1 Arinc-818
   uint16_t mfci6_bgs1_a818  : 1; //!< Исправность связи МФЦИ-6 с БГС-1 Arinc-818
   uint16_t mfci7_bgs1_a818  : 1; //!< Исправность связи МФЦИ-7 с БГС-1 Arinc-818
   uint16_t mfci8_bgs1_a818  : 1; //!< Исправность связи МФЦИ-8 с БГС-1 Arinc-818
   uint16_t mfci9_bgs1_a818  : 1; //!< Исправность связи МФЦИ-9 с БГС-1 Arinc-818
   uint16_t mfci10_bgs1_a818 : 1; //!< Исправность связи МФЦИ-10 с БГС-1 Arinc-818
   uint16_t mfci11_bgs1_a818 : 1; //!< Исправность связи МФЦИ-11 с БГС-1 Arinc-818
   uint16_t mfci1_bgs2_a818  : 1; //!< Исправность связи МФЦИ-1 с БГС-2 Arinc-818
   uint16_t mfci2_bgs2_a818  : 1; //!< Исправность связи МФЦИ-2 с БГС-2 Arinc-818
} mfci_in_blocks_mfci_status_word_7_b_t;

//! Слово 8 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_8_b_t {
   uint16_t mfci3_bgs2_a818  : 1; //!< Исправность связи МФЦИ-3 с БГС-2 Arinc-818
   uint16_t mfci4_bgs2_a818  : 1; //!< Исправность связи МФЦИ-4 с БГС-2 Arinc-818
   uint16_t mfci5_bgs2_a818  : 1; //!< Исправность связи МФЦИ-5 с БГС-2 Arinc-818
   uint16_t mfci6_bgs2_a818  : 1; //!< Исправность связи МФЦИ-6 с БГС-2 Arinc-818
   uint16_t mfci7_bgs2_a818  : 1; //!< Исправность связи МФЦИ-7 с БГС-2 Arinc-818
   uint16_t mfci8_bgs2_a818  : 1; //!< Исправность связи МФЦИ-8 с БГС-2 Arinc-818
   uint16_t mfci9_bgs2_a818  : 1; //!< Исправность связи МФЦИ-9 с БГС-2 Arinc-818
   uint16_t mfci10_bgs2_a818 : 1; //!< Исправность связи МФЦИ-10 с БГС-2 Arinc-818
   uint16_t mfci11_bgs2_a818 : 1; //!< Исправность связи МФЦИ-11 с БГС-2 Arinc-818
   uint16_t mfci1_vim1       : 1; //!< Исправность связи МФЦИ-1 с VIM-1 Arinc-429
   uint16_t mfci1_rsbn       : 1; //!< Исправность связи МФЦИ-1 с РСБН Arinc-429
   uint16_t mfci1_svs1       : 1; //!< Исправность связи МФЦИ-1 с СВС-1 Arinc-429
   uint16_t mfci1_rvm1       : 1; //!< Исправность связи МФЦИ-1 с РВМ-1 Arinc-429
   uint16_t mfci1_ark        : 1; //!< Исправность связи МФЦИ-1 с АРК Arinc-429
   uint16_t mfci1_bins1      : 1; //!< Исправность связи МФЦИ-1 с БИНС-1 Arinc-429
   uint16_t mfci3_vim2       : 1; //!< Исправность связи МФЦИ-3 с VIM-2 Arinc-429
} mfci_in_blocks_mfci_status_word_8_b_t;

//! Слово 9 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_9_b_t {
   uint16_t mfci3_rsbn  : 1; //!< Исправность связи МФЦИ-3 с РСБН Arinc-429
   uint16_t mfci3_svs1  : 1; //!< Исправность связи МФЦИ-3 с СВС-1 Arinc-429
   uint16_t mfci3_pnap  : 1; //!< Исправность связи МФЦИ-3 с ПНАП-ПЛА Arinc-429
   uint16_t mfci3_ark   : 1; //!< Исправность связи МФЦИ-3 с АРК Arinc-429
   uint16_t mfci3_bins1 : 1; //!< Исправность связи МФЦИ-3 с БИНС-1 Arinc-429
   uint16_t mfci5_bins2 : 1; //!< Исправность связи МФЦИ-5 с БИНС-2 Arinc-429
   uint16_t mfci5_svs2  : 1; //!< Исправность связи МФЦИ-5 с СВС-2 Arinc-429
   uint16_t mfci5_vim1  : 1; //!< Исправность связи МФЦИ-5 с VIM-1 Arinc-429
   uint16_t mfci5_rvm2  : 1; //!< Исправность связи МФЦИ-5 с РВМ-2 Arinc-429
   uint16_t mfci5_rsbn  : 1; //!< Исправность связи МФЦИ-5 с РСБН Arinc-429
   uint16_t mfci5_ark   : 1; //!< Исправность связи МФЦИ-5 с АРК Arinc-429
   uint16_t mfci8_rsbn  : 1; //!< Исправность связи МФЦИ-8 с РСБН Arinc-429
   uint16_t mfci8_svs1  : 1; //!< Исправность связи МФЦИ-8 с СВС-1 Arinc-429
   uint16_t mfci8_rvm1  : 1; //!< Исправность связи МФЦИ-8 с РВМ-1 Arinc-429
   uint16_t mfci8_ark   : 1; //!< Исправность связи МФЦИ-8 с АРК Arinc-429
   uint16_t mfci8_bins1 : 1; //!< Исправность связи МФЦИ-8 с БИНС-1 Arinc-429
} mfci_in_blocks_mfci_status_word_9_b_t;

//! Слово 10 состояния МФЦИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_mfci_status_word_10_b_t {
   uint16_t mfci8_pnap : 1;  //!< Исправность связи МФЦИ-8 с ПНАП-ПЛА Arinc-429
   uint16_t            : 15; //!< Резерв
} mfci_in_blocks_mfci_status_word_10_b_t;

//! Выбранные для взаимодействия системы (слово 1, для кадра БЛОКИ)
typedef struct mfci_in_blocks_selected_systems_1_b_t {
   uint16_t bis_selected_number  : 2; //!< Номер БИС, выбранной для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t bcvm_selected_number : 2; //!< Номер БЦВМ, выбранной для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t bvd_selected_number  : 2; //!< Номер БВД, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t kvi_selected_number  : 2; //!< Номер КВИ, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t ins_selected_number  : 2; //!< Номер ИНС, выбранной для взаимодействия (0-н/д) //(min:0 max:3)
   uint16_t svs_selected_number  : 2; //!< Номер СВС, выбранной для взаимодействия (0-н/д) //(min:0 max:3)
   uint16_t rvm_selected_number  : 2; //!< Номер РВМ, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t kutc_selected_number : 2; //!< Номер канала КУТЦ, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
} mfci_in_blocks_selected_systems_1_b_t;

//! Выбранные для взаимодействия системы (слово 2, для кадра БЛОКИ)
typedef struct mfci_in_blocks_selected_systems_2_b_t {
   uint16_t esud1_ud_selected_number : 2; //!< Номер канала УД ЭСУД-1, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud2_ud_selected_number : 2; //!< Номер канала УД ЭСУД-2, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud3_ud_selected_number : 2; //!< Номер канала УД ЭСУД-3, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud4_ud_selected_number : 2; //!< Номер канала УД ЭСУД-4, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud1_sku_selected_number: 2; //!< Номер канала СКУ ЭСУД-1, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud2_sku_selected_number: 2; //!< Номер канала СКУ ЭСУД-2, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud3_sku_selected_number: 2; //!< Номер канала СКУ ЭСУД-3, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t esud4_sku_selected_number: 2; //!< Номер канала СКУ ЭСУД-4, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
} mfci_in_blocks_selected_systems_2_b_t;

//! Выбранные для взаимодействия системы (слово 3, для кадра БЛОКИ)
typedef struct mfci_in_blocks_selected_systems_3_b_t {
   uint16_t absu_selected_number : 3; //!< Номер канала АБСУ, выбранного для взаимодействия (0-н/д) //(min:0 max:4)
   uint16_t bask_selected_number : 2; //!< Номер канала БАСК, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t kskv_selected_number : 2; //!< Номер канала КСКВ, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t bupt_selected_number : 2; //!< Номер канала БУПТ, выбранного для взаимодействия (0-н/д) //(min:0 max:2)
   uint16_t build_block_id       : 3; //!< Блок, для которого предается номер сборки (1…2-БИС, 3…4-БЦВМ, 5…6-БГС) //(min:1 max:6 bits:4..19 lsb:1)
   uint16_t build_kfm_id         : 4; //!< КФМ, для которого предается номер сборки //(min:1 max:10 bits:4..19 lsb:1)
} mfci_in_blocks_selected_systems_3_b_t;

//! Слово состояния ПУИ, МУП, 1П2М, 1П8М (для кадра БЛОКИ)
typedef struct mfci_in_blocks_boards_status_word_b_t {
   uint16_t pui1_integral       : 2; //!< ПУИ-1 Интегральное состояние //(min:0 max:3)
   uint16_t pui2_integral       : 2; //!< ПУИ-2 Интегральное состояние //(min:0 max:3)
   uint16_t mup1_integral       : 2; //!< МУП-1 Интегральное состояние //(min:0 max:3)
   uint16_t mup2_integral       : 2; //!< МУП-2 Интегральное состояние //(min:0 max:3)
   uint16_t board1p8m1_integral : 2; //!< 1П8М-1 Интегральное состояние //(min:0 max:3)
   uint16_t board1p8m2_integral : 2; //!< 1П8М-2 Интегральное состояние //(min:0 max:3)
   uint16_t board1p2m1_integral : 2; //!< 1П2М-1 Интегральное состояние //(min:0 max:3)
   uint16_t board1p2m2_integral : 2; //!< 1П2М-2 Интегральное состояние //(min:0 max:3)
} mfci_in_blocks_boards_status_word_b_t;

//! Слово 1 состояния КВИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_kvi_status_word_1_b_t {
   uint16_t integral : 2; //!< Интегральное состояние //(min:0 max:3)
   uint16_t unit01   : 2; //!< Состояние модуля № 1 (МС102) //(min:0 max:3)
   uint16_t unit02   : 2; //!< Состояние модуля № 2 (МН100) //(min:0 max:3)
   uint16_t unit03   : 2; //!< Состояние модуля № 3 (МВ100-02-03/МВ105-02 ММП1) //(min:0 max:3)
   uint16_t unit04   : 2; //!< Состояние модуля № 4 (МВ100-01/МВ105-01) //(min:0 max:3)
   uint16_t unit05   : 2; //!< Состояние модуля № 5 (МВ101-01/МВ106-01) //(min:0 max:3)
   uint16_t unit06   : 2; //!< Состояние модуля № 6 (МВ101-01/МВ106-01) //(min:0 max:3)
   uint16_t unit07   : 2; //!< Состояние модуля № 7 (МВ101-01/МВ106-01) //(min:0 max:3)
} mfci_in_blocks_kvi_status_word_1_b_t;

//! Слово 2 состояния КВИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_kvi_status_word_2_b_t {
   uint16_t unit08       : 2; //!< Состояние модуля № 8 (МВ101-01/МВ106-01) //(min:0 max:3)
   uint16_t unit09       : 2; //!< Состояние модуля № 9 (МВ101-01/МВ106-01) //(min:0 max:3)
   uint16_t unit10       : 2; //!< Состояние модуля № 10 (МВ101-01/МВ106-01) //(min:0 max:3)
   uint16_t unit11       : 2; //!< Состояние модуля № 11 (МВ100-01/МВ105-01) //(min:0 max:3)
   uint16_t unit12       : 2; //!< Состояние модуля № 12 (МВ100-02-03/МВ105-02 ММП2) //(min:0 max:3)
   uint16_t unit13       : 2; //!< Состояние модуля № 13 (МН100) //(min:0 max:3)
   uint16_t unit14       : 2; //!< Состояние модуля № 14 (МС102) //(min:0 max:3)
   uint16_t crc_mismatch : 1; //!< Отличие интегральных контрольных сумм КВИ-1 и КВИ-2
   uint16_t              : 1; //!< Резерв
} mfci_in_blocks_kvi_status_word_2_b_t;

//! Слово 3 состояния КВИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_kvi_status_word_3_b_t {
   uint16_t mmp1_kvi_spacewire   : 2; //!< Состояние связи c другим КВИ SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bis1_spacewire  : 2; //!< Состояние связи с БИС-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bis2_spacewire  : 2; //!< Состояние связи с БИС-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bcvm1_spacewire : 2; //!< Состояние связи с БЦВМ-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bcvm2_spacewire : 2; //!< Состояние связи с БЦВМ-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bvd1_spacewire  : 2; //!< Состояние связи с БВД-1 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t mmp1_bvd2_spacewire  : 2; //!< Состояние связи с БВД-2 SpaceWire (на ММП1) //(min:0 max:3)
   uint16_t                      : 2; //!< Резерв
} mfci_in_blocks_kvi_status_word_3_b_t;

//! Слово 4 состояния КВИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_kvi_status_word_4_b_t {
   uint16_t mmp2_kvi_spacewire   : 2; //!< Состояние связи c другим КВИ SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bis1_spacewire  : 2; //!< Состояние связи с БИС-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bis2_spacewire  : 2; //!< Состояние связи с БИС-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bcvm1_spacewire : 2; //!< Состояние связи с БЦВМ-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bcvm2_spacewire : 2; //!< Состояние связи с БЦВМ-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bvd1_spacewire  : 2; //!< Состояние связи с БВД-1 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t mmp2_bvd2_spacewire  : 2; //!< Состояние связи с БВД-2 SpaceWire (на ММП2) //(min:0 max:3)
   uint16_t                      : 2; //!< Резерв
} mfci_in_blocks_kvi_status_word_4_b_t;

//! Слово 5 состояния КВИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_kvi_status_word_5_b_t {
   uint16_t bvd1_mkio4_1_bus1 : 1; //!< Исправность связи с ОУ БВД-1 МКИО-4.1A
   uint16_t bvd1_mkio4_1_bus2 : 1; //!< Исправность связи с ОУ БВД-1 МКИО-4.1B
   uint16_t bvd2_mkio4_2_bus1 : 1; //!< Исправность связи с ОУ БВД-2 МКИО-4.2A
   uint16_t bvd2_mkio4_2_bus2 : 1; //!< Исправность связи с ОУ БВД-2 МКИО-4.2B
   uint16_t board1p2m1_a429   : 1; //!< Исправность связи с 1П2М-1 Arinc-429
   uint16_t board1p2m2_a429   : 1; //!< Исправность связи с 1П2М-2 Arinc-429
   uint16_t board1p8m1_a429   : 1; //!< Исправность связи с 1П8М-1 Arinc-429
   uint16_t board1p8m2_a429   : 1; //!< Исправность связи с 1П8М-2 Arinc-429
   uint16_t                   : 8; //!< Резерв
} mfci_in_blocks_kvi_status_word_5_b_t;

//! Слово 6 состояния КВИ (для кадра БЛОКИ)
typedef struct mfci_in_blocks_kvi_status_word_6_b_t {
   uint16_t bi1m_1_a429  : 1; //!< Исправность связи с БИ-1М № 1 Arinc-429
   uint16_t bi1m_2_a429  : 1; //!< Исправность связи с БИ-1М № 2 Arinc-429
   uint16_t bi1m_3_a429  : 1; //!< Исправность связи с БИ-1М № 3 Arinc-429
   uint16_t bi1m_4_a429  : 1; //!< Исправность связи с БИ-1М № 4 Arinc-429
   uint16_t bi1m_5_a429  : 1; //!< Исправность связи с БИ-1М № 5 Arinc-429
   uint16_t bi1m_6_a429  : 1; //!< Исправность связи с БИ-1М № 6 Arinc-429
   uint16_t bi1m_7_a429  : 1; //!< Исправность связи с БИ-1М № 7 Arinc-429
   uint16_t bi1m_8_a429  : 1; //!< Исправность связи с БИ-1М № 8 Arinc-429
   uint16_t bi1m_9_a429  : 1; //!< Исправность связи с БИ-1М № 9 Arinc-429
   uint16_t bi1m_10_a429 : 1; //!< Исправность связи с БИ-1М № 10 Arinc-429
   uint16_t bi1m_11_a429 : 1; //!< Исправность связи с БИ-1М № 11 Arinc-429
   uint16_t bi1m_12_a429 : 1; //!< Исправность связи с БИ-1М № 12 Arinc-429
   uint16_t bi4m_1_a429  : 1; //!< Исправность связи с БИ-4М № 1 Arinc-429
   uint16_t bi4m_2_a429  : 1; //!< Исправность связи с БИ-4М № 2 Arinc-429
   uint16_t bi4m_3_a429  : 1; //!< Исправность связи с БИ-4М № 3 Arinc-429
   uint16_t bi4m_4_a429  : 1; //!< Исправность связи с БИ-4М № 4 Arinc-429
} mfci_in_blocks_kvi_status_word_6_b_t;

//! Признаки наличия данных СЗИ (для фрагмента 1)
typedef struct mfci_in_blocks_szi_1_valid_word_b_t {
   uint16_t bis1 : 1;  //!< Признак наличия данных СЗИ БИС 1
   uint16_t bis2 : 1;  //!< Признак наличия данных СЗИ БИС 2
   uint16_t bgs1 : 1;  //!< Признак наличия данных СЗИ БГС 1
   uint16_t bgs2 : 1;  //!< Признак наличия данных СЗИ БГС 2
   uint16_t kvi1 : 1;  //!< Признак наличия данных СЗИ КВИ 1
   uint16_t kvi2 : 1;  //!< Признак наличия данных СЗИ КВИ 2
   uint16_t      : 10; //!< Резерв
} mfci_in_blocks_szi_1_valid_word_b_t;

//! Признаки наличия данных СЗИ (для фрагмента 2)
typedef struct mfci_in_blocks_szi_2_valid_word_b_t {
   uint16_t bcvm1 : 1;  //!< Признак наличия данных СЗИ БЦВМ 1
   uint16_t bcvm2 : 1;  //!< Признак наличия данных СЗИ БЦВМ 2
   uint16_t bvd1  : 1;  //!< Признак наличия данных СЗИ БВД 1
   uint16_t bvd2  : 1;  //!< Признак наличия данных СЗИ БВД 2
   uint16_t       : 12; //!< Резерв
} mfci_in_blocks_szi_2_valid_word_b_t;

//! События СЗИ модуля
typedef struct mfci_in_blocks_szi_messages_b_t {
   uint16_t unit_1 : 8; //!< Событие СЗИ первого модуля //(min:0 max:255)
   uint16_t unit_2 : 8; //!< Событие СЗИ второго модуля //(min:0 max:255)
} mfci_in_blocks_szi_messages_b_t;

//! Слово состояния тарировки УКС
typedef struct mfci_in_tar_status_word_b_t {
   uint16_t uks_number       : 3; //!< Номер выбранного УКС (квитанция на upr_flag_word_tar_1_b_t::uks_number) //(min:1 max:4)
   uint16_t parameter_number : 4; //!< Номер тарируемого параметра (квитанция на upr_flag_word_tar_1_b_t::parameter_number) //(min:1 max:10)
   uint16_t load_status      : 2; //!< Состояние чтения таблицы тарировки выбранного УКС (0-чтение не активно, 1-чтение активно, 2-ошибка чтения, 3-завершение чтения) //(min:0 max:3)
   uint16_t save_status      : 2; //!< Состояние записи таблицы тарировки выбранного УКС (0-запись не активна, 1-запись активна, 2-ошибка записи, 3-завершение записи) //(min:0 max:3)
   uint16_t uks1_crc_valid   : 1; //!< Наличие контрольной суммы таблицы тарировок УКС-1
   uint16_t uks2_crc_valid   : 1; //!< Наличие контрольной суммы таблицы тарировок УКС-2
   uint16_t uks3_crc_valid   : 1; //!< Наличие контрольной суммы таблицы тарировок УКС-3
   uint16_t uks4_crc_valid   : 1; //!< Наличие контрольной суммы таблицы тарировок УКС-4
   uint16_t                  : 1; //!< Резерв
} mfci_in_tar_status_word_b_t;

//! Слово состояния кодов АЦП тарируемого параметра УКС
typedef struct mfci_in_tar_status_word_adc_b_t {
   uint16_t current_code_valid : 1; //!< Достоверность текущего кода АЦП тарируемого параметра
   uint16_t code_1_status      : 2; //!< Состояние кода АЦП узловой точки 1 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t code_2_status      : 2; //!< Состояние кода АЦП узловой точки 2 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t code_3_status      : 2; //!< Состояние кода АЦП узловой точки 3 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t code_4_status      : 2; //!< Состояние кода АЦП узловой точки 4 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t code_5_status      : 2; //!< Состояние кода АЦП узловой точки 5 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t code_6_status      : 2; //!< Состояние кода АЦП узловой точки 6 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t code_7_status      : 2; //!< Состояние кода АЦП узловой точки 7 тарируемого параметра (0-нет данных, 1-загружен из ПЗУ УКС, 2-перезаписан оператором) //(min:0 max:2)
   uint16_t                    : 1; //!< Резерв
} mfci_in_tar_status_word_adc_b_t;

//! Тип точки плана полета
typedef enum plan_point_type_t {
   PLAN_POINT_HIDE,            //!< Тип не определен (не отображается)
   PLAN_POINT_AERODROME,       //!< КТА
   PLAN_POINT_RUNWAY_END,      //!< Торец ВПП
   PLAN_POINT_RUNWAY_END_VIS,  //!< Торец ВПП без системы захода на посадку
   PLAN_POINT_RSBN,            //!< Радиомаяк РСБН
   PLAN_POINT_VOR,             //!< Радиомаяк VOR
   PLAN_POINT_DME,             //!< Радиомаяк DME
   PLAN_POINT_VOR_DME,         //!< Радиомаяк VOR+DME
   PLAN_POINT_NDB,             //!< Приводная станция
   PLAN_POINT_DPRS,            //!< Дальняя приводная станция с маркерным радиомаяком
   PLAN_POINT_SPRS,            //!< Средняя приводная станция с маркерным радиомаяком
   PLAN_POINT_BPRS,            //!< Ближняя приводная станция с маркерным радиомаяком
   PLAN_POINT_REFERENCE,       //!< Ориентир
   PLAN_POINT_HIGH_MANMADE,    //!< Точка искуственного препятствия
   PLAN_POINT_HIGH_NATURAL,    //!< Точка естественного препятствия
   PLAN_POINT_RPU,             //!< Рубеж передачи управления
   PLAN_POINT_RPC,             //!< Пункт обязательного донесения
   PLAN_POINT_RPR,             //!< Пункт донесения по запросу
   PLAN_POINT_RNAVC,           //!< Пункт RNAV с обязательным донесением
   PLAN_POINT_RNAVR,           //!< Пункт RNAV с донесением по запросу
   PLAN_POINT_MILEAGE,         //!< Точка разрыва в измерении расстояния
   PLAN_POINT_NAV_POINT,       //!< Пункт маршрута (точка без определенного типа, отображается как ППМ или цель)
   PLAN_POINT_DANDER_ZONE,     //!< Опасная зона (круглая)
   PLAN_POINT_RESTRICTED_ZONE, //!< Запретная зона (круглая)
   PLAN_POINT_DANDER_PG,       //!< Точка многоугольной запретной зоны
   PLAN_POINT_RESTRICTED_PG,   //!< Точка многоугольной опасной зоны
   PLAN_POINT_MP_ALT_UP,       //!< Рубеж начала набора высоты
   PLAN_POINT_MP_ALT_DOWN,     //!< Рубеж начала снижения
   PLAN_POINT_MP_SPEED_UP,     //!< Рубеж начала разгона
   PLAN_POINT_MP_SPEED_DOWN,   //!< Рубеж начала торможения
   PLAN_POINT_TYPES_COUNT      //!< Количество типов точек плана полета
} plan_point_type_t;

//! Тип участка траектории
typedef enum plan_leg_type_t {
   PLAN_LEG_HIDE,            //!< Разрыв траектории (участок не отображается)
   PLAN_LEG_STANDART,        //!< Основная активная траектория (маршрут, трасса, траектория маневра, SID/STAR/APPROACH)
   PLAN_LEG_STANDART_PASSED, //!< Основная пройденная траектория (маршрут, трасса, траектория маневра, SID/STAR/APPROACH)
   PLAN_LEG_ALTERNATIVE,     //!< Альтернативная траектория (смещение маршрута, маневр выхода в Тзад)
   PLAN_LEG_OPERATIVE,       //!< Траектория оперативного маршрута (новый маршрут, участки измененного маршрута)
   PLAN_LEG_TRANSITION,      //!< Траектория перехода
   PLAN_LEG_MIS_APPROACH,    //!< Траектория ухода на второй круг
   PLAN_LEG_VECTORS,         //!< Траектория радарного векторения
   PLAN_LEG_VISUAL,          //!< Траектория визуального захода
   PLAN_LEG_SEL_ANGLE,       //!< Траектория полета по заданному курсу (заданному путевому углу)
   PLAN_LEG_TYPES_COUNT      //!< Количество типов участков траекторий плана полета
} plan_leg_type_t;

//! Слово-идентификатор 1 точки участка траекторий
typedef struct mfci_leg_id_1_b_t {
   uint16_t legs_count : 8; //!< Количество точек участков траекторий //(min:2 max:255)
   uint16_t leg_number : 8; //!< Номер точки участка траекторий //(min:1 max:255)
} mfci_leg_id_1_b_t;

//! Слово-идентификатор 2 точки участка траекторий
typedef struct mfci_leg_id_2_b_t {
   uint16_t type                   : 4; //!< Тип следующего участка (plan_leg_type_t) //(min:0 max:9)
   uint16_t clockwise              : 1; //!< Направление разворота следующего участка (0-против часовой, 1-по часовой)
   uint16_t azimuth                : 9; //!< Азимут следующего участка траекторий //(min:0 max:359 lsb:1°)
   uint16_t azimuth_distance_valid : 1; //!< Наличие данных об азимуте и длине следующего участка траекторий
   uint16_t                        : 1;  //!< Резерв
} mfci_leg_id_2_b_t;

//! Слово-идентификатор 1 точки плана полета
typedef struct mfci_point_id_1_b_t {
   uint16_t points_count : 8; //!< Количество точек плана полета //(min:0 max:255)
   uint16_t point_number : 8; //!< Номер точки плана полета //(min:1 max:255)
} mfci_point_id_1_b_t;

//! Слово-идентификатор 2 точки плана полета
typedef struct mfci_point_id_2_b_t {
   uint16_t type                  : 5; //!< Тип точки (plan_point_type_t) //(min:0 max:29)
   uint16_t selected_point_number : 8; //!< Номер исполняемой точки (0 - нет исполняемой точки) //(min:1 max:255)
   uint16_t waypoint              : 1; //!< Признак ПМ маршрута (точка является ППМ/ИПМ/КПМ активного или оперативного маршрута)
   uint16_t target                : 1; //!< Признак цели (точка является целью)
   uint16_t operative             : 1; //!< Принадлежность оперативному маршруту
} mfci_point_id_2_b_t;

//! Слово-идентификатор 3 точки плана полета
typedef struct mfci_point_id_3_b_t {
   uint16_t time_hour       : 5; //!< Час //(min:0 max:23)
   uint16_t time_minute     : 6; //!< Минута //(min:0 max:59)
   uint16_t time_valid      : 1; //!< Наличие заданного времени для ПМ
   uint16_t beacon_selected : 1; //!< Признак взаимодействующего радиомаяка
   uint16_t passed          : 1; //!< Признак пройденного ПМ маршрута (точка является пройденным ППМ/ИПМ/КПМ активного маршрута)
   uint16_t bpm1            : 1; //!< Признак БПМ-1 боевого участка маршрута
   uint16_t ipom            : 1; //!< Признак ИПОМ боевого участка маршрута
} mfci_point_id_3_b_t;

//! Слово-идентификатор 4 точки плана полета
typedef struct mfci_point_id_4_b_t {
   uint16_t bp_number : 8; //!< Номер в массиве ППМ, передаваемых в ФПО БП (0 - точки нет в массиве) //(min:0 max:150)
   uint16_t speed_low : 8; //!< Заданная истинная скорость точки маршрута или траекторий или рубежа разгона/торможения (0 - не задана, младшие разряды) //(min:0 max:3500 bits:4..19 lsb:1 км/ч)
} mfci_point_id_4_b_t;

//! Слово-идентификатор 5 точки плана полета
typedef struct mfci_point_id_5_b_t {
   uint16_t speed_high : 4;  //!< Заданная истинная скорость точки маршрута или траекторий или рубежа разгона/торможения (0 - не задана, старшие разряды) //(min:0 max:3500 bits:4..19 lsb:1 км/ч)
   uint16_t fuel       : 11; //!< Заданный остаток топлива точки маршрута или траекторий (0 - не задан) //(min:0 max:175 bits:4..19 lsb:0.1 т)
   uint16_t            : 1;  //!< Резерв
} mfci_point_id_5_b_t;

//! Слово-идентификатор 1 точки плана полета
typedef struct mfci_single_point_id_1_b_t {
   uint16_t single_point_number : 11; //!< Номер точки плана полета //(min:1 max:2047)
   uint16_t type                : 5;  //!< Тип точки (plan_point_type_t) //(min:0 max:29)
} mfci_single_point_id_1_b_t;

//! Слово-идентификатор 2 точки плана полета
typedef struct mfci_single_point_id_2_b_t {
   uint16_t single_points_count : 11; //!< Количество точек плана полета //(min:0 max:2047)
   uint16_t beacon_selected     : 1;  //!< Признак взаимодействующего радиомаяка
   uint16_t last_point          : 1;  //!< Признак последней точки многоугольной зоны
   uint16_t                     : 3;  //!< Резерв
} mfci_single_point_id_2_b_t;

//! Слово-идентификатор 1 участков траектории выхода на активный участок маршрута или маневра
typedef struct mfci_active_path_legs_id_1_b_t {
   uint16_t legs_count      : 4; //!< Количество участков траектории, включая завершающую точку (0-трактория отсутствует) //(min:0 max:15)
   uint16_t segment_number  : 2; //!< Номер сегмента участков траектории (0-трактория отсутствует) //(min:0 max:3)
   uint16_t leg_1_clockwise : 1; //!< Направление разворота на участке 1 (0-против часовой, 1-по часовой)
   uint16_t leg_2_clockwise : 1; //!< Направление разворота на участке 2 (0-против часовой, 1-по часовой)
   uint16_t leg_3_clockwise : 1; //!< Направление разворота на участке 3 (0-против часовой, 1-по часовой)
   uint16_t leg_4_clockwise : 1; //!< Направление разворота на участке 4 (0-против часовой, 1-по часовой)
   uint16_t leg_5_clockwise : 1; //!< Направление разворота на участке 5 (0-против часовой, 1-по часовой)
   uint16_t type_1          : 4; //!< Тип следующего участка (plan_leg_type_t) //(min:0 max:9)
   uint16_t                 : 1; //!< Резерв
} mfci_active_path_legs_id_1_b_t;

//! Слово-идентификатор 2 участков траектории выхода на активный участок маршрута или маневра
typedef struct mfci_active_path_legs_id_2_b_t {
   uint16_t type_2 : 4; //!< Тип следующего участка (plan_leg_type_t) //(min:0 max:9)
   uint16_t type_3 : 4; //!< Тип следующего участка (plan_leg_type_t) //(min:0 max:9)
   uint16_t type_4 : 4; //!< Тип следующего участка (plan_leg_type_t) //(min:0 max:9)
   uint16_t type_5 : 4; //!< Тип следующего участка (plan_leg_type_t) //(min:0 max:9)
} mfci_active_path_legs_id_2_b_t;

//! Элемент массива сечений вихревого следа
typedef struct fovb_section_b_t {
   uint32_t abscissa : 12; //!< Координата центра сечения на перпендикулярной оси самолета (0…4095 - -100…100 км) //(min:-100 max:100)
   uint32_t ordinate : 12; //!< Координата центра сечения на продольной оси самолета (0…4095 - -100…100 км) //(min:-100 max:100)
   uint32_t size     : 5;  //!< Радиус сечения (0…31 - 0…1 км, 0 - признак отсутствия сечения) //(min:0 max:1)
   uint32_t          : 3;  //!< Резерв
} fovb_section_b_t;

//! Параметры массива сечений вихревого следа
typedef struct fovb_sections_id_b_t {
   uint16_t zone_id          : 8; //!< Идентификатор вихревого следа //(min:0 max:255)
   uint16_t section_start_id : 4; //!< Младшие 4 бита номера первого элемента массива передаваемых сечений вихревого следа //(min:0 max:14)
   uint16_t sections_count   : 3; //!< Количество сечений в массиве передаваемых сечений вихревого следа //(min:0 max:6)
   uint16_t                  : 1; //!< Резерв
} fovb_sections_id_b_t;

//! Параметры вихревого следа (слово 1)
typedef struct fovb_trail_id_1_b_t {
   uint32_t tail_section_abscissa : 12; //!< Координата центра хвостового сечения на перпендикулярной оси самолета (0…4095 - -100…100 км) //(min:-100 max:100)
   uint32_t tail_section_ordinate : 12; //!< Координата центра хвостового сечения на продольной оси самолета (0…4095 - -100…100 км) //(min:-100 max:100)
   uint32_t zone_id               : 8;  //!< Идентификатор вихревого следа //(min:0 max:255)
} fovb_trail_id_1_b_t;

//! Параметры вихревого следа (слово 2)
typedef struct fovb_trail_id_2_b_t {
   uint16_t tail_section_id   : 4; //!< Младшие 4 бита номера хвостового сечения вихревого следа //(min:0 max:14)
   uint16_t color             : 2; //!< Категория вихревого следа (0-не отображать, 1-белый, 2-желтый, 3-красный) //(min:0 max:3)
   uint16_t tail_section_size : 5; //!< Размер хвостового сечения (0…31 - 0…1 км, 0 - признак отсутствия сечения) //(min:0 max:1)
   uint16_t                   : 5; //!< Резерв
} fovb_trail_id_2_b_t;

//! Слово рекомендуемых вертикальных скоростей ФОВБ
typedef struct fovb_rates_b_t {
   uint16_t rate_min : 8; //!< [ФОВБ-А003] Рекомендуемая вертикальная скорость минимальная (0…255 - -83…83 м/с) //(min:-83 max:83)
   uint16_t rate_max : 8; //!< [ФОВБ-А004] Рекомендуемая вертикальная скорость максимальная (0…255 - -83…83 м/с) //(min:-83 max:83)
} fovb_rates_b_t;

//! Данные о сборке ПО модуля/системы (версия и контрольная сумма ПО модуля/системы)
typedef struct mfci_in_blocks_crc_unit_b_t {
   uint8_t  dopstr[24];  //!< Дополнительная строка
   uint16_t verdata[2];  //!< Подверсия и версия (редакция) //(min:1 max:99 lsb:1)
   uint8_t  datestr[12]; //!< Дата в формате DD.MM.YYYY
   uint32_t crc;         //!< Контрольная сумма //(min:0 max:4294967295 lsb:1)
} mfci_in_blocks_crc_unit_b_t;

//! Слово 1 идентификации данных о сборке ПО модуля/системы
typedef struct mfci_in_blocks_crc_mkio_id_1_b_t {
   uint16_t mode   : 6; //!< Режим работы кадра БЛОКИ (mfci_blocks_mode_t, квитанция)
   uint16_t system : 6; //!< Выбранная система (mfci_blocks_system_t, квитанция)
   uint16_t        : 4; //!< Резерв
} mfci_in_blocks_crc_mkio_id_1_b_t;

//! Слово 2 идентификации данных о сборке ПО модуля/системы
typedef struct mfci_in_blocks_crc_mkio_id_2_b_t {
   uint16_t mfci1  : 1; //!< Данные предназначены для МФЦИ 1
   uint16_t mfci2  : 1; //!< Данные предназначены для МФЦИ 2
   uint16_t mfci3  : 1; //!< Данные предназначены для МФЦИ 3
   uint16_t mfci4  : 1; //!< Данные предназначены для МФЦИ 4
   uint16_t mfci5  : 1; //!< Данные предназначены для МФЦИ 5
   uint16_t mfci6  : 1; //!< Данные предназначены для МФЦИ 6
   uint16_t mfci7  : 1; //!< Данные предназначены для МФЦИ 7
   uint16_t mfci8  : 1; //!< Данные предназначены для МФЦИ 8
   uint16_t mfci9  : 1; //!< Данные предназначены для МФЦИ 9
   uint16_t mfci10 : 1; //!< Данные предназначены для МФЦИ 10
   uint16_t mfci11 : 1; //!< Данные предназначены для МФЦИ 11
   uint16_t        : 5; //!< Резерв
} mfci_in_blocks_crc_mkio_id_2_b_t;

//! Слово 1 состояния МФЦИ
typedef struct mfci_status_word_1_b_t {
   uint16_t number      : 4; //!< Номер МФЦИ //(min:0 max:11)
   uint16_t             : 4; //!< Резерв
   uint16_t vpr_mvs     : 2; //!< Квитанция 1 активного режима индикации для МСРП (1-ВПР/Ноп, 2-МВС) //(min:0 max:2)
   uint16_t qfe_std_qnh : 2; //!< Квитанция 2 активного режима индикации для МСРП (1-QFE, 2-СТД, 3-QNH) //(min:0 max:3)
   uint16_t             : 4; //!< Резерв
} mfci_status_word_1_b_t;

//! Слово 2 состояния МФЦИ
typedef struct mfci_status_word_2_b_t {
   uint16_t format_1 : 6; //!< Кадр 1 (mfci_format_t) //(min:0 max:31)
   uint16_t format_2 : 6; //!< Кадр 2 (mfci_format_t) //(min:0 max:31)
   uint16_t mv       : 1; //!< Исправность МВ (МС24)
   uint16_t mg24     : 1; //!< Исправность МГ24 (МС25)
   uint16_t mg428    : 1; //!< Исправность МГ428 (МС428)
   uint16_t mn       : 1; //!< Исправность МН100
} mfci_status_word_2_b_t;

//! Слово 3 состояния МФЦИ
typedef struct mfci_status_word_3_b_t {
   uint16_t buttons        : 1; //!< Исправность кнопок
   uint16_t brightness     : 1; //!< Исправность регулировки яркости
   uint16_t contrast       : 1; //!< Исправность регулировки контрастности
   uint16_t mode_reserve   : 1; //!< Резервный режим работы (прием данных по МКИО)
   uint16_t mode_emergency : 1; //!< Аварийный режим работы (прием данных по Arinc-429)
   uint16_t bis_mkio31     : 1; //!< Исправность связи с БИС по МКИО-3.1
   uint16_t bcvm_mkio32    : 1; //!< Исправность связи с БЦВМ по МКИО-3.2
   uint16_t bgs1_arinc818  : 1; //!< Исправность связи с БГС-1 Arinc-818
   uint16_t bgs2_arinc818  : 1; //!< Исправность связи с БГС-2 Arinc-818
   uint16_t bins_arinc429  : 1; //!< Исправность связи с БИНС Arinc-429
   uint16_t svs_arinc429   : 1; //!< Исправность связи с СВС Arinc-429
   uint16_t ark_arinc429   : 1; //!< Исправность связи с АРК Arinc-429
   uint16_t rsbn_arinc429  : 1; //!< Исправность связи с РСБН Arinc-429
   uint16_t vim_arinc429   : 1; //!< Исправность связи с VIM Arinc-429
   uint16_t rvm_arinc429   : 1; //!< Исправность связи с РВМ Arinc-429
   uint16_t pnap_arinc429  : 1; //!< Исправность связи с ПНАП-ПЛА Arinc-429
} mfci_status_word_3_b_t;

//! Слово 1 сигналов УПР (общее для всех кадров МФЦИ)
typedef struct upr_flag_word_common_1_b_t {
   uint16_t valid_data     : 1; //!< Достоверность слов сигналов УПР
   uint16_t menu           : 1; //!< Активен режим индикации меню (МЕНЮ)
   uint16_t obrm           : 1; //!< Активен режим индикации кнопочного обрамления кадра (ОБРМ)
   uint16_t dvs_next_page  : 1; //!< Сигнал листания страниц сигнализации ДВ/С
   uint16_t sost_next_page : 1; //!< Сигнал листания страниц сигнализации СОСТ
   uint16_t sign_next_page : 1; //!< Сигнал листания страниц сигнализации СИГН
   uint16_t vor1           : 1; //!< [УПР-Д001] Активен режим индикации VOR1
   uint16_t vor2           : 1; //!< [УПР-Д002] Активен режим индикации VOR2
   uint16_t ark            : 1; //!< [УПР-Д003] Активен режим индикации AРК
   uint16_t use_ans        : 1; //!< [УПР-Д004] Активен режим использования курса, крена и тангажа АНС
   uint16_t change_ins     : 1; //!< [УПР-Д005] Активен режим использования параметров резервной ИНС
   uint16_t rsbn           : 1; //!< [УПР-Д006] Активен режим индикации РСБН
   uint16_t landing        : 1; //!< [УПР-Д007] Активен режим индикации ПОСАДКА
   uint16_t change_svs     : 1; //!< [УПР-Д008] Активен режим использования параметров резервной СВС
   uint16_t brit           : 1; //!< [УПР-Д009] Активен режим индикации БРИТ
   uint16_t frts           : 1; //!< [УПР-Д010] Активен режим индикации "FРТС" (частота настройки РТС)
} upr_flag_word_common_1_b_t;

//! Слово 2 сигналов УПР (общее для всех кадров МФЦИ)
typedef struct upr_flag_word_common_2_b_t {
   uint16_t hpa              : 1; //!< [УПР-Д021] Активен режим индикации единиц измерения "гПа"
   uint16_t mach             : 1; //!< [УПР-Д023] Активен режим индикации числа М
   uint16_t msgt             : 1; //!< [УПР-Д024] Активен режим индикации "МсGт" (массы самолета и веса топлива)
   uint16_t sev              : 1; //!< [УПР-Д031] Активен режим индикации СЕВ (ориентация на север)
   uint16_t rpu              : 1; //!< [УПР-Д032] Активен режим индикации РПУ (рубеж передачи управления)
   uint16_t rts              : 1; //!< [УПР-Д033] Активен режим индикации РТС (индикация невыбанных РТС)
   uint16_t tpm              : 1; //!< [УПР-Д034] Активен режим индикации Tпм (расстояние между ППМ и время пролета ППМ)
   uint16_t topl             : 1; //!< [УПР-Д035] Активен режим индикации ТОПЛ (остаток топлива в ППМ)
   uint16_t hv               : 1; //!< [УПР-Д036] Активен режим индикации H/V (значение скорости и высоты пролета ППМ)
   uint16_t vt               : 1; //!< [УПР-Д037] Активен режим индикации ВТ (воздушные трассы)
   uint16_t aer              : 1; //!< [УПР-Д038] Активен режим индикации АЭР (запасные аэродромы)
   uint16_t redundant_values : 1; //!< [УПР-Д061] Активен режим индикации "Tзад" (параметры выхода в заданную точку в заданное время)
   uint16_t zones            : 1; //!< [УПР-Д065] Активен режим индикации ЗОНЫ (опасные и запретные зоны)
   uint16_t landing_sys      : 3; //!< [УПР] Посадочная система, выбранная для индикации //(min:0 max:5)
} upr_flag_word_common_2_b_t;

//! Слово 3 сигналов УПР (общее для всех кадров МФЦИ)
typedef struct upr_flag_word_common_3_b_t {
   uint16_t pui_cursor_position : 6; //!< Положение курсора ПУИ //(min:0 max:40)
   uint16_t sign_hint_change    : 1; //!< Сигнал включения/выключения отображения подсказок сигнализации
   uint16_t sost_reset          : 1; //!< Признак отбоя сигналов СОСТ
   uint16_t sign_show           : 1; //!< Признак отображения поля СИГН
   uint16_t markpoints          : 1; //!< [УПР] Активен режим индикации РУБЖ (рубежи изменения режима и профиля полета)
   uint16_t contrail            : 1; //!< [УПР-Д040] Активен режим индикации информации по вихревому следу
   uint16_t tn                  : 1; //!< [УПР-Д060] Активен режим индикации температуры наружного воздуха и отклонения от ТМСА
   uint16_t takeoff_landing_run : 1; //!< [УПР-Д062…УПР-Д063] Активен режим индикации "Lпотр" (потребные длины пробега)
   uint16_t set_zero_alt        : 1; //!< [УПР-Д011] Команда выставки нулевой баровысоты
   uint16_t set_unreserved_pui  : 1; //!< [УПР] Команда включения или выключения подтверждения ввода с ПУИ
   uint16_t format_2_flag       : 1; //!< Признак активности правого кадра широкоформатного МФЦИ
} upr_flag_word_common_3_b_t;

//! Слово 4 сигналов УПР (общее для всех кадров МФЦИ)
typedef struct upr_flag_word_common_4_b_t {
   uint16_t grey_background : 1; //!< Использование серого фона вместо черного (ФОН)
   uint16_t bgs_channel     : 1; //!< Номер БГС, канал которого подключен (0 - БГС-1, 1 - БГС-2) //(min:0 max:1)
   uint16_t brightness      : 6; //!< Значение яркости экрана МФЦИ //(min:0 max:63)
   uint16_t show_brightness : 1; //!< Признак отображения шкалы яркости
   uint16_t contrast        : 5; //!< Значение контрастности экрана МФЦИ //(min:0 max:31)
   uint16_t show_contrast   : 1; //!< Признак отображения шкалы контрастности
   uint16_t int_test        : 1; //!< Режим теста интерфейсов
} upr_flag_word_common_4_b_t;

//! Слово с признаками отбоя сигналов СОСТ
typedef struct mfci_sost_reset_b_t {
   uint16_t mfci1_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 1
   uint16_t mfci2_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 2
   uint16_t mfci3_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 3
   uint16_t mfci4_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 4
   uint16_t mfci5_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 5
   uint16_t mfci6_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 6
   uint16_t mfci7_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 7
   uint16_t mfci8_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 8
   uint16_t mfci9_sost_reset  : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 9
   uint16_t mfci10_sost_reset : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 10
   uint16_t mfci11_sost_reset : 1; //!< Признак отбоя сигналов СОСТ на МФЦИ 11
   uint16_t                   : 5; //!< Резерв
} mfci_sost_reset_b_t;

//! Слово с признаками отображения поля СИГН
typedef struct mfci_sign_show_b_t {
   uint16_t mfci6_sign_show  : 1;  //!< Признак отображения поля СИГН на МФЦИ 6
   uint16_t mfci7_sign_show  : 1;  //!< Признак отображения поля СИГН на МФЦИ 7
   uint16_t mfci8_sign_show  : 1;  //!< Признак отображения поля СИГН на МФЦИ 8
   uint16_t mfci9_sign_show  : 1;  //!< Признак отображения поля СИГН на МФЦИ 9
   uint16_t mfci10_sign_show : 1;  //!< Признак отображения поля СИГН на МФЦИ 10
   uint16_t mfci11_sign_show : 1;  //!< Признак отображения поля СИГН на МФЦИ 11
   uint16_t                  : 10; //!< Резерв
} mfci_sign_show_b_t;

//! Слово сигналов УПР для кадра ПЛАН
typedef struct upr_flag_word_plan_b_t {
   uint16_t grid        : 1;  //!< [УПР-Д022] Индикация масштабной сетки (СЕТК)
   uint16_t mup         : 1;  //!< [УПР-Д039] Вызов индикации МУП в кадре МФЦИ
   uint16_t fixed       : 1;  //!< [УПР-Д064] Признак фиксированного центра привязки и подвижного самолета (СЕВл)
   uint16_t scale_value : 3;  //!< [УПР-А001/СОИ-А038] Масштаб МФЦИ (mfci_scale_t)
   uint16_t             : 10; //!< Резерв
} upr_flag_word_plan_b_t;

//! Слово сигналов УПР для кадров КАРТА, КАРТА-НСТР (слово 1)
typedef struct upr_flag_word_kart_1_b_t {
   uint16_t mup           : 1; //!< [УПР-Д039] Вызов индикации МУП в кадре МФЦИ
   uint16_t scale_value   : 3; //!< [УПР-А001/СОИ-А038] Масштаб МФЦИ (mfci_scale_t)
   uint16_t nstr_submenu  : 3; //!< [СОИ] Подменю КАРТА-НСТР (0-нет, 1-НО, 2-ОТО, 3-ПО, 4-ЭКМ, 5-ДОП) //(min:0 max:5)
   uint16_t mrst          : 1; //!< [БСКИ-Д001] МРШТ (Слой ЛЗП)
   uint16_t no_aer        : 1; //!< [БСКИ-Д007] НО: АЭР (навигационная обстановка: слой аэродромов и цраниц аэродрома/аэроузла)
   uint16_t no_scheme_out : 1; //!< [БСКИ-Д008] НО: СХЕМЫ ВЫХОДА (навигационная обстановка: слой схемы выхода из района аэродрома/аэроузла)
   uint16_t no_scheme_in  : 1; //!< [БСКИ-Д009] НО: СХЕМЫ ПОДХОДА (навигационная обстановка: слой схемы подхода к району аэродрома и схемы посадки)
   uint16_t no_rts        : 1; //!< [БСКИ-Д010] НО: РТС (навигационная обстановка: слой радиотехнических средств навигации и посадки)
   uint16_t no_ovd_routes : 1; //!< [БСКИ-Д011] НО: МАРШРУТЫ ОВД (навигационная обстановка: слой маршрутов обеспечения воздушного движения)
   uint16_t no_es_orvd    : 1; //!< [БСКИ-Д012] НО: ЕС ОрВД (навигационная обстановка: слой границ зон единой системы организации воздушного движения)
   uint16_t no_excl_zones : 1; //!< [БСКИ-Д013] НО: ЗАПРЕТНЫЕ ЗОНЫ (навигационная обстановка: слой запретных зон, опасных зоны и зон ограничения полетов)
   uint16_t no_spec_zones : 1; //!< [БСКИ-Д014] НО: СПЕЦИАЛЬНЫЕ ЗОНЫ (навигационная обстановка: слой специальных зон)
} upr_flag_word_kart_1_b_t;

//! Слово сигналов УПР для кадров КАРТА, КАРТА-НСТР (слово 2)
typedef struct upr_flag_word_kart_2_b_t {
   uint16_t no_obstacle    : 1; //!< [БСКИ-Д015] НО: ПРЕПЯТСТВИЯ (навигационная обстановка: слой естественных и искусственных препятствий)
   uint16_t oto_pvo        : 1; //!< [БСКИ-Д016] ОТО: ПВО (оперативно-тактическая обстановка: слой противовоздушной обороны противника)
   uint16_t oto_vms        : 1; //!< [БСКИ-Д017] ОТО: ВМС (оперативно-тактическая обстановка: слой военно-морских сил противника)
   uint16_t oto_dang_zones : 1; //!< [БСКИ-Д018] ОТО: ЗОНЫ УГРОЗ (оперативно-тактическая обстановка: слой зон угроз)
   uint16_t oto_marks      : 1; //!< [БСКИ-Д019] ОТО: РУБЕЖИ-КОРИДОРЫ (оперативно-тактическая обстановка: слой рубежей перехвата, ввода в бой и Коридоров пролета)
   uint16_t oto_lines      : 1; //!< [БСКИ-Д020] ОТО: ЛИНИИ (оперативно-тактическая обстановка: слой линий соприкосновения войск)
   uint16_t po_polygones   : 1; //!< [БСКИ-Д021] ПО: ПОЛИГОНЫ (пользовательская обстановка: слой наземных и воздушных границы, мишеней, полигонов)
   uint16_t po_zones       : 1; //!< [БСКИ-Д022] ПО: ЗОНЫ (пользовательская обстановка: слой прочих зон)
   uint16_t ekm            : 2; //!< [БСКИ-Д023…БСКИ-Д025] ЭКМ (вид электронной карты местности: 0-цветная, 1-ночная, 2-градации серого)
   uint16_t w              : 2; //!< [БСКИ-Д029…БСКИ-Д032] ВЕКТОР W (вектор путевой скорости: 0-нет, 1-60 сек, 2-90 сек, 3-120 сек)
   uint16_t track          : 2; //!< [БСКИ-Д033…БСКИ-Д036] ТРЕК (линия пролета самолета: 0-нет, 1-15 мин, 2-30 мин, 3-постоянно)
   uint16_t kart           : 1; //!< [БСКИ-Д038] КАРТ (Включение отображения карты, всей целиком)
   uint16_t sevr           : 1; //!< [БСКИ-Д039] СЕВР (Ориентация карты на север)
} upr_flag_word_kart_2_b_t;

//! Слово сигналов УПР для кадров КАРТА, КАРТА-НСТР (слово 3)
typedef struct upr_flag_word_kart_3_b_t {
   uint16_t nav           : 1; //!< [БСКИ-Д047] НАВ (слой дополнительной полетной информации, курс, ППМ, ветер и т.п.)
   uint16_t fmt           : 2; //!< [БСКИ-Д048…БСКИ-Д050] ФОРМАТ КООРДИНАТ (0-ГГГ-ММ.М, 1-ГГГ-ММ'СС", 2-ГГГ°ММ'СС.СС") //(min:0 max:2)
   uint16_t relief        : 1; //!< [БСКИ-Д051] РЕЛЬЕФ (матрица рельефа)
   uint16_t no_dang_zones : 1; //!< [БСКИ-Д052] НО: ОПАСНЫЕ ЗОНЫ (зоны опасности для полетов)
   uint16_t move_vozv     : 1; //!< Нажатие на кнопку ВОЗВ (команда сброса сдвига карты)
   uint16_t move_up       : 1; //!< Нажатие на кнопку "стрелка вверх" (команда сдвига карты вверх)
   uint16_t move_down     : 1; //!< Нажатие на кнопку "стрелка вниз" (команда сдвига карты вниз)
   uint16_t move_left     : 1; //!< Нажатие на кнопку "стрелка влево" (команда сдвига карты влево)
   uint16_t move_right    : 1; //!< Нажатие на кнопку "стрелка вправо" (команда сдвига карты вправо)
   uint16_t               : 6; //!< Резерв
} upr_flag_word_kart_3_b_t;

//! Слово сигналов УПР для кадра ГРУП (слово 1)
typedef struct upr_flag_word_grup_1_b_t {
   uint16_t scale       : 3; //!< [СОИ] Масштаб (mfci_group_scale_t)
   uint16_t row_1_group : 3; //!< Номер ударной группы для левого ряда подменю кнопочного обрамления //(min:0 max:4)
   uint16_t row_2_group : 3; //!< Номер ударной группы для правого ряда подменю кнопочного обрамления //(min:0 max:4)
   uint16_t             : 7; //!< Резерв
} upr_flag_word_grup_1_b_t;

//! Слово сигналов УПР для кадра ГРУП (слово 2)
typedef struct upr_flag_word_grup_2_b_t {
   uint16_t column_1_number : 5; //!< Номер самолета, отображаемого в столбце 1 таблицы //(min:0 max:16)
   uint16_t column_2_number : 5; //!< Номер самолета, отображаемого в столбце 2 таблицы //(min:0 max:16)
   uint16_t column_3_number : 5; //!< Номер самолета, отображаемого в столбце 3 таблицы //(min:0 max:16)
   uint16_t                 : 1; //!< Резерв
} upr_flag_word_grup_2_b_t;

//! Слово сигналов УПР для кадра ГРУП (слово 3)
typedef struct upr_flag_word_grup_3_b_t {
   uint16_t column_4_number : 5; //!< Номер самолета, отображаемого в столбце 4 таблицы //(min:0 max:16)
   uint16_t column_5_number : 5; //!< Номер самолета, отображаемого в столбце 5 таблицы //(min:0 max:16)
   uint16_t column_6_number : 5; //!< Номер самолета, отображаемого в столбце 6 таблицы //(min:0 max:16)
   uint16_t                 : 1; //!< Резерв
} upr_flag_word_grup_3_b_t;

//! Слово сигналов УПР для кадра СУО-ИИПЭ
typedef struct upr_flag_word_suo_iipa_b_t {
   uint16_t : 16; //!< Резерв
} upr_flag_word_suo_iipa_b_t;

//! Слово сигналов УПР для кадра СУО-504/506 (слово 1)
typedef struct upr_flag_word_suo_50x_1_b_t {
   uint16_t scale_2_value   : 3; //!< [СОИ] Масштаб МФЦИ на странице 2 (mfci_scale_t)
   uint16_t scale_3_value   : 4; //!< [СОИ] Масштаб МФЦИ на странице 3 (mfci_scale_t)
   uint16_t signals_index   : 5; //!< [СОИ] Индекс первой отображаемой подсказки зоны 3 стр.1 //(min:0 max:29)
   uint16_t select_bz       : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.1] "Назначь БЗ (АСУ)"
   uint16_t select_hit_time : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.2] "Назначь время удара (АСУ)"
   uint16_t bz_cancelled    : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.3] "Отмени БЗ (АСУ)"
   uint16_t bz_missed       : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.4] "В БД нет БЗ (АСУ)"
} upr_flag_word_suo_50x_1_b_t;

//! Слово сигналов УПР для кадра СУО-504/506 (слово 2)
typedef struct upr_flag_word_suo_50x_2_b_t {
   uint16_t mpu_locked      : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.5] "Запрет повортота МПУ на 5 минут"
   uint16_t set_roll_5      : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.6] "Уменьши крен до 5°"
   uint16_t set_pitch_5     : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.7] "Установи тангаж от -5° до +15°"
   uint16_t set_mach_08     : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.8] "Уменьши число Маха до 0.8"
   uint16_t mach            : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.9] "Увеличь число Маха"
   uint16_t alt_up          : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.10] "Увеличь высоту"
   uint16_t alt_down        : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.11] "Уменьши высоту"
   uint16_t wrong_unit_type : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.12] "Тип изделия не соответствует БЗ"
   uint16_t drop_fail       : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.13] "Зависло"
   uint16_t emergency_drop  : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.14] "Аварийный сброс нижнего изделия"
   uint16_t pz_cancelled    : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.15] "Отмена нескольких ПЗ (АСУ)"
   uint16_t rear_spus_fail  : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.16] "Отказ СПУС заднего грузоотсека"
   uint16_t front_spus_fail : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.17] "Отказ СПУС переднего грузоотсека"
   uint16_t rear_fail       : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.18] "Отказ заднего грузоотсека"
   uint16_t front_fail      : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.19] "Отказ переднего грузоотсека"
   uint16_t rear_mpu_fail   : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.20] "Отказ МПУ заднего грузоотсека"
} upr_flag_word_suo_50x_2_b_t;

//! Слово сигналов УПР для кадра СУО-504/506 (слово 3)
typedef struct upr_flag_word_suo_50x_3_b_t {
   uint16_t front_mpu_fail    : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.21] "Отказ МПУ переднего грузоотсека"
   uint16_t rear_skv_manual   : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.22] "Ручное управление СКВ заднего грузоотсека"
   uint16_t front_skv_manual  : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.23] "Ручное управление СКВ переднего грузоотсека"
   uint16_t wrong_bz          : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.24] "Некорректное БЗ"
   uint16_t bz_loading_fail   : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.25] "Сбой загрузки БЗ"
   uint16_t load_route        : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.26] "Введи БЗ"
   uint16_t check_units       : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.27] "Проверь включение изделий"
   uint16_t set_hit_time      : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.28] "Введи время удара"
   uint16_t set_orzp          : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.29] "Назначь ОРЗП после расчета РВП"
   uint16_t set_align_mode    : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.30] "Включи режим подготовки"
   uint16_t rear_spus_res     : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.31] "Резервный канал СПУС заднего грузоотсека"
   uint16_t front_spus_res    : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.32] "Резервный канал СПУС переднего грузоотсека"
   uint16_t mode_finished     : 1; //!< [СОИ] Признак непрочитанного сигнала [БП-504/506-Д068.33] "Конец режима" (сигнал из МФЦИ в БГС)
   uint16_t show_course_scale : 1; //!< [СОИ] Отображать шкалу курса
   uint16_t show_nav_route    : 1; //!< [СОИ] Отображать маршрут полета и навигационные данные этапа маршрута
   uint16_t show_rzp          : 1; //!< [СОИ] Отображать координаты точек А/В РЗП (сигнал из МФЦИ в БГС)
} upr_flag_word_suo_50x_3_b_t;

//! Слово сигналов УПР для кадра СУО-504/506 (слово 4, в ФПО БП)
typedef struct upr_flag_word_suo_50x_4_b_t {
   uint16_t page_number     : 2; //!< [СОИ] Номер страницы кадра СУО-504/506 (сигнал из МФЦИ в БГС) //(min:1 max:3)
   uint16_t show_rvp        : 1; //!< [СОИ] Отображать РВП (сигнал из МФЦИ в БГС)
   uint16_t show_orzp       : 1; //!< [СОИ] Отображать координаты точек А/В ОРЗП и перемещение центра ОРЗП (сигнал из МФЦИ в БГС)
   uint16_t use_ti          : 1; //!< [СОИ] Центрировать область просмотра к точке интереса (режим "ЦОП", сигнал из МФЦИ в БГС)
   uint16_t command_counter : 2; //!< [СОИ] Счетчик команд для ФПО БП (сигнал из МФЦИ в ФПО БП) //(min:0 max:3)
   uint16_t command         : 2; //!< [СОИ] Команда (сигнал из МФЦИ в ФПО БП, iupk_aur_command_t) //(min:0 max:2)
   uint16_t                 : 7; //!< Резерв
} upr_flag_word_suo_50x_4_b_t;

//! Слово сигналов УПР для кадра РЛС (слово 1)
typedef struct upr_flag_word_rls_1_b_t {
   uint16_t btn_code; //!< Код нажатой кнопки для НВ РЛС (0-не нажата) //(min:0 max:40)
} upr_flag_word_rls_1_b_t;

//! Слово сигналов УПР для кадра РЛС (слово 2)
typedef struct upr_flag_word_rls_2_b_t {
   uint16_t mup   : 1;  //!< [УПР-Д039] Вызов индикации МУП в кадре МФЦИ
   uint16_t menu  : 1;  //!< Включение отображения меню выбора слоя
   uint16_t map   : 1;  //!< Включение отображения слоя КАРТ-ОТО
   uint16_t route : 1;  //!< Включение отображения слоя Маршрут
   uint16_t       : 12; //!< Резерв
} upr_flag_word_rls_2_b_t;

//! Слово сигналов УПР для кадра КВР (слово 1, нажатия на кнопки КВР)
typedef struct upr_flag_word_kvr_1_b_t {
   uint16_t button_16 : 1; //!< Нажатие на кнопку 16
   uint16_t button_15 : 1; //!< Нажатие на кнопку 15
   uint16_t button_14 : 1; //!< Нажатие на кнопку 14
   uint16_t button_13 : 1; //!< Нажатие на кнопку 13
   uint16_t button_12 : 1; //!< Нажатие на кнопку 12
   uint16_t button_11 : 1; //!< Нажатие на кнопку 11
   uint16_t button_10 : 1; //!< Нажатие на кнопку 10
   uint16_t button_9  : 1; //!< Нажатие на кнопку 9
   uint16_t button_8  : 1; //!< Нажатие на кнопку 8
   uint16_t button_7  : 1; //!< Нажатие на кнопку 7
   uint16_t button_6  : 1; //!< Нажатие на кнопку 6
   uint16_t button_5  : 1; //!< Нажатие на кнопку 5
   uint16_t button_4  : 1; //!< Нажатие на кнопку 4
   uint16_t button_3  : 1; //!< Нажатие на кнопку 3
   uint16_t button_2  : 1; //!< Нажатие на кнопку 2
   uint16_t button_1  : 1; //!< Нажатие на кнопку 1
} upr_flag_word_kvr_1_b_t;

//! Слово сигналов УПР для кадра КВР (слово 2, нажатия на кнопки КВР)
typedef struct upr_flag_word_kvr_2_b_t {
   uint16_t button_32 : 1; //!< Нажатие на кнопку 32
   uint16_t button_31 : 1; //!< Нажатие на кнопку 31
   uint16_t button_30 : 1; //!< Нажатие на кнопку 30
   uint16_t button_29 : 1; //!< Нажатие на кнопку 29
   uint16_t button_28 : 1; //!< Нажатие на кнопку 28
   uint16_t button_27 : 1; //!< Нажатие на кнопку 27
   uint16_t button_26 : 1; //!< Нажатие на кнопку 26
   uint16_t button_25 : 1; //!< Нажатие на кнопку 25
   uint16_t button_24 : 1; //!< Нажатие на кнопку 24
   uint16_t button_23 : 1; //!< Нажатие на кнопку 23
   uint16_t button_22 : 1; //!< Нажатие на кнопку 22
   uint16_t button_21 : 1; //!< Нажатие на кнопку 21
   uint16_t button_20 : 1; //!< Нажатие на кнопку 20
   uint16_t button_19 : 1; //!< Нажатие на кнопку 19
   uint16_t button_18 : 1; //!< Нажатие на кнопку 18
   uint16_t button_17 : 1; //!< Нажатие на кнопку 17
} upr_flag_word_kvr_2_b_t;

//! Слово сигналов УПР для кадра КВР (слово 3, нажатия на кнопки КВР)
typedef struct upr_flag_word_kvr_3_b_t {
   uint16_t mfci_type : 7; //!< Тип МФЦИ (125-узкоформатный, 126-широкоформатный) //(min:125 max:126)
   uint16_t           : 1; //!< Резерв
   uint16_t button_40 : 1; //!< Нажатие на кнопку 40
   uint16_t button_39 : 1; //!< Нажатие на кнопку 39
   uint16_t button_38 : 1; //!< Нажатие на кнопку 38
   uint16_t button_37 : 1; //!< Нажатие на кнопку 37
   uint16_t button_36 : 1; //!< Нажатие на кнопку 36
   uint16_t button_35 : 1; //!< Нажатие на кнопку 35
   uint16_t button_34 : 1; //!< Нажатие на кнопку 34
   uint16_t button_33 : 1; //!< Нажатие на кнопку 33
} upr_flag_word_kvr_3_b_t;

//! Слово сигналов УПР для кадра КВР (слово 4)
typedef struct upr_flag_word_kvr_4_b_t {
   uint16_t mup       : 1;  //!< [УПР-Д039] Вызов индикации МУП в кадре МФЦИ
   uint16_t rls_layer : 1;  //!< Индикация cлоя РЛС (от РЛС)
   uint16_t rtr_layer : 1;  //!< Индикация cлоя РТР (от КВР)
   uint16_t           : 13; //!< Резерв
} upr_flag_word_kvr_4_b_t;

//! Слово сигналов УПР для кадра АСУ (слово 1)
typedef struct upr_flag_word_asu_1_b_t {
   uint16_t asu_format                : 4; //!< Подкадр АСУ (режим функционирования задачи АСУ) //(min:0 max:8)
   uint16_t auto_mode_active          : 1; //!< Признак активности режима автоматизированной обработки
   uint16_t use_mfpu                  : 1; //!< Признак подключения МФПУ
   uint16_t address_prepare           : 1; //!< Признак выбора или ввода адреса получателя НФИ (АДР)
   uint16_t report_prepare            : 1; //!< Включение подготовки донесения к отправке (ИСП)
   uint16_t order_history_cursor_flag : 1; //!< Признак нахождения курсора в окне истории выполнения приказа (АРХ/ДОНС)
   uint16_t                           : 7; //!< Резерв
} upr_flag_word_asu_1_b_t;

//! Слово сигналов УПР для кадра АСУ (слово 2)
typedef struct upr_flag_word_asu_2_b_t {
   uint16_t index_1; //!< Индекс списка 1 //(min:0 max:65535)
} upr_flag_word_asu_2_b_t;

//! Слово сигналов УПР для кадра АСУ (слово 3)
typedef struct upr_flag_word_asu_3_b_t {
   uint16_t index_2; //!< Индекс списка 2 //(min:0 max:65535)
} upr_flag_word_asu_3_b_t;

//! Слово сигналов УПР для кадра РЭП (слово 1 нажатых МФК кадра РЭП)
typedef struct upr_flag_word_rap_1_b_t {
   uint16_t       : 2; //!< Резерв
   uint16_t exit  : 1; //!< Нажатие на МФК "Выход" (ВЫХ)
   uint16_t uv    : 1; //!< Нажатие на МФК "УВ"
   uint16_t ku    : 1; //!< Нажатие на МФК "КУ"
   uint16_t vz    : 1; //!< Нажатие на МФК "ВЗ"
   uint16_t iz    : 1; //!< Нажатие на МФК "ИЗ"
   uint16_t       : 1; //!< Резерв
   uint16_t zs    : 1; //!< Нажатие на МФК "ЗС"
   uint16_t ls    : 1; //!< Нажатие на МФК "ЛС"
   uint16_t ps    : 1; //!< Нажатие на МФК "ПС"
   uint16_t indic : 1; //!< Нажатие на МФК "ИНДК"
   uint16_t       : 1; //!< Резерв
   uint16_t rap_1 : 1; //!< Нажатие на МФК "РЭП1"
   uint16_t row_2 : 1; //!< Нажатие на МФК "РЯД2"
   uint16_t row_1 : 1; //!< Нажатие на МФК "РЯД1"
} upr_flag_word_rap_1_b_t;

//! Слово сигналов УПР для кадра РЭП (слово 2 нажатых МФК кадра РЭП)
typedef struct upr_flag_word_rap_2_b_t {
   uint16_t                  : 2; //!< Резерв
   uint16_t decrement        : 1; //!< Нажатие на МФК "ДЕК БВ" (Декремент номера блока выброса)
   uint16_t increment        : 1; //!< Нажатие на МФК "ИНК БВ" (Инкремент номера блока выброса)
   uint16_t limited_power    : 1; //!< Нажатие на МФК "ОМ" (Режим ограниченной мощности)
   uint16_t max_power        : 1; //!< Нажатие на МФК "ММ" (Режим максимальной мощности)
   uint16_t bu3              : 1; //!< Нажатие на МФК "3" (Выбор БУ3)
   uint16_t bu2              : 1; //!< Нажатие на МФК "2" (Выбор БУ2)
   uint16_t bu1              : 1; //!< Нажатие на МФК "1" (Выбор БУ1)
   uint16_t heading_scale    : 1; //!< Нажатие на МФК "КУРС" (Индикация курсовой шкалы)
   uint16_t dangerous_areas  : 1; //!< Нажатие на МФК "ЗП" (Индикация зон поражения)
   uint16_t ric_unidentified : 1; //!< Нажатие на МФК "НЕОП" (Индикация неопознанных РИЦ)
   uint16_t ric_overview     : 1; //!< Нажатие на МФК "ОБЗ" (Индикация РИЦ в режиме обзора)
   uint16_t ric_tracking     : 1; //!< Нажатие на МФК "СОПР" (Индикация РИЦ в режиме сопровождения)
   uint16_t manual           : 1; //!< Нажатие на МФК "РУЧН" (Ручной. режим работы)
   uint16_t automatic        : 1; //!< Нажатие на МФК "АВТ" (Авт. режим работы)
} upr_flag_word_rap_2_b_t;

//! Слово сигналов УПР для кадра РЭП (слово 3 нажатых МФК кадра РЭП)
typedef struct upr_flag_word_rap_3_b_t {
   uint16_t       : 8; //!< Резерв
   uint16_t mfk_8 : 1; //!< Нажатие на МФК № 8
   uint16_t mfk_7 : 1; //!< Нажатие на МФК № 7
   uint16_t mfk_6 : 1; //!< Нажатие на МФК № 6
   uint16_t mfk_5 : 1; //!< Нажатие на МФК № 5
   uint16_t mfk_4 : 1; //!< Нажатие на МФК № 4
   uint16_t mfk_3 : 1; //!< Нажатие на МФК № 3
   uint16_t mfk_2 : 1; //!< Нажатие на МФК № 2
   uint16_t mfk_1 : 1; //!< Нажатие на МФК № 1
} upr_flag_word_rap_3_b_t;

//! Слово сигналов УПР для кадра РЭП (слово 4)
typedef struct upr_flag_word_rap_4_b_t {
   uint16_t separation          : 1; //!< [СОИ-Б018] Режим разнесения меток РИЦ (РАЗД)
   uint16_t volume_show         : 1; //!< [СОИ-Б046] [(СОИ-Б045+СОИ-Б046)*T=5] Признак индикации схемы регулировки громкости
   uint16_t volume_down         : 1; //!< [СОИ-Б045] Признак уменьшения громкости (нажатие или удерживание кнопки уменьшения громкости)
   uint16_t volume_up           : 1; //!< [СОИ-Б046] Признак увеличения громкости (нажатие или удерживание кнопки увеличения громкости)
   uint16_t bsv_bu_loading_on   : 1; //!< [СОИ] Команда начать загрузку библиотеки угроз БУ и ПО (ЗАГР)
   uint16_t bsv_bu_loading_off  : 1; //!< [СОИ] Команда прервать загрузки библиотеки угроз БУ и ПО (ЗАГР)
   uint16_t scale_selecting     : 1; //!< [УПР-Д049] Активен режим индикации функции "выбор масштаба изображения"
   uint16_t scale_value         : 3; //!< [УПР-А001/СОИ-А038] Масштаб МФЦИ (mfci_scale_t)
   uint16_t separation_duration : 6; //!< Длительность режима разнесения меток РИЦ в секундах //(min:0 max:63)
} upr_flag_word_rap_4_b_t;

//! Слово сигналов УПР для кадра СВР (слово 1)
typedef struct upr_flag_word_svr_1_b_t {
   uint16_t format_zaps : 1; //!< [СВР-Д001] Подкадр ЗАПС (записи)
   uint16_t format_prsm : 1; //!< [СВР-Д002] Подкадр ПРСМ (просмотра ранее записанного)
   uint16_t format_teks : 1; //!< [СВР-Д003] Подкадр ТЕКЩ (просмотра текущего)
   uint16_t format_kont : 1; //!< [СВР-Д004] Подкадр КОНТ (тест-контроля)
   uint16_t tko         : 1; //!< [СВР-Д005/Д013/Д021] Запись/просмотр/контроль ТКО
   uint16_t mfi1        : 1; //!< [СВР-Д006/Д014/Д022] Запись/просмотр/контроль МФИ1
   uint16_t mfi2        : 1; //!< [СВР-Д007/Д015/Д023] Запись/просмотр/контроль МФИ2
   uint16_t mfi3        : 1; //!< [СВР-Д008/Д016/Д024] Запись/просмотр/контроль МФИ3
   uint16_t mfi4        : 1; //!< [СВР-Д009/Д017/Д025] Запись/просмотр/контроль МФИ4
   uint16_t mfi7        : 1; //!< [СВР-Д010/Д018/Д026] Запись/просмотр/контроль МФИ7
   uint16_t mfi8        : 1; //!< [СВР-Д011/Д019/Д027] Запись/просмотр/контроль МФИ8
   uint16_t mfi9        : 1; //!< [СВР-Д012/Д020/Д028] Запись/просмотр/контроль МФИ9
   uint16_t event_enter : 1; //!< [СВР-Д035] Команда ввода выставленного номера события СВР (активен режим ВВОД)
   uint16_t date_enter  : 1; //!< [СВР-Д035] Команда ввода выставленной даты записи СВР (активен режим ВВОД)
   uint16_t time_enter  : 1; //!< [СВР-Д035] Команда ввода выставленного времени записи СВР (активен режим ВВОД)
   uint16_t event_align : 1; //!< [СОИ-Д052] Установка номера события СВР (СОБТ)
} upr_flag_word_svr_1_b_t;

//! Слово сигналов УПР для кадра СВР (слово 2)
typedef struct upr_flag_word_svr_2_b_t {
   uint16_t date_align      : 1; //!< [СОИ-Д053] Установка даты записи СВР (ДАТА)
   uint16_t time_align      : 1; //!< [СОИ-Д054] Установка времени записи СВР (ВРЕМ)
   uint16_t play            : 1; //!< Команда включения воспроизведения / тест-контроля СВР (ПУСК)
   uint16_t stop            : 1; //!< Команда выключения воспроизведения (СТОП)
   uint16_t frame_prev      : 1; //!< Команда перехода к предыдущему кадру (КАДР, пред)
   uint16_t frame_next      : 1; //!< Команда перехода к следующему кадру (КАДР, след)
   uint16_t uskr_prev       : 1; //!< Команда ускоренного воспроизведения назад (УСКР, пред)
   uint16_t uskr_next       : 1; //!< Команда ускоренного воспроизведения вперед (УСКР, след)
   uint16_t cursor_position : 3; //!< Положение метки-курсора в окне установки СВР //(min:0 max:5)
   uint16_t                 : 5; //!< Резерв
} upr_flag_word_svr_2_b_t;

//! Слово сигналов УПР для кадра СВР (слово 3)
typedef struct upr_flag_word_svr_3_b_t {
   uint16_t edit_digit_1 : 4; //!< Цифра 1 выставленного значения даты, времени или номер события СВР //(min:0 max:9)
   uint16_t edit_digit_2 : 4; //!< Цифра 2 выставленного значения даты, времени или номер события СВР //(min:0 max:9)
   uint16_t edit_digit_3 : 4; //!< Цифра 3 выставленного значения даты или времени записи СВР //(min:0 max:9)
   uint16_t edit_digit_4 : 4; //!< Цифра 4 выставленного значения даты или времени записи СВР //(min:0 max:9)
} upr_flag_word_svr_3_b_t;

//! Слово сигналов УПР для кадра СВР (слово 4)
typedef struct upr_flag_word_svr_4_b_t {
   uint16_t edit_digit_5 : 4; //!< Цифра 5 выставленного значения даты, времени или номер события СВР //(min:0 max:9)
   uint16_t edit_digit_6 : 4; //!< Цифра 6 выставленного значения даты, времени или номер события СВР //(min:0 max:9)
   uint16_t              : 8; //!< Резерв
} upr_flag_word_svr_4_b_t;

//! Слово сигналов УПР для кадра ДВ/С
typedef struct upr_flag_word_dvs_b_t {
   uint16_t mech_brief : 1;  //!< Активен режим индикации фрагмента "упрв"
   uint16_t            : 15; //!< Резерв
} upr_flag_word_dvs_b_t;

//! Слово сигналов УПР для кадра ТОПЛ
typedef struct upr_flag_word_topl_b_t {
   uint16_t refuel  : 1;  //!< [УПР-Д044] Активен режим индикации ДЗТ (дозаправка топливом)
   uint16_t support : 1;  //!< [УПР-Д047] Активен режим индикации кадра ТОПЛ-СПРАВКА (ТС)
   uint16_t         : 14; //!< Резерв
} upr_flag_word_topl_b_t;

//! Слово сигналов УПР для кадра СЭС
typedef struct upr_flag_word_sas_b_t {
   uint16_t sas_115 : 1;  //!< [УПР-Д041] Активен режим индикации кадра СЭС "115 В"
   uint16_t sas_27  : 1;  //!< [УПР-Д042] Активен режим индикации кадра СЭС "27 В"
   uint16_t sas_uif : 1;  //!< [УПР-Д048] Активен режим индикации кадра СЭС "U-I-F"
   uint16_t         : 13; //!< Резерв
} upr_flag_word_sas_b_t;

//! Слово сигналов УПР для кадра РЛЭ
typedef struct upr_flag_word_rla_b_t {
   uint16_t page; //!< Страница РЛЭ //(min:0 max:220 bits:4..16 lsb:1)
} upr_flag_word_rla_b_t;

//! Слово 1 сигналов УПР для кадра ККД
typedef struct upr_flag_word_kkd_1_b_t {
   uint16_t cards_count       : 6; //!< Количество карт //(min:1 max:63)
   uint16_t next_page_pressed : 1; //!< Признак, фиксирующий, что страницы ККД листались вправо
   uint16_t                   : 9; //!< Резерв
} upr_flag_word_kkd_1_b_t;

//! Слово 2 сигналов УПР для кадра ККД
typedef struct upr_flag_word_kkd_2_b_t {
   uint16_t page_id; //!< Страница ККД //(min:0 max:19 bits:4..16 lsb:1)
} upr_flag_word_kkd_2_b_t;

//! Слово 3 сигналов УПР для кадра ККД
typedef struct upr_flag_word_kkd_3_b_t {
   uint16_t selected_page_id; //!< Зачитываемая страница ККД //(min:0 max:19 bits:4..16 lsb:1)
} upr_flag_word_kkd_3_b_t;

//! Слово сигналов УПР для кадра БАСК (слово состояния кнопок индикатора)
typedef struct upr_flag_word_bask_b_t {
   uint16_t           : 2; //!< Резерв
   uint16_t button_14 : 1; //!< Нажатие на кнопку № 14 (ГМБ)
   uint16_t button_13 : 1; //!< Нажатие на кнопку № 13 (ВОЗВ)
   uint16_t button_12 : 1; //!< Нажатие на кнопку № 12 (стрелка вниз)
   uint16_t button_11 : 1; //!< Нажатие на кнопку № 11 (стрелка вверх)
   uint16_t button_10 : 1; //!< Нажатие на кнопку № 10 (6-ю правую)
   uint16_t button_9  : 1; //!< Нажатие на кнопку № 9 (5-ю правую)
   uint16_t button_8  : 1; //!< Нажатие на кнопку № 8 (4-ю правую)
   uint16_t button_7  : 1; //!< Нажатие на кнопку № 7 (3-ю правую)
   uint16_t button_6  : 1; //!< Нажатие на кнопку № 6 (2-ю правую)
   uint16_t button_5  : 1; //!< Нажатие на кнопку № 5 (6-ю левую)
   uint16_t button_4  : 1; //!< Нажатие на кнопку № 4 (5-ю левую)
   uint16_t button_3  : 1; //!< Нажатие на кнопку № 3 (4-ю левую)
   uint16_t button_2  : 1; //!< Нажатие на кнопку № 2 (3-ю левую)
   uint16_t button_1  : 1; //!< Нажатие на кнопку № 1 (2-ю левую)
} upr_flag_word_bask_b_t;

//! Слово сигналов УПР для кадра МСРП (слово "Код управления")
typedef struct upr_flag_word_msrp_b_t {
   uint16_t              : 13; //!< Резерв
   uint16_t code_control : 3;  //!< Код управления (0-начало отчета, 1-следующая страница, 2-предыдущая страница) //(min:0 max:2)
} upr_flag_word_msrp_b_t;

//! Слово сигналов УПР для кадров БЛОКИ, БЛОКИ-КС (слово 1)
typedef struct upr_flag_word_blocks_1_b_t {
   uint16_t mode      : 6; //!< Режим работы кадра БЛОКИ (mfci_blocks_mode_t)
   uint16_t system    : 6; //!< Выбранная система (mfci_blocks_system_t)
   uint16_t subsystem : 4; //!< Выбранная подсистема/модуль //(min:0 max:15)
} upr_flag_word_blocks_1_b_t;

//! Слово сигналов УПР для кадров БЛОКИ, БЛОКИ-КС (слово 2)
typedef struct upr_flag_word_blocks_2_b_t {
   uint16_t number    : 6; //!< Номер нажатой кнопки (для режима работы ТЕСТ) /  Страница сводного перечня отказов //(min:1 max:63)
   uint16_t button_l1 : 1; //!< Исправность кнопки левой 1
   uint16_t button_l2 : 1; //!< Исправность кнопки левой 2
   uint16_t button_l3 : 1; //!< Исправность кнопки левой 3
   uint16_t button_l4 : 1; //!< Исправность кнопки левой 4
   uint16_t button_l5 : 1; //!< Исправность кнопки левой 5
   uint16_t button_l6 : 1; //!< Исправность кнопки левой 6
   uint16_t button_l7 : 1; //!< Исправность кнопки левой 7
   uint16_t button_l8 : 1; //!< Исправность кнопки левой 8
   uint16_t button_r1 : 1; //!< Исправность кнопки правой 1
   uint16_t button_r2 : 1; //!< Исправность кнопки правой 2
} upr_flag_word_blocks_2_b_t;

//! Слово сигналов УПР для кадров БЛОКИ, БЛОКИ-КС (слово 3)
typedef struct upr_flag_word_blocks_3_b_t {
   uint16_t button_r3 : 1; //!< Исправность кнопки правой 3
   uint16_t button_r4 : 1; //!< Исправность кнопки правой 4
   uint16_t button_r5 : 1; //!< Исправность кнопки правой 5
   uint16_t button_r6 : 1; //!< Исправность кнопки правой 6
   uint16_t button_r7 : 1; //!< Исправность кнопки правой 7
   uint16_t button_r8 : 1; //!< Исправность кнопки правой 8
   uint16_t button_t1 : 1; //!< Исправность кнопки верхней 1
   uint16_t button_t2 : 1; //!< Исправность кнопки верхней 2
   uint16_t button_t3 : 1; //!< Исправность кнопки верхней 3
   uint16_t button_t4 : 1; //!< Исправность кнопки верхней 4
   uint16_t button_t5 : 1; //!< Исправность кнопки верхней 5
   uint16_t button_b1 : 1; //!< Исправность кнопки нижней 1
   uint16_t button_b2 : 1; //!< Исправность кнопки нижней 2
   uint16_t button_b3 : 1; //!< Исправность кнопки нижней 3
   uint16_t button_b4 : 1; //!< Исправность кнопки нижней 4
   uint16_t button_b5 : 1; //!< Исправность кнопки нижней 5
} upr_flag_word_blocks_3_b_t;

//! Слово сигналов УПР для кадров БЛОКИ, БЛОКИ-КС (слово 4)
typedef struct upr_flag_word_blocks_4_b_t {
   uint16_t button_t6          : 1; //!< Исправность кнопки верхней 6
   uint16_t button_t7          : 1; //!< Исправность кнопки верхней 7
   uint16_t button_t8          : 1; //!< Исправность кнопки верхней 8
   uint16_t button_t9          : 1; //!< Исправность кнопки верхней 9
   uint16_t button_t10         : 1; //!< Исправность кнопки верхней 10
   uint16_t button_t11         : 1; //!< Исправность кнопки верхней 11
   uint16_t button_t12         : 1; //!< Исправность кнопки верхней 12
   uint16_t button_b6          : 1; //!< Исправность кнопки нижней 6
   uint16_t button_b7          : 1; //!< Исправность кнопки нижней 7
   uint16_t button_b8          : 1; //!< Исправность кнопки нижней 8
   uint16_t button_b9          : 1; //!< Исправность кнопки нижней 9
   uint16_t button_b10         : 1; //!< Исправность кнопки нижней 10
   uint16_t button_b11         : 1; //!< Исправность кнопки нижней 11
   uint16_t button_b12         : 1; //!< Исправность кнопки нижней 12
   uint16_t tests_passed       : 1; //!< Тесты яркости, контрастности и кнопок пройдены
   uint16_t show_build_numbers : 1; //!< Индицировать номера сборок модулей
} upr_flag_word_blocks_4_b_t;

//! Слово сигналов УПР для кадра БЛОКИ-СЗИ
typedef struct upr_flag_word_blocks_szi_b_t {
   uint16_t system : 6;  //!< Выбранная система (mfci_blocks_system_t)
   uint16_t        : 10; //!< Резерв
} upr_flag_word_blocks_szi_b_t;

//! Слово сигналов УПР для кадра ТАР
typedef struct upr_flag_word_tar_b_t {
   uint16_t uks_number         : 3; //!< Номер выбранного УКС //(min:1 max:4)
   uint16_t parameter_number   : 4; //!< Номер тарируемого параметра //(min:1 max:10)
   uint16_t code_number        : 3; //!< Номер выбранной узловой точки тарируемого параметра //(min:1 max:7)
   uint16_t cmd_load_table     : 1; //!< Команда включения/отмены чтения таблицы тарировок в УКС
   uint16_t cmd_save_table     : 1; //!< Команда включения/отмены записи таблицы тарировок в УКС
   uint16_t cmd_save_code      : 1; //!< Команда фиксирования кода АЦП для выбранной узловой точки тарируемого параметра
   uint16_t soi_parameter_edit : 1; //!< Редактирование выбранного параметра УКС (параметр для БГС)
   uint16_t                    : 2; //!< Резерв
} upr_flag_word_tar_b_t;

//! Слово сигналов УПР для активного кадра
typedef union upr_flag_word_format_b_t {
   upr_flag_word_plan_b_t       plan_b;       //!< Управляющие сигналы МФЦИ для кадра ПЛАН
   upr_flag_word_kart_1_b_t     kart_1_b;     //!< Управляющие сигналы МФЦИ для кадра КАРТА, КАРТА-НСТР (слово 1)
   upr_flag_word_kart_2_b_t     kart_2_b;     //!< Управляющие сигналы МФЦИ для кадра КАРТА, КАРТА-НСТР (слово 2)
   upr_flag_word_kart_3_b_t     kart_3_b;     //!< Управляющие сигналы МФЦИ для кадра КАРТА, КАРТА-НСТР (слово 3)
   upr_flag_word_grup_1_b_t     grup_1_b;     //!< Управляющие сигналы МФЦИ для кадра ГРУП (слово 1)
   upr_flag_word_grup_2_b_t     grup_2_b;     //!< Управляющие сигналы МФЦИ для кадра ГРУП (слово 2)
   upr_flag_word_grup_3_b_t     grup_3_b;     //!< Управляющие сигналы МФЦИ для кадра ГРУП (слово 3)
   upr_flag_word_suo_iipa_b_t   suo_iipa_b;   //!< Управляющие сигналы МФЦИ для кадра СУО-ИИПЭ
   upr_flag_word_suo_50x_1_b_t  suo_50x_1_b;  //!< Управляющие сигналы МФЦИ для кадра СУО-504/506 (слово 1)
   upr_flag_word_suo_50x_2_b_t  suo_50x_2_b;  //!< Управляющие сигналы МФЦИ для кадра СУО-504/506 (слово 2)
   upr_flag_word_suo_50x_3_b_t  suo_50x_3_b;  //!< Управляющие сигналы МФЦИ для кадра СУО-504/506 (слово 3)
   upr_flag_word_suo_50x_4_b_t  suo_50x_4_b;  //!< Управляющие сигналы МФЦИ для кадра СУО-504/506 (слово 4)
   upr_flag_word_rls_1_b_t      rls_1_b;      //!< Управляющие сигналы МФЦИ для кадра РЛС (слово 1)
   upr_flag_word_rls_2_b_t      rls_2_b;      //!< Управляющие сигналы МФЦИ для кадра РЛС (слово 2)
   upr_flag_word_kvr_1_b_t      kvr_1_b;      //!< Управляющие сигналы МФЦИ для кадра КВР (слово 1)
   upr_flag_word_kvr_2_b_t      kvr_2_b;      //!< Управляющие сигналы МФЦИ для кадра КВР (слово 2)
   upr_flag_word_kvr_3_b_t      kvr_3_b;      //!< Управляющие сигналы МФЦИ для кадра КВР (слово 3)
   upr_flag_word_kvr_4_b_t      kvr_4_b;      //!< Управляющие сигналы МФЦИ для кадра КВР (слово 4)
   upr_flag_word_asu_1_b_t      asu_1_b;      //!< Управляющие сигналы МФЦИ для кадра АСУ (слово 1)
   upr_flag_word_asu_2_b_t      asu_2_b;      //!< Управляющие сигналы МФЦИ для кадра АСУ (слово 2)
   upr_flag_word_asu_3_b_t      asu_3_b;      //!< Управляющие сигналы МФЦИ для кадра АСУ (слово 3)
   upr_flag_word_rap_1_b_t      rap_1_b;      //!< Управляющие сигналы МФЦИ для кадра РЭП (слово 1)
   upr_flag_word_rap_2_b_t      rap_2_b;      //!< Управляющие сигналы МФЦИ для кадра РЭП (слово 2)
   upr_flag_word_rap_3_b_t      rap_3_b;      //!< Управляющие сигналы МФЦИ для кадра РЭП (слово 3)
   upr_flag_word_rap_4_b_t      rap_4_b;      //!< Управляющие сигналы МФЦИ для кадра РЭП (слово 4)
   upr_flag_word_svr_1_b_t      svr_1_b;      //!< Управляющие сигналы МФЦИ для кадра СВР (слово 1)
   upr_flag_word_svr_2_b_t      svr_2_b;      //!< Управляющие сигналы МФЦИ для кадра СВР (слово 2)
   upr_flag_word_svr_3_b_t      svr_3_b;      //!< Управляющие сигналы МФЦИ для кадра СВР (слово 3)
   upr_flag_word_svr_4_b_t      svr_4_b;      //!< Управляющие сигналы МФЦИ для кадра СВР (слово 4)
   upr_flag_word_dvs_b_t        dvs_b;        //!< Управляющие сигналы МФЦИ для кадра ДВ/С
   upr_flag_word_topl_b_t       topl_b;       //!< Управляющие сигналы МФЦИ для кадра ТОПЛ
   upr_flag_word_sas_b_t        sas_b;        //!< Управляющие сигналы МФЦИ для кадра СЭС
   upr_flag_word_rla_b_t        rla_b;        //!< Управляющие сигналы МФЦИ для кадра РЛЭ
   upr_flag_word_kkd_1_b_t      kkd_1_b;      //!< Управляющие сигналы МФЦИ для кадра ККД (слово 1)
   upr_flag_word_kkd_2_b_t      kkd_2_b;      //!< Управляющие сигналы МФЦИ для кадра ККД (слово 2)
   upr_flag_word_kkd_3_b_t      kkd_3_b;      //!< Управляющие сигналы МФЦИ для кадра ККД (слово 3)
   upr_flag_word_bask_b_t       bask_b;       //!< Управляющие сигналы МФЦИ для кадра БАСК
   upr_flag_word_msrp_b_t       msrp_b;       //!< Управляющие сигналы МФЦИ для кадра МСРП
   upr_flag_word_blocks_1_b_t   blocks_1_b;   //!< Управляющие сигналы МФЦИ для кадра БЛОКИ (слово 1)
   upr_flag_word_blocks_2_b_t   blocks_2_b;   //!< Управляющие сигналы МФЦИ для кадра БЛОКИ (слово 2)
   upr_flag_word_blocks_3_b_t   blocks_3_b;   //!< Управляющие сигналы МФЦИ для кадра БЛОКИ (слово 3)
   upr_flag_word_blocks_4_b_t   blocks_4_b;   //!< Управляющие сигналы МФЦИ для кадра БЛОКИ (слово 4)
   upr_flag_word_blocks_szi_b_t blocks_szi_b; //!< Управляющие сигналы МФЦИ для кадра БЛОКИ-СЗИ
   upr_flag_word_tar_b_t        tar_b;        //!< Управляющие сигналы МФЦИ для кадра ТАР
} upr_flag_word_format_b_t;

//! Входное сообщение МФЦИ, подадрес 1 МКИО-3.1 (25 Гц, передается постоянно)
typedef struct mfci_in_sa_1_b_t {
   uint16_t                 counter;           //!< Счетчик контроля достоверности данных //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                 header_revision;   //!< Ревизия заголовочника (MFCI_IO_REVISION) //(min:1 max:65535 bits:4..19 lsb:1)
   mfci_signals_word_1_b_t  signals_word_1_b;  //!< Слово 1 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_2_b_t  signals_word_2_b;  //!< Слово 2 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_3_b_t  signals_word_3_b;  //!< Слово 3 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_4_b_t  signals_word_4_b;  //!< Слово 4 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_5_b_t  signals_word_5_b;  //!< Слово 5 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_6_b_t  signals_word_6_b;  //!< Слово 6 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_7_b_t  signals_word_7_b;  //!< Слово 7 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_8_b_t  signals_word_8_b;  //!< Слово 8 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_9_b_t  signals_word_9_b;  //!< Слово 9 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_10_b_t signals_word_10_b; //!< Слово 10 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_11_b_t signals_word_11_b; //!< Слово 11 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_12_b_t signals_word_12_b; //!< Слово 12 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_13_b_t signals_word_13_b; //!< Слово 13 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_14_b_t signals_word_14_b; //!< Слово 14 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_15_b_t signals_word_15_b; //!< Слово 15 сигнализации МФЦИ (сигналы ДВ)
   mfci_signals_word_16_b_t signals_word_16_b; //!< Слово 16 сигнализации МФЦИ (сигналы ДВ, ТОПЛ)
   mfci_signals_word_17_b_t signals_word_17_b; //!< Слово 17 сигнализации МФЦИ (сигналы ТОПЛ)
   mfci_signals_word_18_b_t signals_word_18_b; //!< Слово 18 сигнализации МФЦИ (сигналы ТОПЛ)
   mfci_signals_word_19_b_t signals_word_19_b; //!< Слово 19 сигнализации МФЦИ (сигналы ТОПЛ)
   mfci_signals_word_20_b_t signals_word_20_b; //!< Слово 20 сигнализации МФЦИ (сигналы ТОПЛ, ПКР)
   mfci_signals_word_21_b_t signals_word_21_b; //!< Слово 21 сигнализации МФЦИ (сигналы ПКР, САУ)
   mfci_signals_word_22_b_t signals_word_22_b; //!< Слово 22 сигнализации МФЦИ (сигналы САУ, АБСУ)
   mfci_signals_word_23_b_t signals_word_23_b; //!< Слово 23 сигнализации МФЦИ (сигналы АБСУ)
   mfci_signals_word_24_b_t signals_word_24_b; //!< Слово 24 сигнализации МФЦИ (сигналы АБСУ)
   mfci_signals_word_25_b_t signals_word_25_b; //!< Слово 25 сигнализации МФЦИ (сигналы АБСУ, СМК)
   mfci_signals_word_26_b_t signals_word_26_b; //!< Слово 26 сигнализации МФЦИ (сигналы СМК, СК, ТОРМ)
   mfci_signals_word_27_b_t signals_word_27_b; //!< Слово 27 сигнализации МФЦИ (сигналы ТОРМ, СЭС)
   mfci_signals_word_28_b_t signals_word_28_b; //!< Слово 28 сигнализации МФЦИ (сигналы СЭС)
   mfci_signals_word_29_b_t signals_word_29_b; //!< Слово 29 сигнализации МФЦИ (сигналы СЭС)
   mfci_signals_word_30_b_t signals_word_30_b; //!< Слово 30 сигнализации МФЦИ (сигналы ГС)
} mfci_in_sa_1_b_t;

//! Входное сообщение МФЦИ, подадрес 2 МКИО-3.1 (25 Гц, передается постоянно)
typedef struct mfci_in_sa_2_b_t {
   mfci_signals_word_31_b_t    signals_word_31_b;    //!< Слово 31 сигнализации МФЦИ (сигналы ВСУ)
   mfci_signals_word_32_b_t    signals_word_32_b;    //!< Слово 32 сигнализации МФЦИ (сигналы ВСУ, СКВ)
   mfci_signals_word_33_b_t    signals_word_33_b;    //!< Слово 33 сигнализации МФЦИ (сигналы СКВ, СОИ)
   mfci_signals_word_34_b_t    signals_word_34_b;    //!< Слово 34 сигнализации МФЦИ (сигналы ИНС, АНС, СВС)
   mfci_signals_word_35_b_t    signals_word_35_b;    //!< Слово 35 сигнализации МФЦИ (сигналы СВС)
   mfci_signals_word_36_b_t    signals_word_36_b;    //!< Слово 36 сигнализации МФЦИ (сигналы КИСЛ)
   mfci_signals_word_37_b_t    signals_word_37_b;    //!< Слово 37 сигнализации МФЦИ (сигналы КИСЛ, ШАСС, ЛЕД)
   mfci_signals_word_38_b_t    signals_word_38_b;    //!< Слово 38 сигнализации МФЦИ (сигналы БЦВМ
   mfci_signals_word_39_b_t    signals_word_39_b;    //!< Слово 39 сигнализации МФЦИ (сигналы БЦВМ, РЭП)
   mfci_signals_word_40_b_t    signals_word_40_b;    //!< Слово 40 сигнализации МФЦИ (сигналы РЭП, К070)
   mfci_signals_word_41_b_t    signals_word_41_b;    //!< Слово 41 сигнализации МФЦИ (сигналы К070, СУО, БАСУ, С505)
   mfci_signals_word_42_b_t    signals_word_42_b;    //!< Слово 42 сигнализации МФЦИ (сигналы МФИ)
   mfci_signals_word_43_b_t    signals_word_43_b;    //!< Слово 43 сигнализации МФЦИ (сигналы МФИ, МФПУ, ЛЮКИ)
   mfci_signals_word_44_b_t    signals_word_44_b;    //!< Слово 44 сигнализации МФЦИ (отказы систем)
   mfci_signals_word_45_b_t    signals_word_45_b;    //!< Слово 45 сигнализации МФЦИ (отказы систем)
   mfci_signals_word_46_b_t    signals_word_46_b;    //!< Слово 46 сигнализации МФЦИ (отказы систем)
   mfci_signals_word_47_b_t    signals_word_47_b;    //!< Слово 47 сигнализации МФЦИ (сигналы СПЗ)
   mfci_signals_word_48_b_t    signals_word_48_b;    //!< Слово 48 сигнализации МФЦИ (сигналы СПЗ)
   mfci_signals_word_49_b_t    signals_word_49_b;    //!< Слово 49 сигнализации МФЦИ (сигналы СПЗ)
   mfci_signals_word_50_b_t    signals_word_50_b;    //!< Слово 50 сигнализации МФЦИ (сигналы СПЗ, РАД, БЦВМ, НО)
   mfci_signals_word_51_b_t    signals_word_51_b;    //!< Слово 51 сигнализации МФЦИ (сигналы БЦВМ, НО)
   mfci_signals_word_52_b_t    signals_word_52_b;    //!< Слово 52 сигнализации МФЦИ (сигналы БЦВМ, НО, ПБД, БГС)
   mfci_signals_word_53_b_t    signals_word_53_b;    //!< Слово 53 сигнализации МФЦИ (сигналы НГ, СНС, СУПК)
   mfci_signals_word_54_b_t    signals_word_54_b;    //!< Слово 54 сигнализации МФЦИ (сигналы САС/ЦСО)
   gears_flag_word_b_t         gears_flag_word_b;    //!< Слово сигналов шасси
   bcvm_valid_word_1_b_t       bcvm_valid_word_1_b;  //!< Слово 1 достоверностей БЦВМ
   bcvm_valid_word_2_b_t       bcvm_valid_word_2_b;  //!< Слово 2 достоверностей БЦВМ
   bcvm_valid_word_3_b_t       bcvm_valid_word_3_b;  //!< Слово 3 достоверностей БЦВМ
   sau_smk_valid_word_b_t      sau_smk_valid_word_b; //!< Слово достоверностей САУ/СМК
   uint16_t                    sau_director_x;       //!< [САУ-А001] Команда директорная по крену //(min:-30 max:30 signed:4 bits:5..19 msb:90°)
   uint16_t                    sau_director_y;       //!< [САУ-А002] Команда директорная по тангажу //(min:-40 max:40 signed:4 bits:5..19 msb:90°)
   uint16_t                    sau_course_selected;  //!< [САУ-А003] Заданный курс/путевой угол //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
} mfci_in_sa_2_b_t;

//! Входное сообщение МФЦИ, подадрес 3 МКИО-3.1 (25 Гц, передается постоянно)
typedef struct mfci_in_sa_3_b_t {
   ins_svs_numbers_b_t           ins_svs_numbers_b;           //!< Номера используемых ИНС/СВС
   bcvm_flag_word_1_b_t          bcvm_flag_word_1_b;          //!< Слово 1 сигналов БЦВМ
   svs_absu_rts_valid_word_1_b_t svs_absu_rts_valid_word_1_b; //!< Слово 1 достоверностей СВС/АБСУ/РТС
   svs_absu_rts_valid_word_2_b_t svs_absu_rts_valid_word_2_b; //!< Слово 2 достоверностей СВС/АБСУ/РТС
   svs_absu_rts_valid_word_3_b_t svs_absu_rts_valid_word_3_b; //!< Слово 3 достоверностей СВС/АБСУ/РТС
   rsbn_vim_dme_flag_word_b_t    rsbn_vim_dme_flag_word_b;    //!< Слово сигналов РСБН/VIM/DME
   uint16_t                      absu_alpha;                  //!< [АБСУ-А001] Угол атаки истинный //(min:-5 max:25 signed:4 bits:5..19 msb:90°)
   uint16_t                      ark_bearing;                 //!< [АРК-А001] Курсовой угол радиостанции АРК //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                      rvm_altitude_k;              //!< [РВМ-А001] Радиовысота малых высот (для командира и навигатора) //(min:0 max:4921.25984 signed:4 bits:5..19 msb:4096 фут)
   uint16_t                      rvm_altitude_p;              //!< [РВМ-А001] Радиовысота малых высот (для помощника и оператора) //(min:0 max:4921.25984 signed:4 bits:5..19 msb:4096 фут)
   uint16_t                      rvb_altitude;                //!< [РВБ-А001] Радиовысота больших высот //(min:0 max:6000 bits:4..18 msb:8192 м)
   uint16_t                      rsbn_delta_y_1;              //!< [РСБН-А002] Отклонение от глиссады снижения (канал 1) //(min:-50 max:50 signed:4 bits:5..15 msb:25 % КРС)
   uint16_t                      rsbn_delta_x_1;              //!< [РСБН-А003] Отклонение от курса посадки (канал 1) //(min:-50 max:50 signed:4 bits:5..15 msb:25 % КРС)
   uint16_t                      rsbn_delta_y_2;              //!< [РСБН-А002] Отклонение от глиссады снижения (канал 2) //(min:-50 max:50 signed:4 bits:5..15 msb:25 % КРС)
   uint16_t                      rsbn_delta_x_2;              //!< [РСБН-А003] Отклонение от курса посадки (канал 2) //(min:-50 max:50 signed:4 bits:5..15 msb:25 % КРС)
   uint16_t                      rsbn_delta_rpk;              //!< [РСБН-А007] Отклонение от пеленга до взаимодействующего ЛА) //(min:-50 max:50 signed:4 bits:5..15 msb:25 % КРС)
   uint16_t                      svs_altitude_abs_k;          //!< [СВС-А001] Высота абсолютная (для командира и навигатора) //(min:-500 max:30000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                      svs_altitude_abs_p;          //!< [СВС-А001] Высота абсолютная (для помощника и оператора) //(min:-500 max:30000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                      svs_indicated_speed_k;       //!< [СВС-А002] Приборная скорость (для командира и навигатора) //(min:0 max:1600 signed:4 bits:5..18 msb:948.224 км/ч)
   uint16_t                      svs_indicated_speed_p;       //!< [СВС-А002] Приборная скорость (для помощника и оператора) //(min:0 max:1600 signed:4 bits:5..18 msb:948.224 км/ч)
   uint16_t                      svs_mach_k;                  //!< [СВС-А003] Число Маха (для командира и навигатора) //(min:0 max:3 signed:4 bits:5..19 msb:2.048)
   uint16_t                      svs_mach_p;                  //!< [СВС-А003] Число Маха (для помощника и оператора) //(min:0 max:3 signed:4 bits:5..19 msb:2.048)
   uint16_t                      svs_altitude_qnh_k;          //!< [СВС-А004] Высота QNH (для командира и навигатора) //(min:-500 max:30000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                      svs_altitude_qnh_p;          //!< [СВС-А004] Высота QNH (для помощника и оператора) //(min:-500 max:30000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                      svs_altitude_qfe_k;          //!< [СВС-А005] Высота QFE (для командира и навигатора) //(min:-500 max:30000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                      svs_altitude_qfe_p;          //!< [СВС-А005] Высота QFE (для помощника и оператора) //(min:-500 max:30000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                      svs_vy_k;                    //!< [СВС-А008] Вертикальная скорость (для командира и навигатора) //(min:-100 max:100 signed:4 bits:5..15 msb:83.23072 м/с)
   uint16_t                      svs_vy_p;                    //!< [СВС-А008] Вертикальная скорость (для помощника и оператора) //(min:-100 max:100 signed:4 bits:5..15 msb:83.23072 м/с)
   uint16_t                      vim_ils1_delta_x;            //!< [VIM-А006] Отклонение от курса посадки ILS1 //(min:-0.4 max:0.4 signed:4 bits:5..16 msb:0.2 РГМ)
   uint16_t                      vim_ils1_delta_y;            //!< [VIM-А007] Отклонение от глиссады снижения ILS1 //(min:-0.8 max:0.8 signed:4 bits:5..16 msb:0.4 РГМ)
   uint16_t                      vim_ils2_delta_x;            //!< [VIM-А006] Отклонение от курса посадки ILS2 //(min:-0.4 max:0.4 signed:4 bits:5..16 msb:0.2 РГМ)
   uint16_t                      vim_ils2_delta_y;            //!< [VIM-А007] Отклонение от глиссады снижения ILS2 //(min:-0.8 max:0.8 signed:4 bits:5..16 msb:0.4 РГМ)
} mfci_in_sa_3_b_t;

//! Входное сообщение МФЦИ, подадрес 4 МКИО-3.1 (25 Гц, данные используются в кадрах КПИ, ПНП, ПЛАН, КАРТ, СУО, ГРУП, ДВ/С, ДВ, УПР)
typedef struct mfci_in_sa_4_b_t {
   ins_ans_valid_word_1_b_t ins_ans_valid_word_1_b;      //!< Слово 1 достоверностей ИНС/АНС
   ins_ans_valid_word_2_b_t ins_ans_valid_word_2_b;      //!< Слово 2 достоверностей ИНС/АНС
   uint16_t                 bcvm_magn_course;            //!< [БЦВМ-А003] Курс магнитный //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 bcvm_true_course;            //!< [БЦВМ-А004] Курс истинный //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 bcvm_true_pu;                //!< [БЦВМ-А007] Путевой угол истинный //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 bcvm_magn_pu;                //!< [БЦВМ-А009] Путевой угол магнитный //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 bcvm_drift_angle;            //!< [БЦВМ-А028] Угол сноса //(min:-30 max:30 signed:4 bits:5..19 msb:90°)
   uint16_t                 ins_roll_k;                  //!< [ИНС-А001] Угол крена (для командира и навигатора) //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                 ins_roll_p;                  //!< [ИНС-А001] Угол крена (для помощника и оператора) //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                 ins_pitch_k;                 //!< [ИНС-А002] Угол тангажа (для командира и навигатора) //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                 ins_pitch_p;                 //!< [ИНС-А002] Угол тангажа (для помощника и оператора) //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                 ins_nz;                      //!< [ИНС-А003] Боковая перегрузка //(min:-40 max:40 signed:4 bits:5..19 msb:20 м/кв.с)
   uint16_t                 ins_ny_k;                    //!< [ИНС-А004] Нормальная перегрузка (для командира и навигатора) //(min:-40 max:40 signed:4 bits:5..19 msb:20 м/кв.с)
   uint16_t                 ins_ny_p;                    //!< [ИНС-А004] Нормальная перегрузка (для помощника и оператора) //(min:-40 max:40 signed:4 bits:5..19 msb:20 м/кв.с)
   uint16_t                 ins_nx;                      //!< [ИНС-А009] Горизонтальное ускорение вдоль траектории движения //(min:-40 max:40 signed:4 bits:5..19 msb:20 м/кв.с)
   uint16_t                 ins_true_pu_k;               //!< [ИНС-А012] Путевой угол истинный (для командира и навигатора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_true_pu_p;               //!< [ИНС-А012] Путевой угол истинный (для помощника и оператора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_magn_pu_k;               //!< [ИНС-А013] Путевой угол магнитный (для командира и навигатора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_magn_pu_p;               //!< [ИНС-А013] Путевой угол магнитный (для помощника и оператора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_magn_course_k;           //!< [ИНС-А014] Курс магнитный (для командира и навигатора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_magn_course_p;           //!< [ИНС-А014] Курс магнитный (для помощника и оператора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_true_course_k;           //!< [ИНС-А015] Курс истинный (для командира и навигатора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ins_true_course_p;           //!< [ИНС-А015] Курс истинный (для помощника и оператора) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ans_true_course;             //!< [АНС-А003] Курс истинный //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                 ans_roll;                    //!< [АНС-А004] Угол крена //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                 ans_pitch;                   //!< [АНС-А005] Угол тангажа //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                 svs_true_speed_k;            //!< [СВС-А011] Скорость воздушная истинная (для командира и навигатора) //(min:0 max:3500 signed:4 bits:5..19 msb:1896.448 км/ч)
   uint16_t                 svs_true_speed_p;            //!< [СВС-А011] Скорость воздушная истинная (для помощника и оператора) //(min:0 max:3500 signed:4 bits:5..19 msb:1896.448 км/ч)
   dv_valid_word_1_b_t      dv_valid_word_1_b[DV_COUNT]; //!< Слово 1 достоверностей ДВ
} mfci_in_sa_4_b_t;

//! Входное сообщение МФЦИ, подадрес 5 МКИО-3.1 (25 Гц, данные используются в кадрах ДВ/С, ДВ, КПИ)
typedef struct mfci_in_sa_5_b_t {
   dv_valid_word_2_b_t dv_valid_word_2_b[DV_COUNT]; //!< Слово 2 достоверностей ДВ
   dv_valid_word_3_b_t dv_valid_word_3_b[DV_COUNT]; //!< Слово 3 достоверностей ДВ
   dv_valid_word_4_b_t dv_valid_word_4_b;           //!< Слово 4 достоверностей ДВ
   dv_flag_word_1_b_t  dv_flag_word_1_b;            //!< Слово 1 сигналов ДВ
   dv_flag_word_2_b_t  dv_flag_word_2_b;            //!< Слово 2 сигналов ДВ
   uint16_t            dv_start_time_1;             //!< [ДВ-А001] Время запуска двигателя (байты 0-1) //(min:0 max:240 signed:12 bits:11..1 msb:204.8 с)
   uint16_t            dv_start_time_2;             //!< [ДВ-А001] Время запуска двигателя (байты 2-3) //(min:0 max:240 signed:12 bits:11..1 msb:204.8 с)
   uint16_t            dv_start_time_3;             //!< [ДВ-А001] Время запуска двигателя (байты 4-6) //(min:0 max:240 signed:12 bits:11..1 msb:204.8 с)
   uint16_t            dv_rud_ud_k_1;               //!< [ДВ-А004] Положение РУД (от УД, для командира и навигатора, байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:204.8°)
   uint16_t            dv_rud_ud_k_2;               //!< [ДВ-А004] Положение РУД (от УД, для командира и навигатора, байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:204.8°)
   uint16_t            dv_rud_ud_k_3;               //!< [ДВ-А004] Положение РУД (от УД, для командира и навигатора, байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:204.8°)
   uint16_t            dv_rud_ud_p_1;               //!< [ДВ-А004] Положение РУД (от УД, для помощника и оператора, байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:204.8°)
   uint16_t            dv_rud_ud_p_2;               //!< [ДВ-А004] Положение РУД (от УД, для помощника и оператора, байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:204.8°)
   uint16_t            dv_rud_ud_p_3;               //!< [ДВ-А004] Положение РУД (от УД, для помощника и оператора, байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:204.8°)
   uint16_t            dv_rud_sku_k_1;              //!< [ДВ-А005] Положение РУД (от СКУ, для командира и навигатора, байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t            dv_rud_sku_k_2;              //!< [ДВ-А005] Положение РУД (от СКУ, для командира и навигатора, байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t            dv_rud_sku_k_3;              //!< [ДВ-А005] Положение РУД (от СКУ, для командира и навигатора, байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t            dv_rud_sku_p_1;              //!< [ДВ-А005] Положение РУД (от СКУ, для помощника и оператора, байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t            dv_rud_sku_p_2;              //!< [ДВ-А005] Положение РУД (от СКУ, для помощника и оператора, байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t            dv_rud_sku_p_3;              //!< [ДВ-А005] Положение РУД (от СКУ, для помощника и оператора, байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t            dv_n2_k_1;                   //!< [ДВ-А006] Значение оборотов ротора ВД (для командира и навигатора, байты 0-1) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t            dv_n2_k_2;                   //!< [ДВ-А006] Значение оборотов ротора ВД (для командира и навигатора, байты 2-3) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t            dv_n2_k_3;                   //!< [ДВ-А006] Значение оборотов ротора ВД (для командира и навигатора, байты 4-6) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t            dv_n2_p_1;                   //!< [ДВ-А006] Значение оборотов ротора ВД (для помощника и оператора, байты 0-1) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t            dv_n2_p_2;                   //!< [ДВ-А006] Значение оборотов ротора ВД (для помощника и оператора, байты 2-3) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t            dv_n2_p_3;                   //!< [ДВ-А006] Значение оборотов ротора ВД (для помощника и оператора, байты 4-6) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
} mfci_in_sa_5_b_t;

//! Входное сообщение МФЦИ, подадрес 6 МКИО-3.1 (25 Гц, данные используются в кадрах ДВ/С, ДВ)
typedef struct mfci_in_sa_6_b_t {
   dv_flag_word_3_b_t dv_flag_word_3_b;         //!< Слово 3 сигналов ДВ
   dv_flag_word_4_b_t dv_flag_word_4_b;         //!< Слово 4 сигналов ДВ
   uint16_t           dv_n1_ud_k_1;             //!< [ДВ-А008] Значение оборотов ротора НД (от УД, для командира и навигатора, байты 0-1) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_ud_k_2;             //!< [ДВ-А008] Значение оборотов ротора НД (от УД, для командира и навигатора, байты 2-3) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_ud_k_3;             //!< [ДВ-А008] Значение оборотов ротора НД (от УД, для командира и навигатора, байты 4-6) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_ud_p_1;             //!< [ДВ-А008] Значение оборотов ротора НД (от УД, для помощника и оператора, байты 0-1) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_ud_p_2;             //!< [ДВ-А008] Значение оборотов ротора НД (от УД, для помощника и оператора, байты 2-3) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_ud_p_3;             //!< [ДВ-А008] Значение оборотов ротора НД (от УД, для помощника и оператора, байты 4-6) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_sku_k_1;            //!< [ДВ-А009] Значение оборотов ротора НД (от СКУ, для командира и навигатора, байты 0-1) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_sku_k_2;            //!< [ДВ-А009] Значение оборотов ротора НД (от СКУ, для командира и навигатора, байты 2-3) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_sku_k_3;            //!< [ДВ-А009] Значение оборотов ротора НД (от СКУ, для командира и навигатора, байты 4-6) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_sku_p_1;            //!< [ДВ-А009] Значение оборотов ротора НД (от СКУ, для помощника и оператора, байты 0-1) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_sku_p_2;            //!< [ДВ-А009] Значение оборотов ротора НД (от СКУ, для помощника и оператора, байты 2-3) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n1_sku_p_3;            //!< [ДВ-А009] Значение оборотов ротора НД (от СКУ, для помощника и оператора, байты 4-6) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n_sd_k_1;              //!< [ДВ-А017] Значение оборотов ротора СД (для командира и навигатора, байты 0-1) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n_sd_k_2;              //!< [ДВ-А017] Значение оборотов ротора СД (для командира и навигатора, байты 2-3) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n_sd_k_3;              //!< [ДВ-А017] Значение оборотов ротора СД (для командира и навигатора, байты 4-6) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n_sd_p_1;              //!< [ДВ-А017] Значение оборотов ротора СД (для помощника и оператора, байты 0-1) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n_sd_p_2;              //!< [ДВ-А017] Значение оборотов ротора СД (для помощника и оператора, байты 2-3) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_n_sd_p_3;              //!< [ДВ-А017] Значение оборотов ротора СД (для помощника и оператора, байты 4-6) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t           dv_tg_ud_1;               //!< [ДВ-А012] Температура газа в турбине (от УД, байты 0-1) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t           dv_tg_ud_2;               //!< [ДВ-А012] Температура газа в турбине (от УД, байты 2-3) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t           dv_tg_ud_3;               //!< [ДВ-А012] Температура газа в турбине (от УД, байты 4-6) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t           dv_tg_sku_1;              //!< [ДВ-А013] Температура газа в турбине (от СКУ, байты 0-1) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t           dv_tg_sku_2;              //!< [ДВ-А013] Температура газа в турбине (от СКУ, байты 2-3) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t           dv_tg_sku_3;              //!< [ДВ-А013] Температура газа в турбине (от СКУ, байты 4-6) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t           dv_inlet_wedge_angle_1;   //!< [ДВ-А019] Положение панелей клина ВЗ (байты 0-1) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t           dv_inlet_wedge_angle_2;   //!< [ДВ-А019] Положение панелей клина ВЗ (байты 2-3) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t           dv_inlet_wedge_angle_3;   //!< [ДВ-А019] Положение панелей клина ВЗ (байты 4-6) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t           dv_inlet_restart_angle_1; //!< [ДВ-А020] Положение створки перепуска ВЗ (байты 0-1) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t           dv_inlet_restart_angle_2; //!< [ДВ-А020] Положение створки перепуска ВЗ (байты 2-3) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t           dv_inlet_restart_angle_3; //!< [ДВ-А020] Положение створки перепуска ВЗ (байты 4-6) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
} mfci_in_sa_6_b_t;

//! Входное сообщение МФЦИ, подадрес 7 МКИО-3.1 (12.5 Гц, данные используются в кадрах ДВ/С, ДВ)
typedef struct mfci_in_sa_7_b_t {
   uint16_t dv1_afterburn_time_land;   //!< [ДВ1-А002] Оставшееся время работы форсажа на взлете //(min:0 max:300 signed:4 bits:5..18 msb:8192 с)
   uint16_t dv1_afterburn_time_in_air; //!< [ДВ1-А003] Оставшееся время работы форсажа в полете //(min:0 max:1800 signed:4 bits:5..18 msb:8192 с)
   uint16_t dv_n2_max_danger_1;        //!< [ДВ-А007] Опасное значение оборотов ротора ВД (байты 0-1) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n2_max_danger_2;        //!< [ДВ-А007] Опасное значение оборотов ротора ВД (байты 2-3) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n2_max_danger_3;        //!< [ДВ-А007] Опасное значение оборотов ротора ВД (байты 4-6) //(min:0 max:13000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n1_max_danger_1;        //!< [ДВ-А010] Опасное значение оборотов ротора НД (байты 0-1) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n1_max_danger_2;        //!< [ДВ-А010] Опасное значение оборотов ротора НД (байты 2-3) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n1_max_danger_3;        //!< [ДВ-А010] Опасное значение оборотов ротора НД (байты 4-6) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n1_max_1;               //!< [ДВ-А036] Предельное значение оборотов ротора НД (байты 0-1) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n1_max_2;               //!< [ДВ-А036] Предельное значение оборотов ротора НД (байты 2-3) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n1_max_3;               //!< [ДВ-А036] Предельное значение оборотов ротора НД (байты 4-6) //(min:0 max:7000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n_sd_max_1;             //!< [ДВ-А018] Предельное значение оборотов ротора СД (байты 0-1) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n_sd_max_2;             //!< [ДВ-А018] Предельное значение оборотов ротора СД (байты 2-3) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_n_sd_max_3;             //!< [ДВ-А018] Предельное значение оборотов ротора СД (байты 4-6) //(min:0 max:10000 signed:12 bits:11..1 msb:8192 об/мин)
   uint16_t dv_tg_max_danger_ud_1;     //!< [ДВ-А014] Опасная температура газа в турбине (байты 0-1) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_danger_ud_2;     //!< [ДВ-А014] Опасная температура газа в турбине (байты 2-3) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_danger_ud_3;     //!< [ДВ-А014] Опасная температура газа в турбине (байты 4-6) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_danger_sku_1;    //!< [ДВ-А045] Опасная температура газа в турбине (байты 0-1) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_danger_sku_2;    //!< [ДВ-А045] Опасная температура газа в турбине (байты 2-3) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_danger_sku_3;    //!< [ДВ-А045] Опасная температура газа в турбине (байты 4-6) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_1;               //!< [ДВ-А015] Повышенная температура газа в турбине (байты 0-1) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_2;               //!< [ДВ-А015] Повышенная температура газа в турбине (байты 2-3) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_tg_max_3;               //!< [ДВ-А015] Повышенная температура газа в турбине (байты 4-6) //(min:-60 max:900 signed:12 bits:11..1 msb:819.2°С)
   uint16_t dv_vibration_vpo_1;        //!< [ДВ-А021] Вибрация передней опоры (байты 0-1) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vpo_2;        //!< [ДВ-А021] Вибрация передней опоры (байты 2-3) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vpo_3;        //!< [ДВ-А021] Вибрация передней опоры (байты 4-6) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vot_1;        //!< [ДВ-А022] Вибрация опоры турбины (байты 0-1) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vot_2;        //!< [ДВ-А022] Вибрация опоры турбины (байты 2-3) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vot_3;        //!< [ДВ-А022] Вибрация опоры турбины (байты 4-6) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vfk_1;        //!< [ДВ-А023] Вибрация форсажной камеры (байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vfk_2;        //!< [ДВ-А023] Вибрация форсажной камеры (байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vfk_3;        //!< [ДВ-А023] Вибрация форсажной камеры (байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:102.4 мм/с)
} mfci_in_sa_7_b_t;

//! Входное сообщение МФЦИ, подадрес 8 МКИО-3.1 (12.5 Гц, данные используются в кадре ДВ/С, ДВ)
typedef struct mfci_in_sa_8_b_t {
   uint16_t dv2_afterburn_time_land;      //!< [ДВ2-А002] Оставшееся время работы форсажа на взлете //(min:0 max:300 signed:4 bits:5..18 msb:8192 с)
   uint16_t dv2_afterburn_time_in_air;    //!< [ДВ2-А003] Оставшееся время работы форсажа в полете //(min:0 max:1800 signed:4 bits:5..18 msb:8192 с)
   uint16_t dv_vibration_vpo_max_1;       //!< [ДВ-А024] Повышенная вибрация передней опоры (байты 0-1) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vpo_max_2;       //!< [ДВ-А024] Повышенная вибрация передней опоры (байты 2-3) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vpo_max_3;       //!< [ДВ-А024] Повышенная вибрация передней опоры (байты 4-6) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vot_max_1;       //!< [ДВ-А025] Повышенная вибрация опоры турбины (байты 0-1) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vot_max_2;       //!< [ДВ-А025] Повышенная вибрация опоры турбины (байты 2-3) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vot_max_3;       //!< [ДВ-А025] Повышенная вибрация опоры турбины (байты 4-6) //(min:0 max:100 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vfk_max_1;       //!< [ДВ-А026] Повышенная вибрация форсажной камеры (байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vfk_max_2;       //!< [ДВ-А026] Повышенная вибрация форсажной камеры (байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_vibration_vfk_max_3;       //!< [ДВ-А026] Повышенная вибрация форсажной камеры (байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:102.4 мм/с)
   uint16_t dv_oil_pressure_1;            //!< [ДВ-А027] Давление масла на входе в двигатель (байты 0-1) //(min:0 max:8 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_oil_pressure_2;            //!< [ДВ-А027] Давление масла на входе в двигатель (байты 2-3) //(min:0 max:8 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_oil_pressure_3;            //!< [ДВ-А027] Давление масла на входе в двигатель (байты 4-6) //(min:0 max:8 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_oil_pressure_min_1;        //!< [ДВ-А028] Пониженное давление масла на входе в двигатель (байты 0-1) //(min:0 max:8 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_oil_pressure_min_2;        //!< [ДВ-А028] Пониженное давление масла на входе в двигатель (байты 2-3) //(min:0 max:8 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_oil_pressure_min_3;        //!< [ДВ-А028] Пониженное давление масла на входе в двигатель (байты 4-6) //(min:0 max:8 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_oil_temperature_in_1;      //!< [ДВ-А030] Температура масла на входе в двигатель (байты 0-1) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_in_2;      //!< [ДВ-А030] Температура масла на входе в двигатель (байты 2-3) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_in_3;      //!< [ДВ-А030] Температура масла на входе в двигатель (байты 4-6) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_in_max_1;  //!< [ДВ-А031] Повышенная температура масла на входе в двигатель (байты 0-1) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_in_max_2;  //!< [ДВ-А031] Повышенная температура масла на входе в двигатель (байты 2-3) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_in_max_3;  //!< [ДВ-А031] Повышенная температура масла на входе в двигатель (байты 4-6) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_out_1;     //!< [ДВ-А032] Температура масла на выходе из опоры турбины (байты 0-1) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_out_2;     //!< [ДВ-А032] Температура масла на выходе из опоры турбины (байты 2-3) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_out_3;     //!< [ДВ-А032] Температура масла на выходе из опоры турбины (байты 4-6) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_out_max_1; //!< [ДВ-А033] Повышенная температура масла на выходе из опоры турбины (байты 0-1) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_out_max_2; //!< [ДВ-А033] Повышенная температура масла на выходе из опоры турбины (байты 2-3) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_temperature_out_max_3; //!< [ДВ-А033] Повышенная температура масла на выходе из опоры турбины (байты 4-6) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_nozzle_angle_1;            //!< [ДВ-А034] Положение реактивного сопла (байты 0-1) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t dv_nozzle_angle_2;            //!< [ДВ-А034] Положение реактивного сопла (байты 2-3) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
   uint16_t dv_nozzle_angle_3;            //!< [ДВ-А034] Положение реактивного сопла (байты 4-6) //(min:0 max:180 signed:12 bits:11..1 msb:102.4°)
} mfci_in_sa_8_b_t;

//! Входное сообщение МФЦИ, подадрес 9 МКИО-3.1 (12.5 Гц, данные используются в кадрах ДВ/С, ДВ)
typedef struct mfci_in_sa_9_b_t {
   uint16_t dv3_afterburn_time_land;     //!< [ДВ3-А002] Оставшееся время работы форсажа на взлете //(min:0 max:300 signed:4 bits:5..18 msb:8192 с)
   uint16_t dv3_afterburn_time_in_air;   //!< [ДВ3-А003] Оставшееся время работы форсажа в полете //(min:0 max:1800 signed:4 bits:5..18 msb:8192 с)
   uint16_t dv_air_pressure_turb_1;      //!< [ДВ-А035] Давление в объединенной полости опор турбины (байты 0-1) //(min:0 max:2.5 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_air_pressure_turb_2;      //!< [ДВ-А035] Давление в объединенной полости опор турбины (байты 2-3) //(min:0 max:2.5 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_air_pressure_turb_3;      //!< [ДВ-А035] Давление в объединенной полости опор турбины (байты 4-6) //(min:0 max:2.5 signed:12 bits:11..2 msb:5.12 кгс/кв.см)
   uint16_t dv_bearing_temperature_n1_1; //!< [ДВ-А037] Температура подшипников ротора НД (байты 0-1) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_n1_2; //!< [ДВ-А037] Температура подшипников ротора НД (байты 2-3) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_n1_3; //!< [ДВ-А037] Температура подшипников ротора НД (байты 4-6) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_sd_1; //!< [ДВ-А038] Температура подшипников ротора CД (байты 0-1) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_sd_2; //!< [ДВ-А038] Температура подшипников ротора CД (байты 2-3) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_sd_3; //!< [ДВ-А038] Температура подшипников ротора CД (байты 4-6) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_n2_1; //!< [ДВ-А039] Температура подшипников ротора ВД (байты 0-1) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_n2_2; //!< [ДВ-А039] Температура подшипников ротора ВД (байты 2-3) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_bearing_temperature_n2_3; //!< [ДВ-А039] Температура подшипников ротора ВД (байты 4-6) //(min:-60 max:300 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_oil_level_1;              //!< [ДВ-А040] Количество масла в маслобаке (байты 0-1) //(min:0 max:60 signed:12 bits:11..2 msb:51.2 л)
   uint16_t dv_oil_level_2;              //!< [ДВ-А040] Количество масла в маслобаке (байты 2-3) //(min:0 max:60 signed:12 bits:11..2 msb:51.2 л)
   uint16_t dv_oil_level_3;              //!< [ДВ-А040] Количество масла в маслобаке (байты 4-6) //(min:0 max:60 signed:12 bits:11..2 msb:51.2 л)
   uint16_t dv_oil_level_min_1;          //!< [ДВ-А041] Пониженное количество масла в маслобаке (байты 0-1) //(min:0 max:51.1 bits:11..3 msb:25.6 л)
   uint16_t dv_oil_level_min_2;          //!< [ДВ-А041] Пониженное количество масла в маслобаке (байты 2-3) //(min:0 max:51.1 bits:11..3 msb:25.6 л)
   uint16_t dv_oil_level_min_3;          //!< [ДВ-А041] Пониженное количество масла в маслобаке (байты 4-6) //(min:0 max:51.1 bits:11..3 msb:25.6 л)
   uint16_t dv_oil_level_max_1;          //!< [ДВ-А042] Предельное количество масла в маслобаке (байты 0-1) //(min:0 max:51.1 bits:11..3 msb:25.6 л)
   uint16_t dv_oil_level_max_2;          //!< [ДВ-А042] Предельное количество масла в маслобаке (байты 2-3) //(min:0 max:51.1 bits:11..3 msb:25.6 л)
   uint16_t dv_oil_level_max_3;          //!< [ДВ-А042] Предельное количество масла в маслобаке (байты 4-6) //(min:0 max:51.1 bits:11..3 msb:25.6 л)
   uint16_t dv_fuel_pressure_1;          //!< [ДВ-А043] Давление топлива перед форсунками основной КС (байты 0-1) //(min:0 max:100 signed:12 bits:11..2 msb:51.2 кгс/кв.см)
   uint16_t dv_fuel_pressure_2;          //!< [ДВ-А043] Давление топлива перед форсунками основной КС (байты 2-3) //(min:0 max:100 signed:12 bits:11..2 msb:51.2 кгс/кв.см)
   uint16_t dv_fuel_pressure_3;          //!< [ДВ-А043] Давление топлива перед форсунками основной КС (байты 4-6) //(min:0 max:100 signed:12 bits:11..2 msb:51.2 кгс/кв.см)
   uint16_t dv_fuel_temperature_tmt_1;   //!< [ДВ-А044] Температура топлива за ТМТ (байты 0-1, байты 0-1) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_fuel_temperature_tmt_2;   //!< [ДВ-А044] Температура топлива за ТМТ (байты 2-3, байты 2-3) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_fuel_temperature_tmt_3;   //!< [ДВ-А044] Температура топлива за ТМТ (байты 4-6, байты 4-6) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_air_temperature_1;        //!< [ДВ-А048/ДВ-А049] Температура воздуха на входе в ДВ/ВЗ (байты 0-1) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_air_temperature_2;        //!< [ДВ-А048/ДВ-А049] Температура воздуха на входе в ДВ/ВЗ (байты 2-3) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
   uint16_t dv_air_temperature_3;        //!< [ДВ-А048/ДВ-А049] Температура воздуха на входе в ДВ/ВЗ (байты 4-6) //(min:-60 max:250 signed:12 bits:11..1 msb:204.8°С)
} mfci_in_sa_9_b_t;

//! Входное сообщение МФЦИ, подадрес 10 МКИО-3.1 (12.5 Гц, данные используются в кадрах КПИ, ПНП, ПЛАН, КАРТ, СУО, ГРУП, ДВ/С, ДВ)
typedef struct mfci_in_sa_10_b_t {
   uint16_t            dv4_afterburn_time_land;      //!< [ДВ4-А002] Оставшееся время работы форсажа на взлете //(min:0 max:300 signed:4 bits:5..18 msb:8192 с)
   uint16_t            dv4_afterburn_time_in_air;    //!< [ДВ4-А003] Оставшееся время работы форсажа в полете //(min:0 max:1800 signed:4 bits:5..18 msb:8192 с)
   uint16_t            dv_inlet_wedge_angle_set_1;   //!< [ДВ-А046] Программное положение клина (байты 0-1) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t            dv_inlet_wedge_angle_set_2;   //!< [ДВ-А046] Программное положение клина (байты 2-3) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t            dv_inlet_wedge_angle_set_3;   //!< [ДВ-А046] Программное положение клина (байты 4-6) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t            dv_inlet_restart_angle_set_1; //!< [ДВ-А047] Программное положение створки (байты 0-1) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t            dv_inlet_restart_angle_set_2; //!< [ДВ-А047] Программное положение створки (байты 2-3) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t            dv_inlet_restart_angle_set_3; //!< [ДВ-А047] Программное положение створки (байты 4-6) //(min:-30 max:30 signed:12 bits:11..3 msb:25.6°)
   uint16_t            ans_latitude_high;            //!< [АНС-А001] Географическая широта местоположения объекта, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t            ans_latitude_low;             //!< [АНС-А001] Географическая широта местоположения объекта, младшее слово
   uint16_t            ans_longitude_high;           //!< [АНС-А002] Географическая долгота местоположения объекта, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t            ans_longitude_low;            //!< [АНС-А002] Географическая долгота местоположения объекта, младшее слово
   uint16_t            ans_w;                        //!< [АНС-А006] Путевая скорость //(min:0 max:972.22222222 signed:4 bits:5..19 msb:1054 м/с)
   uint16_t            ins_latitude_k_high;          //!< [ИНС-А010] Географическая широта местоположения объекта (для командира и навигатора), старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t            ins_latitude_k_low;           //!< [ИНС-А010] Географическая широта местоположения объекта (для командира и навигатора), младшее слово
   uint16_t            ins_latitude_p_high;          //!< [ИНС-А010] Географическая широта местоположения объекта (для помощника и оператора), старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t            ins_latitude_p_low;           //!< [ИНС-А010] Географическая широта местоположения объекта (для помощника и оператора), младшее слово
   uint16_t            ins_longitude_k_high;         //!< [ИНС-А011] Географическая долгота местоположения объекта (для командира и навигатора), старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t            ins_longitude_k_low;          //!< [ИНС-А011] Географическая долгота местоположения объекта (для командира и навигатора), младшее слово
   uint16_t            ins_longitude_p_high;         //!< [ИНС-А011] Географическая долгота местоположения объекта (для помощника и оператора), старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t            ins_longitude_p_low;          //!< [ИНС-А011] Географическая долгота местоположения объекта (для помощника и оператора), младшее слово
   uint16_t            ins_drift_angle;              //!< [ИНС-А016] Угол сноса //(min:-30 max:30 signed:4 bits:5..19 msb:90°)
   sau_flag_word_2_b_t sau_flag_word_2_b;            //!< Слово 2 сигналов САУ
   sau_flag_word_3_b_t sau_flag_word_3_b;            //!< Слово 3 сигналов САУ
   uint16_t            sau_altitude_selected;        //!< [САУ-А004] Заданная барометрическая высота //(min:100 max:20000 signed:4 bits:5..19 msb:9987.7 м)
   uint16_t            sau_speed_selected;           //!< [САУ-А005] Заданная приборная скорость //(min:180 max:1600 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t            sau_vy_selected;              //!< [САУ-А006] Заданная вертикальная скорость //(min:-30 max:30 signed:4 bits:5..19 msb:41.615 м/с)
   uint16_t            sau_mach_selected;            //!< [САУ-А007] Заданное число Маха //(min:0.4 max:2.5 signed:4 bits:5..19 msb:2.048)
   uint16_t            sau_path_angle_selected;      //!< [САУ-А008] Заданный угол наклона траектории //(min:-30 max:30 signed:4 bits:5..19 msb:51.2°)
   uint16_t            svs_pressure_qnh;             //!< [СВС-А006] Барокоррекция QNH (ДДК, 4…7р - х100, 8…11р - х10, 12…15р - х1, 16…19р - х0.1 мм.рт.ст) //(min:407 max:812)
   uint16_t            svs_pressure_qfe;             //!< [СВС-А007] Барокоррекция QFE (ДДК, 4…7р - х100, 8…11р - х10, 12…15р - х1, 16…19р - х0.1 мм.рт.ст) //(min:407 max:812)
   uint16_t            svs_temperature;              //!< [СВС-А010] Температура наружного воздуха //(min:-99 max:60 signed:4 bits:5..15 msb:256°С)
} mfci_in_sa_10_b_t;

//! Входное сообщение МФЦИ, подадрес 11 МКИО-3.1 (12.5 Гц, передается постоянно)
typedef struct mfci_in_sa_11_b_t {
   pui_valid_word_b_t    pui_valid_word_b;        //!< Слово достоверностей ПУИ
   pui_flag_word_1_b_t   pui_flag_word_1_b;       //!< Слово 1 сигналов ПУИ
   pui_flag_word_2_b_t   pui_flag_word_2_b;       //!< Слово 2 сигналов ПУИ
   pui_flag_word_3_b_t   pui_flag_word_3_b;       //!< Слово 3 сигналов ПУИ
   pui_flag_word_4_b_t   pui_flag_word_4_b;       //!< Слово 4 сигналов ПУИ
   pkr_flag_word_b_t     pkr_flag_word_b;         //!< Слово сигналов ПКР
   sau_flag_word_1_b_t   sau_flag_word_1_b;       //!< Слово 1 сигналов САУ
   topl_valid_word_1_b_t topl_valid_word_1_b;     //!< Слово 1 достоверностей ТОПЛ
   topl_valid_word_2_b_t topl_valid_word_2_b;     //!< Слово 2 достоверностей ТОПЛ
   uint16_t              mup1_x;                  //!< [МУП1-А001] Положение рукоятки МУП 1 по координате x (6…15р - значение в прямом коде, 16р - знак) //(min:-1023 max:1023 signed:16 bits:6..15 lsb:1)
   uint16_t              mup2_x;                  //!< [МУП2-А001] Положение рукоятки МУП 2 по координате x (6…15р - значение в прямом коде, 16р - знак) //(min:-1023 max:1023 signed:16 bits:6..15 lsb:1)
   uint16_t              mup1_y;                  //!< [МУП1-А002] Положение рукоятки МУП 1 по координате y (4…13р - значение в прямом коде, 14р - знак) //(min:-1023 max:1023 signed:14 bits:4..13 lsb:1)
   uint16_t              mup2_y;                  //!< [МУП2-А002] Положение рукоятки МУП 2 по координате y (4…13р - значение в прямом коде, 14р - знак) //(min:-1023 max:1023 signed:14 bits:4..13 lsb:1)
   uint16_t              pui_vpr;                 //!< [ПУИ-А001] Высота принятия решения/высота опасная //(min:0 max:1500 bits:5..17 lsb:1 м)
   uint16_t              pui_mvs;                 //!< [ПУИ-А002] Минимальная высота снижения //(min:0 max:6000 bits:5..17 lsb:1 м)
   uint16_t              pui_vpr_edited;          //!< [ПУИ-А003] Высота принятия решения/высота опасная выставляемая //(min:0 max:1500 bits:5..17 lsb:1 м)
   uint16_t              pui_mvs_edited;          //!< [ПУИ-А004] Минимальная высота снижения выставляемая //(min:0 max:6000 bits:5..17 lsb:1 м)
   uint16_t              pui_pressure_qnh_edited; //!< [ПУИ-А005] Барокоррекция QNH выставляемая (ДДК, 4…7р - х100, 8…11р - х10, 12…15р - х1, 16…19р - х0.1 мм.рт.ст) //(min:407 max:812)
   uint16_t              pui_pressure_qfe_edited; //!< [ПУИ-А006] Барокоррекция QFE выставляемая (ДДК, 4…7р - х100, 8…11р - х10, 12…15р - х1, 16…19р - х0.1 мм.рт.ст) //(min:407 max:812)
   uint16_t              ark_frequency;           //!< [АРК-А002] Частота настройки АРК (ДДК, 4…6р - х1000, 7…10р - х100, 11…14р - х10, 15…18р - х1, 19р - х0.5 кГц) //(min:150 max:1750)
   uint16_t              rsbn_distance;           //!< [РСБН-А004] Дальность самолета от РСБН //(min:0 max:500 signed:4 bits:5..19 msb:250 км)
   uint16_t              rsbn_azimuth;            //!< [РСБН-А005] Азимут на маяк РСБН истинный //(min:-180 max:180, signed:4 bits:5..19 msb:90°)
   uint16_t              rsbn_channel_number_np;  //!< [РСБН-А006] Номер частотно-кодового канала РСБН НП (ДДК, 5р - х100, 6…9р - х10, 10…13р - х1, 15р - х1000) //(min:1 max:1176)
   uint16_t              rsbn_channel_number_ms;  //!< [РСБН-А006] Номер частотно-кодового канала РСБН МС (ДДК, 5р - х100, 6…9р - х10, 10…13р - х1, 15р - х1000) //(min:1 max:28)
   uint16_t              rsbn_distance_ms;        //!< [РСБН-А008] Дальность до взаимодействующего ЛА //(min:0 max:500 signed:4 bits:5..19 msb:250 км)
   uint16_t              topl_fuel_total;         //!< [ТОПЛ-А004] Общее количество топлива по всем бакам //(min:0 max:175000 signed:4 bits:5..19 msb:131072 кг)
   uint16_t              topl_weight;             //!< [ТОПЛ-А019] Суммарная масса самолета //(min:50 max:275 signed:4 bits:5..13 msb:256 т)
   rap_flag_word_b_t     rap_flag_word_b;         //!< Слово сигналов РЭП
} mfci_in_sa_11_b_t;

//! Входное сообщение МФЦИ, подадрес 12 МКИО-3.1 (12.5 Гц, данные используются в кадрах КПИ, ПНП, ПЛАН, КАРТ, СУО, УПР)
typedef struct mfci_in_sa_12_b_t {
   bcvm_flag_words_2_3_b_t bcvm_flag_words_2_3_b;  //!< Слова 2-3 сигналов БЦВМ
   bcvm_flag_words_4_5_b_t bcvm_flag_words_4_5_b;  //!< Слова 4-5 сигналов БЦВМ
   bcvm_flag_words_6_7_b_t bcvm_flag_words_6_7_b;  //!< Слова 6-7 сигналов БЦВМ
   pkr_valid_word_b_t      pkr_valid_word_b;       //!< Слово достоверностей ПКР
   uint16_t                pkr_speed_max;          //!< [ПКР-А001] Максимально допустимая приборная скорость //(min:0 max:1200 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                pkr_speed_min;          //!< [ПКР-А002] Минимально допустимая приборная скорость //(min:0 max:850 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                pkr_roll_max;           //!< [ПКР-А003] Допустимый угол крена //(min:-60 max:60 signed:4 bits:5..19 msb:90°)
   uint16_t                pkr_ny_max;             //!< [ПКР-А004] Максимально допустимая нормальная перегрузка //(min:0 max:3 signed:4 bits:5..19 msb:2g)
   uint16_t                pkr_ny_min;             //!< [ПКР-А005] Минимально допустимая нормальная перегрузка //(min:-0.1 max:0.5 signed:4 bits:5..19 msb:2g)
   uint16_t                pkr_alpha_max;          //!< [ПКР-А006] Максимально допустимый угол атаки //(min:1 max:30 signed:4 bits:5..19 msb:90°)
   uint16_t                pkr_alpha_min;          //!< [ПКР-А007] Минимально допустимый угол атаки //(min:-3 max:0 signed:4 bits:5..19 msb:90°)
   uint16_t                pkr_path_angle_pot;     //!< [ПКР-А008] Потенциальный угол наклона траектории //(min:-15 max:30 signed:4 bits:5..19 msb:90°)
   uint16_t                pkr_path_angle;         //!< [ПКР-А009] Угол наклона траектории //(min:-15 max:30 signed:4 bits:5..19 msb:90°)
   uint16_t                pkr_mach_max;           //!< [ПКР-А010] Максимально допустимое число Маха //(min:0 max:3 signed:4 bits:5..19 msb:2.048)
   uint16_t                vim_vor1_azimuth;       //!< [VIM-А001] Азимут на маяк VOR1 магнитный //(min:-180 max:180 signed:4 bits:5..15 msb:90°)
   uint16_t                vim_vor1_frequency;     //!< [VIM-А002] Частота настройки на маяк VOR1 (ДДК, 4…6р - х10, 7…10р - х1, 11…14р - х0.1, 15…18р - х0.01 МГц) //(min:108 max:117.95)
   uint16_t                vim_vor2_azimuth;       //!< [VIM-А003] Азимут на маяк VOR2 магнитный //(min:-180 max:180 signed:4 bits:5..15 msb:90°)
   uint16_t                vim_vor2_frequency;     //!< [VIM-А004] Частота настройки на маяк VOR2 (ДДК, 4…6р - х10, 7…10р - х1, 11…14р - х0.1, 15…18р - х0.01 МГц) //(min:108 max:117.95)
   uint16_t                vim_ils1_frequency;     //!< [VIM-А005] Частота настройки ILS1 (ДДК, 4…6р - х10, 7…10р - х1, 11…14р - х0.1, 15…18р - х0.01 МГц) //(min:108.1 max:111.95)
   uint16_t                vim_ils2_frequency;     //!< [VIM-А005] Частота настройки ILS2 (ДДК, 4…6р - х10, 7…10р - х1, 11…14р - х0.1, 15…18р - х0.01 МГц) //(min:108.1 max:111.95)
   uint16_t                dme1_distance;          //!< [DME-А001] Дальность до радиомаяка DME1 //(min:0 max:500 bits:4..19 msb:474.112 км)
   uint16_t                dme1_frequency;         //!< [DME-А002] Частота настройки радиомаяка DME1 (ДДК, 4…6р - х10, 7…10р - х1, 11…14р - х0.1, 15р - х0.05 МГц) //(min:108 max:117.95)
   uint16_t                dme2_distance;          //!< [DME-А003] Дальность до радиомаяка DME2 //(min:0 max:500 bits:4..19 msb:474.112 км)
   uint16_t                dme2_frequency;         //!< [DME-А004] Частота настройки радиомаяка DME2 (ДДК, 4…6р - х10, 7…10р - х1, 11…14р - х0.1, 15р - х0.05 МГц) //(min:108 max:117.95)
   uint16_t                bcvm_magn_pu_selected;  //!< [БЦВМ-А005] Магнитный заданный путевой угол или заданный курс //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                bcvm_delta_z;           //!< [БЦВМ-А008] Линейное боковое уклонение от ЛЗП //(min:-237 max:237 signed:4 bits:5..19 msb:120 км)
   uint16_t                bcvm_waypoint_distance; //!< [БЦВМ-А010] Расстояние до очередного ППМ //(min:0 max:3276.7 signed:4 bits:5..19 msb:1638.4 км)
   uint16_t                bcvm_azimuth_selected;  //!< [БЦВМ-А012] Азимут заданный VOR магнитный или РСБН истинный //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                bcvm_echelon;           //!< [БЦВМ-А013] Высота эшелона //(min:0 max:30000 signed:4 bits:5..19 lsb:1 м)
} mfci_in_sa_12_b_t;

//! Входное сообщение МФЦИ, подадрес 13 МКИО-3.1 (12.5 Гц, данные используются в кадрах КПИ, ПНП, ПЛАН, КАРТ, СУО)
typedef struct mfci_in_sa_13_b_t {
   uint16_t                bcvm_altitude_delta;       //!< [БЦВМ-А014] Отклонение от заданной высоты полета //(min:-15000 max:15000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                bcvm_runway_course;        //!< [БЦВМ-А015] Курс ВПП //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                bcvm_v1_continued;         //!< [БЦВМ-А016] Скорость принятия решения на разбеге V1 (продолженная) //(min:0 max:390 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                bcvm_v1;                   //!< [БЦВМ-А017] Скорость принятия решения на разбеге V1 (прерванная) //(min:0 max:390 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                bcvm_altitude_min;         //!< [БЦВМ-А021] Минимально безопасная высота //(min:0 max:5000 signed:4 bits:5..19 msb:8192 м)
   uint16_t                bcvm_wind_angle;           //!< [БЦВМ-А022] Направление ветра метеорологическое //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                bcvm_wind_speed;           //!< [БЦВМ-А023] Скорость ветра //(min:0 max:83.33333333 signed:4 bits:5..19 msb:55.55 м/с)
   uint16_t                bcvm_w;                    //!< [БЦВМ-А024] Путевая скорость //(min:0 max:972.22222222 signed:4 bits:5..19 msb:1054 м/с)
   uint16_t                bcvm_fuel_distance;        //!< [БЦВМ-А025] Расстояние, оставшееся по запасу топлива //(min:0 max:32767 bits:4..19 lsb:1 км)
   uint16_t                bcvm_azimuth_delta;        //!< [БЦВМ-А027] Отклонение от линии заданного азимута VOR/РСБН //(min:-10 max:10 signed:4 bits:5..19 msb:90°)
   mfci_text_word_b_t      bcvm_waypoint_name_1_b;    //!< [БЦВМ-А029] Идентификатор очередного ППМ, слово 1 (символы 1-2)
   mfci_text_word_b_t      bcvm_waypoint_name_2_b;    //!< [БЦВМ-А029] Идентификатор очередного ППМ, слово 2 (символы 3-4)
   mfci_text_word_b_t      bcvm_waypoint_name_3_b;    //!< [БЦВМ-А029] Идентификатор очередного ППМ, слово 3 (символы 5-6)
   uint16_t                bcvm_latitude_high;        //!< [БЦВМ-А030] Географическая широта местоположения объекта, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                bcvm_latitude_low;         //!< [БЦВМ-А030] Географическая широта местоположения объекта, младшее слово
   uint16_t                bcvm_longitude_high;       //!< [БЦВМ-А031] Географическая долгота местоположения объекта, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                bcvm_longitude_low;        //!< [БЦВМ-А031] Географическая долгота местоположения объекта, младшее слово
   uint16_t                bcvm_declination;          //!< [БЦВМ-А037] Магнитное склонение //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                bcvm_dtmsa;                //!< [БЦВМ-А039] Отклонение от стандарта атмосферы по температуре //(min:-90 max:90 signed:4 bits:5..19 msb:256°С)
   uint16_t                bcvm_true_pu_selected;     //!< [БЦВМ-А040] Истинный заданный путевой угол или заданный курс //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                bcvm_landing_speed_40;     //!< [БЦВМ-А041] Скорость снижения по глиссаде с закрылками 40° //(min:0 max:370 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                bcvm_landing_speed_25;     //!< [БЦВМ-А042] Скорость снижения по глиссаде с закрылками 25° //(min:0 max:460 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                bcvm_runway_orto_s;        //!< [БЦВМ-А043] Ортодромическая дальность до торца ВПП взлета/посадки //(min:-327.67 max:327.67 signed:4 bits:5..19 lsb:0.01 км)
   uint16_t                bcvm_runway_orto_z;        //!< [БЦВМ-А044] Боковое отклонения от прямой выхода на торец ВПП взлета/посадки //(min:-327.67 max:327.67 signed:4 bits:5..19 lsb:0.01 км)
   uint16_t                bcvm_speed_correction;     //!< [БЦВМ-А046] Изменение скорости при выходе в заданную точку в заданное время //(min:-999 max:999 signed:4 bits:5..19 lsb:1 км/ч)
   uint16_t                bcvm_redundant_time;       //!< [БЦВМ-А047] Изменение времени при выходе в заданную точку в заданное время //(min:-3599 max:3599 signed:4 bits:5..19 lsb:1 с)
   uint16_t                bcvm_takeoff_run;          //!< [БЦВМ-А048] Потребная длина разбега на взлете //(min:1000 max:6000 bits:4..19 lsb:1 м)
   sns_flag_valid_word_b_t sns_flag_valid_word_b;     //!< Слово сигналов и достоверностей СНС
   uint16_t                sns_latitude_high;         //!< [СНС-А003] Географическая широта местоположения, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:90°)
   uint16_t                sns_latitude_low;          //!< [СНС-А003] Географическая широта местоположения, младшее слово
   uint16_t                sns_longitude_high;        //!< [СНС-А004] Географическая долгота местоположения, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                sns_longitude_low;         //!< [СНС-А004] Географическая долгота местоположения, младшее слово
} mfci_in_sa_13_b_t;

//! Входное сообщение МФЦИ, подадрес 14 МКИО-3.1 (12.5 Гц, данные используются в кадрах КПИ, ПНП, РЛС, ГРУП)
typedef struct mfci_in_sa_14_b_t {
   uint16_t                   sns_delta_x;                //!< [СНС-А001] Отклонение от курса посадки //(min:-0.4 max:0.4 signed:4 bits:5..16 msb:0.2 РГМ)
   uint16_t                   sns_delta_y;                //!< [СНС-А002] Отклонение от глиссады снижения //(min:-0.8 max:0.8 signed:4 bits:5..16 msb:0.4 РГМ)
   uint16_t                   sns_distance;               //!< [СНС-А005] Горизонтальная дальность до порога ВПП посадки //(min:0 max:524.288 bits:4..19 msb:262.144 км)
   uint16_t                   sns_channel_num;            //!< [СНС-А006] Код частотного канала //(min:20001 max:39999 bits:4..16 lsb:1)
   rls_flag_word_b_t          rls_flag_word_b;            //!< [РЛС] Слово сигналов РЛС
   uint16_t                   rls_scale;                  //!< [РЛС] Размер масштаба //(min:1 max:1228.8 bits:4..19 msb:614.4)
   uint16_t                   rls_true_course;            //!< [РЛС] Курс истинный (входной параметр НВ70М) //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                   rls_latitude_high;          //!< [РЛС] Географическая широта местоположения объекта (входной параметр НВ70М), старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:90°)
   uint16_t                   rls_latitude_low;           //!< [РЛС] Географическая широта местоположения объекта (входной параметр НВ70М), младшее слово
   uint16_t                   rls_longitude_high;         //!< [РЛС] Географическая долгота местоположения объекта (входной параметр НВ70М), старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                   rls_longitude_low;          //!< [РЛС] Географическая долгота местоположения объекта (входной параметр НВ70М), младшее слово
   group_flag_word_1_b_t      group_flag_word_1_b;        //!< [ФПО НО] Слово 1 сигналов ФПО НО с данными ударных групп
   uint16_t                   group_selected_elevation;   //!< [ФПО НО-А093] Заданное превышение dh между своим и впререди летящим самолетом //(min:-2000 max:2000 signed:4 bits:5..19 lsb:0.1 м)
   uint16_t                   group_selected_distance_z;  //!< [ФПО НО-А094] Заданный интервал i между своим и впререди летящим самолетом //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t                   group_selected_distance_x;  //!< [ФПО НО-А095] Заданная дистанция d между своим и впререди летящим самолетом //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   group_aircraft_numbers_b_t group_aircraft_numbers_b;   //!< [ФПО НО] Номера самолетов ударных групп, информация о которых передается
   uint16_t                   group_aircraft_a_angle;     //!< [ФПО НО-А033 … ФПО НО-А047] Курсовой угол КУ самолета 1…15 ударных групп //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                   group_aircraft_a_distance;  //!< [ФПО НО-А063 … ФПО НО-А077] Дальность D до самолета 1…15 ударных групп //(min:0 max:20000 bits:4..19 lsb:1 м)
   uint16_t                   group_aircraft_a_callsign;  //!< [ФПО НО-А001 … ФПО НО-А015] Позывной самолета 1…15 ударных групп //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t                   group_aircraft_a_elevation; //!< [ФПО НО-А078 … ФПО НО-А092] Превышение dh самолета 1…15 ударных групп //(min:-2000 max:2000 signed:4 bits:5..19 lsb:0.1 м)
   uint16_t                   group_aircraft_b_angle;     //!< [ФПО НО-А033 … ФПО НО-А047] Курсовой угол КУ самолета 1…15 ударных групп //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                   group_aircraft_b_distance;  //!< [ФПО НО-А063 … ФПО НО-А077] Дальность D до самолета 1…15 ударных групп //(min:0 max:20000 bits:4..19 lsb:1 м)
   uint16_t                   group_aircraft_b_callsign;  //!< [ФПО НО-А001 … ФПО НО-А015] Позывной самолета 1…15 ударных групп //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t                   group_aircraft_b_elevation; //!< [ФПО НО-А078 … ФПО НО-А092] Превышение dh самолета 1…15 ударных групп //(min:-2000 max:2000 signed:4 bits:5..19 lsb:0.1 м)
   uint16_t                   group_aircraft_c_angle;     //!< [ФПО НО-А033 … ФПО НО-А047] Курсовой угол КУ самолета 1…15 ударных групп //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                   group_aircraft_c_distance;  //!< [ФПО НО-А063 … ФПО НО-А077] Дальность D до самолета 1…15 ударных групп //(min:0 max:20000 bits:4..19 lsb:1 м)
   uint16_t                   group_aircraft_c_callsign;  //!< [ФПО НО-А001 … ФПО НО-А015] Позывной самолета 1…15 ударных групп //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t                   group_aircraft_c_elevation; //!< [ФПО НО-А078 … ФПО НО-А092] Превышение dh самолета 1…15 ударных групп //(min:-2000 max:2000 signed:4 bits:5..19 lsb:0.1 м)
   uint16_t                   group_aircraft_d_angle;     //!< [ФПО НО-А033 … ФПО НО-А047] Курсовой угол КУ самолета 1…15 ударных групп //(min:0 max:360 signed:4 bits:5..19 msb:180°)
   uint16_t                   group_aircraft_d_distance;  //!< [ФПО НО-А063 … ФПО НО-А077] Дальность D до самолета 1…15 ударных групп //(min:0 max:20000 bits:4..19 lsb:1 м)
   uint16_t                   group_aircraft_d_callsign;  //!< [ФПО НО-А001 … ФПО НО-А015] Позывной самолета 1…15 ударных групп //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t                   group_aircraft_d_elevation; //!< [ФПО НО-А078 … ФПО НО-А092] Превышение dh самолета 1…15 ударных групп //(min:-2000 max:2000 signed:4 bits:5..19 lsb:0.1 м)
} mfci_in_sa_14_b_t;

//! Входное сообщение МФЦИ, подадрес 15 МКИО-3.1 (12.5 Гц, данные используются в кадре ГРУП)
typedef struct mfci_in_sa_15_b_t {
   group_flag_word_2_b_t group_flag_word_2_b;          //!< [ФПО НО] Слово 2 сигналов ФПО НО с данными ударных групп
   group_flag_word_3_b_t group_flag_word_3_b;          //!< [ФПО НО] Слово 3 сигналов ФПО НО с данными ударных групп
   uint16_t              group_aircraft_01_distance_x; //!< [ФПО НО-А018] Дистанция d до самолета 1 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_02_distance_x; //!< [ФПО НО-А019] Дистанция d до самолета 2 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_03_distance_x; //!< [ФПО НО-А020] Дистанция d до самолета 3 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_04_distance_x; //!< [ФПО НО-А021] Дистанция d до самолета 4 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_05_distance_x; //!< [ФПО НО-А022] Дистанция d до самолета 5 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_06_distance_x; //!< [ФПО НО-А023] Дистанция d до самолета 6 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_07_distance_x; //!< [ФПО НО-А024] Дистанция d до самолета 7 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_08_distance_x; //!< [ФПО НО-А025] Дистанция d до самолета 8 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_09_distance_x; //!< [ФПО НО-А026] Дистанция d до самолета 9 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_10_distance_x; //!< [ФПО НО-А027] Дистанция d до самолета 10 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_11_distance_x; //!< [ФПО НО-А028] Дистанция d до самолета 11 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_12_distance_x; //!< [ФПО НО-А029] Дистанция d до самолета 12 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_13_distance_x; //!< [ФПО НО-А030] Дистанция d до самолета 13 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_14_distance_x; //!< [ФПО НО-А031] Дистанция d до самолета 14 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_15_distance_x; //!< [ФПО НО-А032] Дистанция d до самолета 15 ударных групп //(min:-20000 max:20000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_01_distance_z; //!< [ФПО НО-А048] Интервал i между собственным самолетом и самолетом 1 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_02_distance_z; //!< [ФПО НО-А049] Интервал i между собственным самолетом и самолетом 2 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_03_distance_z; //!< [ФПО НО-А050] Интервал i между собственным самолетом и самолетом 3 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_04_distance_z; //!< [ФПО НО-А051] Интервал i между собственным самолетом и самолетом 4 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_05_distance_z; //!< [ФПО НО-А052] Интервал i между собственным самолетом и самолетом 5 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_06_distance_z; //!< [ФПО НО-А053] Интервал i между собственным самолетом и самолетом 6 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_07_distance_z; //!< [ФПО НО-А054] Интервал i между собственным самолетом и самолетом 7 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_08_distance_z; //!< [ФПО НО-А055] Интервал i между собственным самолетом и самолетом 8 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_09_distance_z; //!< [ФПО НО-А056] Интервал i между собственным самолетом и самолетом 9 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_10_distance_z; //!< [ФПО НО-А057] Интервал i между собственным самолетом и самолетом 10 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_11_distance_z; //!< [ФПО НО-А058] Интервал i между собственным самолетом и самолетом 11 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_12_distance_z; //!< [ФПО НО-А059] Интервал i между собственным самолетом и самолетом 12 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_13_distance_z; //!< [ФПО НО-А060] Интервал i между собственным самолетом и самолетом 13 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_14_distance_z; //!< [ФПО НО-А061] Интервал i между собственным самолетом и самолетом 14 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
   uint16_t              group_aircraft_15_distance_z; //!< [ФПО НО-А062] Интервал i между собственным самолетом и самолетом 15 ударных групп //(min:-1000 max:1000 signed:4 bits:5..19 lsb:1 м)
} mfci_in_sa_15_b_t;

//! Входное сообщение МФЦИ, подадрес 16 МКИО-3.1 (12.5 Гц, данные используются в кадре РЭП)
typedef struct mfci_in_sa_16_b_t {
   uint16_t rap_course;                //!< [РЭП-А001, РЭП-А014] Курс, подкадр (БОУ-500 п/а 3 СД 1)
   uint16_t rap_uv_fire_name_1;        //!< [РЭП-А020, РЭП-А021] Название установленной программы отстрела на УВ (БОУ-500 п/а 3 СД 2)
   uint16_t rap_uv_fire_name_2;        //!< [РЭП-А022, РЭП-А023] Название установленной программы отстрела на УВ (БОУ-500 п/а 3 СД 3)
   uint16_t rap_uv_fire_name_recom_1;  //!< [РЭП А024, РЭП-А025] Название рекомендуемой программы отстрела на УВ (БОУ-500 п/а 3 СД 4)
   uint16_t rap_uv_fire_name_recom_2;  //!< [РЭП А026, РЭП-А027] Название рекомендуемой программы отстрела на УВ (БОУ-500 п/а 3 СД 5)
   uint16_t rap_uv_attacks_count;      //!< [РЭП-А006, РЭП-А011] Количество оставшихся атак и целей О (БОУ-500 п/а 3 СД 6)
   uint16_t rap_altitude_km;           //!< [РЭП-А005, РЭП-А009] Высота, время контроля, признаки Пр-СЕКТ и Пр-ЗП (БОУ-500 п/а 3 СД 7)
   uint16_t rap_oes_subtypes;          //!< [РЭП-А002, РЭП-А003] Полусфера НОЦ, маневр (БОУ-500 п/а 3 СД 8)
   uint16_t rap_oes_1;                 //!< [РЭП-А261, РЭП-А273] Данные цели ОЭС 1 (БОУ-500 п/а 3 СД 9)
   uint16_t rap_oes_2;                 //!< [РЭП-А262, РЭП-А274] Данные цели ОЭС 2 (БОУ-500 п/а 3 СД 10)
   uint16_t rap_oes_3;                 //!< [РЭП-А263, РЭП-А275] Данные цели ОЭС 3 (БОУ-500 п/а 3 СД 11)
   uint16_t rap_oes_4;                 //!< [РЭП-А264, РЭП-А276] Данные цели ОЭС 4 (БОУ-500 п/а 3 СД 12)
   uint16_t rap_oes_5;                 //!< [РЭП-А265, РЭП-А277] Данные цели ОЭС 5 (БОУ-500 п/а 3 СД 13)
   uint16_t rap_oes_6;                 //!< [РЭП-А266, РЭП-А278] Данные цели ОЭС 6 (БОУ-500 п/а 3 СД 14)
   uint16_t rap_units_statuses;        //!< [РЭП-А030…РЭП-А033] Состояние изделий 1-2 (ОЭС и ЛСП, БОУ-500 п/а 3 СД 15)
   uint16_t rap_uv_status;             //!< [РЭП-А017…РЭП-А019] Состояние УВ, признаки (БОУ-500 п/а 3 СД 16)
   uint16_t rap_rtr_rap_statuses;      //!< [РЭП-А040…РЭП-А053] Состояние исправности РТР ПРМ и РЭП ПРД (БОУ-500 п/а 3 СД 17)
   uint16_t rap_ric_1_damaging_range;  //!< [РЭП-А301] Дальность поражения цели РИЦ 1 (БОУ-500 п/а 3 СД 18) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_2_damaging_range;  //!< [РЭП-А302] Дальность поражения цели РИЦ 2 (БОУ-500 п/а 3 СД 19) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_3_damaging_range;  //!< [РЭП-А303] Дальность поражения цели РИЦ 3 (БОУ-500 п/а 3 СД 20) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_4_damaging_range;  //!< [РЭП-А304] Дальность поражения цели РИЦ 4 (БОУ-500 п/а 3 СД 21) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_5_damaging_range;  //!< [РЭП-А305] Дальность поражения цели РИЦ 5 (БОУ-500 п/а 3 СД 22) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_6_damaging_range;  //!< [РЭП-А306] Дальность поражения цели РИЦ 6 (БОУ-500 п/а 3 СД 23) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_7_damaging_range;  //!< [РЭП-А307] Дальность поражения цели РИЦ 7 (БОУ-500 п/а 3 СД 24) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_8_damaging_range;  //!< [РЭП-А308] Дальность поражения цели РИЦ 8 (БОУ-500 п/а 3 СД 25) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_9_damaging_range;  //!< [РЭП-А309] Дальность поражения цели РИЦ 9 (БОУ-500 п/а 3 СД 26) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_10_damaging_range; //!< [РЭП-А310] Дальность поражения цели РИЦ 10 (БОУ-500 п/а 3 СД 27) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_11_damaging_range; //!< [РЭП-А311] Дальность поражения цели РИЦ 11 (БОУ-500 п/а 3 СД 28) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_ric_12_damaging_range; //!< [РЭП-А312] Дальность поражения цели РИЦ 12 (БОУ-500 п/а 3 СД 29) //(min:0 max:1023 bits:5..14 lsb:1 км)
   uint16_t rap_targets_count_sn;      //!< [РЭП-А007, РЭП-А008] Количество принятых целей в режимах С/Н (БОУ-500 п/а 3 СД 30)
   uint16_t rap_ric_show;              //!< [РЭП-Б231…РЭП–Б242] Признаки наличия индикации РИЦ (БОУ-500 п/а 4 СД 1)
   uint16_t rap_ric_flickering;        //!< [РЭП-Б201…РЭП–Б212] Признак мерцания РИЦ (БОУ-500 п/а 4 СД 2)
} mfci_in_sa_16_b_t;

//! Входное сообщение МФЦИ, подадрес 17 МКИО-3.1 (12.5 Гц, данные используются в кадре РЭП)
typedef struct mfci_in_sa_17_b_t {
   uint16_t rap_ric_1_azimuth;     //!< [РЭП-А131, РЭП-А201] Класс, азимут РИЦ 1 (БОУ-500 п/а 4 СД 3)
   uint16_t rap_ric_2_azimuth;     //!< [РЭП-А132, РЭП-А202] Класс, азимут РИЦ 2 (БОУ-500 п/а 4 СД 4)
   uint16_t rap_ric_3_azimuth;     //!< [РЭП-А133, РЭП-А203] Класс, азимут РИЦ 3 (БОУ-500 п/а 4 СД 5)
   uint16_t rap_ric_4_azimuth;     //!< [РЭП-А134, РЭП-А204] Класс, азимут РИЦ 4 (БОУ-500 п/а 4 СД 6)
   uint16_t rap_ric_5_azimuth;     //!< [РЭП-А135, РЭП-А205] Класс, азимут РИЦ 5 (БОУ-500 п/а 4 СД 7)
   uint16_t rap_ric_6_azimuth;     //!< [РЭП-А136, РЭП-А206] Класс, азимут РИЦ 6 (БОУ-500 п/а 4 СД 8)
   uint16_t rap_ric_7_azimuth;     //!< [РЭП-А137, РЭП-А207] Класс, азимут РИЦ 7 (БОУ-500 п/а 4 СД 9)
   uint16_t rap_ric_8_azimuth;     //!< [РЭП-А138, РЭП-А208] Класс, азимут РИЦ 8 (БОУ-500 п/а 4 СД 10)
   uint16_t rap_ric_9_azimuth;     //!< [РЭП-А139, РЭП-А209] Класс, азимут РИЦ 9 (БОУ-500 п/а 4 СД 11)
   uint16_t rap_ric_10_azimuth;    //!< [РЭП-А140, РЭП-А210] Класс, азимут РИЦ 10 (БОУ-500 п/а 4 СД 12)
   uint16_t rap_ric_11_azimuth;    //!< [РЭП-А141, РЭП-А211] Класс, азимут РИЦ 11 (БОУ-500 п/а 4 СД 13)
   uint16_t rap_ric_12_azimuth;    //!< [РЭП-А142, РЭП-А212] Класс, азимут РИЦ 12 (БОУ-500 п/а 4 СД 14)
   uint16_t rap_ric_1_distance;    //!< [РЭП-А101, РЭП-А161] Номер, дальность РИЦ 1 (БОУ-500 п/а 4 СД 15)
   uint16_t rap_ric_2_distance;    //!< [РЭП-А102, РЭП-А162] Номер, дальность РИЦ 2 (БОУ-500 п/а 4 СД 16)
   uint16_t rap_ric_3_distance;    //!< [РЭП-А103, РЭП-А163] Номер, дальность РИЦ 3 (БОУ-500 п/а 4 СД 17)
   uint16_t rap_ric_4_distance;    //!< [РЭП-А104, РЭП-А164] Номер, дальность РИЦ 4 (БОУ-500 п/а 4 СД 18)
   uint16_t rap_ric_5_distance;    //!< [РЭП-А105, РЭП-А165] Номер, дальность РИЦ 5 (БОУ-500 п/а 4 СД 19)
   uint16_t rap_ric_6_distance;    //!< [РЭП-А106, РЭП-А166] Номер, дальность РИЦ 6 (БОУ-500 п/а 4 СД 20)
   uint16_t rap_ric_7_distance;    //!< [РЭП-А107, РЭП-А167] Номер, дальность РИЦ 7 (БОУ-500 п/а 4 СД 21)
   uint16_t rap_ric_8_distance;    //!< [РЭП-А108, РЭП-А168] Номер, дальность РИЦ 8 (БОУ-500 п/а 4 СД 22)
   uint16_t rap_ric_9_distance;    //!< [РЭП-А109, РЭП-А169] Номер, дальность РИЦ 9 (БОУ-500 п/а 4 СД 23)
   uint16_t rap_ric_10_distance;   //!< [РЭП-А110, РЭП-А170] Номер, дальность РИЦ 10 (БОУ-500 п/а 4 СД 24)
   uint16_t rap_ric_11_distance;   //!< [РЭП-А111, РЭП-А171] Номер, дальность РИЦ 11 (БОУ-500 п/а 4 СД 25)
   uint16_t rap_ric_12_distance;   //!< [РЭП-А112, РЭП-А172] Номер, дальность РИЦ 12 (БОУ-500 п/а 4 СД 26)
   uint16_t rap_ric_distance_high; //!< [РЭП-А231…РЭП-А242] Дальности РИЦ, старшие разряды (БОУ-500 п/а 4 СД 27)
   uint16_t rap_ric_vz_noise;      //!< [РЭП-Б121…РЭП–Б132] Признаки помехи в режиме ВЗ (БОУ-500 п/а 4 СД 28)
   uint16_t rap_buttons_word_1;    //!< Слово 1 управления индикацией МФК РЭП (БОУ-500 п/а 5 СД 1)
   uint16_t rap_buttons_word_2;    //!< Слово 2 управления индикацией МФК РЭП (БОУ-500 п/а 5 СД 2)
   uint16_t rap_buttons_word_3;    //!< Слово 3 управления индикацией МФК РЭП (БОУ-500 п/а 5 СД 3)
   uint16_t rap_buttons_word_4;    //!< Слово 4 управления индикацией МФК РЭП (БОУ-500 п/а 5 СД 4)
   uint16_t rap_menu_item_1;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 1 (БОУ-500 п/а 5 СД 5)
   uint16_t rap_menu_item_2;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 2 (БОУ-500 п/а 5 СД 6)
} mfci_in_sa_17_b_t;

//! Входное сообщение МФЦИ, подадрес 18 МКИО-3.1 (12.5 Гц, данные используются в кадре РЭП)
typedef struct mfci_in_sa_18_b_t {
   uint16_t rap_menu_item_3;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 3 (БОУ-500 п/а 5 СД 7)
   uint16_t rap_menu_item_4;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 4 (БОУ-500 п/а 5 СД 8)
   uint16_t rap_menu_item_5;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 5 (БОУ-500 п/а 5 СД 9)
   uint16_t rap_menu_item_6;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 6 (БОУ-500 п/а 5 СД 10)
   uint16_t rap_menu_item_7;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 7 (БОУ-500 п/а 5 СД 11)
   uint16_t rap_menu_item_8;       //!< [РЭП-А501…РЭП-А538] Элемент выбора индицируемых РИЦ 8 (БОУ-500 п/а 5 СД 12)
   uint16_t rap_ivz_flags;         //!< [РЭП-Б521…РЭП-Б528] Признаки необходимости перестроения бортов в режиме ИВЗ (БОУ-500 п/а 5 СД 13)
   uint16_t rap_bsv_version;       //!< [РЭП-А703, РЭП-А704] Версия ПМО БСВ (БОУ-500 п/а 6 СД 1)
   uint16_t rap_bpk_bpro_version;  //!< [РЭП-А705, РЭП-А706] Версия ПМО БПК и БПРО (БОУ-500 п/а 6 СД 2)
   uint16_t rap_bfp_version;       //!< [РЭП-А707, РЭП-А708] Версия ПМО БФП (БОУ-500 п/а 6 СД 3)
   uint16_t rap_bou_version;       //!< [РЭП-А709, РЭП-А710] Версия ПМО БОУ (БОУ-500 п/а 6 СД 4)
   uint16_t rap_bsv_bu_version_1;  //!< [РЭП-А811, РЭП-А812] Версия библиотеки угроз БУ (БОУ-500 п/а 6 СД 5)
   uint16_t rap_bsv_bu_version_2;  //!< [РЭП-А813, РЭП-А814] Версия библиотеки угроз БУ (БОУ-500 п/а 6 СД 6)
   uint16_t rap_bsv_bu_version_3;  //!< [РЭП-А815, РЭП-А816] Версия библиотеки угроз БУ (БОУ-500 п/а 6 СД 7)
   uint16_t rap_bsv_bu_version_4;  //!< [РЭП-А817, РЭП-А818] Версия библиотеки угроз БУ (БОУ-500 п/а 6 СД 8)
   uint16_t rap_bsv_bu_version_5;  //!< [РЭП-А819, РЭП-А820] Версия библиотеки угроз БУ (БОУ-500 п/а 6 СД 9)
   uint16_t rap_bou_status;        //!< [РЭП-А761, РЭП-А762] Состояние БОУ, БСВ (БОУ-500 п/а 6 СД 10)
   uint16_t rap_unit5_status;      //!< [РЭП-А726…РЭП-А731] Состояние изделия 5 / УВ (БОУ-500 п/а 6 СД 11)
   uint16_t rap_bv_status;         //!< [УВ-А025, УВ-А030] Номер и состояние блока выброса БВ (БОУ-500 п/а 6 СД 12)
   uint16_t rap_bv_weapon_types_1; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 1-2 блока выброса БВ (БОУ-500 п/а 6 СД 13)
   uint16_t rap_bv_weapon_types_2; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 3-4 блока выброса БВ (БОУ-500 п/а 6 СД 14)
   uint16_t rap_bv_weapon_types_3; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 5-6 блока выброса БВ (БОУ-500 п/а 6 СД 15)
   uint16_t rap_bv_weapon_types_4; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 7-8 блока выброса БВ (БОУ-500 п/а 6 СД 16)
   uint16_t rap_bv_weapon_types_5; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 9-10 блока выброса БВ (БОУ-500 п/а 6 СД 17)
   uint16_t rap_bv_weapon_types_6; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 11-12 блока выброса БВ (БОУ-500 п/а 6 СД 18)
   uint16_t rap_bv_weapon_types_7; //!< [УВ-А001, УВ-А002] Типы патрона в стволах 13-14 блока выброса БВ (БОУ-500 п/а 6 СД 19)
   uint16_t rap_unit1_status;      //!< [РЭП-А713…РЭП-А719] Состояние изделия 1 / ОЭС (БОУ-500 п/а 6 СД 20)
   uint16_t rap_unit2_status;      //!< [РЭП-А720…РЭП-А725] Состояние изделия 2 / ЛСП  (БОУ-500 п/а 6 СД 21)
   uint16_t rap_rap_kzv_status;    //!< [РЭП-А732…РЭП-А737] Состояние РЭП и КЗВ (БОУ-500 п/а 6 СД 23)
   uint16_t rap_recv_side_status;  //!< [РЭП-А738…РЭП-А743] Состояние левого/правого приемного поста (БОУ-500 п/а 6 СД 24)
   uint16_t rap_recv_rear_status;  //!< [РЭП-А744…РЭП-А746] Состояние заднего приемного поста (БОУ-500 п/а 6 СД 25)
   uint16_t rap_send_side_status;  //!< [РЭП-А747…РЭП-А760] Состояние передающего поста (БОУ-500 п/а 6 СД 26)
} mfci_in_sa_18_b_t;

//! Входное сообщение МФЦИ, подадрес 19 МКИО-3.1 (6.25 Гц, данные используются в кадре СЭС)
typedef struct mfci_in_sa_19_b_t {
   sas_valid_word_1_b_t sas_valid_word_1_b;      //!< Слово 1 достоверностей СЭС
   sas_valid_word_2_b_t sas_valid_word_2_b;      //!< Слово 2 достоверностей СЭС
   sas_valid_word_3_b_t sas_valid_word_3_b;      //!< Слово 3 достоверностей СЭС
   sas_valid_word_4_b_t sas_valid_word_4_b;      //!< Слово 4 достоверностей СЭС
   sas_flag_word_1_b_t  sas_flag_word_1_b;       //!< Слово 1 сигналов СЭС
   sas_flag_word_2_b_t  sas_flag_word_2_b;       //!< Слово 2 сигналов СЭС
   sas_flag_word_3_b_t  sas_flag_word_3_b;       //!< Слово 3 сигналов СЭС
   sas_flag_word_4_b_t  sas_flag_word_4_b;       //!< Слово 4 сигналов СЭС
   uint16_t             sas_115_voltage_gen1_1;  //!< [СЭС-А201] Сеть 115В: Напряжение сети генератора 1, фаза A //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen1_2;  //!< [СЭС-А202] Сеть 115В: Напряжение сети генератора 1, фаза B //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen1_3;  //!< [СЭС-А203] Сеть 115В: Напряжение сети генератора 1, фаза C //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen2_1;  //!< [СЭС-А204] Сеть 115В: Напряжение сети генератора 2, фаза A //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen2_2;  //!< [СЭС-А205] Сеть 115В: Напряжение сети генератора 2, фаза B //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen2_3;  //!< [СЭС-А206] Сеть 115В: Напряжение сети генератора 2, фаза C //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen3_1;  //!< [СЭС-А207] Сеть 115В: Напряжение сети генератора 3, фаза A //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen3_2;  //!< [СЭС-А208] Сеть 115В: Напряжение сети генератора 3, фаза B //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen3_3;  //!< [СЭС-А209] Сеть 115В: Напряжение сети генератора 3, фаза C //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen4_1;  //!< [СЭС-А210] Сеть 115В: Напряжение сети генератора 4, фаза A //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen4_2;  //!< [СЭС-А211] Сеть 115В: Напряжение сети генератора 4, фаза B //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_voltage_gen4_3;  //!< [СЭС-А212] Сеть 115В: Напряжение сети генератора 4, фаза C //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t             sas_115_current_rap_1;   //!< [СЭС-А213] Сеть 115В: Ток РАП, фаза A //(min:0 max:402 signed:4 bits:5..19 msb:201 А)
   uint16_t             sas_115_current_rap_2;   //!< [СЭС-А214] Сеть 115В: Ток РАП, фаза B //(min:0 max:402 signed:4 bits:5..19 msb:201 А)
   uint16_t             sas_115_current_rap_3;   //!< [СЭС-А215] Сеть 115В: Ток РАП, фаза C //(min:0 max:402 signed:4 bits:5..19 msb:201 А)
   uint16_t             sas_115_current_vsu_1;   //!< [СЭС-А216] Сеть 115В: Ток генератора ВСУ, фаза A //(min:0 max:402 signed:4 bits:5..19 msb:201 А)
   uint16_t             sas_115_current_vsu_2;   //!< [СЭС-А217] Сеть 115В: Ток генератора ВСУ, фаза B //(min:0 max:402 signed:4 bits:5..19 msb:201 А)
   uint16_t             sas_115_current_vsu_3;   //!< [СЭС-А218] Сеть 115В: Ток генератора ВСУ, фаза C //(min:0 max:402 signed:4 bits:5..19 msb:201 А)
   uint16_t             sas_115_frequency_gen1;  //!< [СЭС-А219] Сеть 115В: Частота сети генератора 1 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t             sas_115_frequency_gen2;  //!< [СЭС-А220] Сеть 115В: Частота сети генератора 2 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t             sas_115_frequency_gen3;  //!< [СЭС-А221] Сеть 115В: Частота сети генератора 3 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t             sas_115_frequency_gen4;  //!< [СЭС-А222] Сеть 115В: Частота сети генератора 4 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t             sas_115_frequency_emrg1; //!< [СЭС-А229] Сеть 115В: Частота аварийной сети 1 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t             sas_115_frequency_emrg2; //!< [СЭС-А230] Сеть 115В: Частота аварийной сети 2 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
} mfci_in_sa_19_b_t;

//! Входное сообщение МФЦИ, подадрес 20 МКИО-3.1 (6.25 Гц, данные используются в кадре СЭС, СКВ)
typedef struct mfci_in_sa_20_b_t {
   uint16_t               sas_115_voltage_emrg1_1;      //!< [СЭС-А223] Сеть 115В: Напряжение аварийной сети 1, фаза A //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_emrg1_2;      //!< [СЭС-А224] Сеть 115В: Напряжение аварийной сети 1, фаза В //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_emrg1_3;      //!< [СЭС-А225] Сеть 115В: Напряжение аварийной сети 1, фаза С //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_emrg2_1;      //!< [СЭС-А226] Сеть 115В: Напряжение аварийной сети 2, фаза А //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_emrg2_2;      //!< [СЭС-А227] Сеть 115В: Напряжение аварийной сети 2, фаза В //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_emrg2_3;      //!< [СЭС-А228] Сеть 115В: Напряжение аварийной сети 2, фаза С //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_conv1_1;      //!< [СЭС-А231] Сеть 115В: Напряжение на шине преобразователя 1, фаза А //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_conv1_2;      //!< [СЭС-А232] Сеть 115В: Напряжение на шине преобразователя 1, фаза В //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_conv1_3;      //!< [СЭС-А233] Сеть 115В: Напряжение на шине преобразователя 1, фаза С //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_conv3l_1;     //!< [СЭС-А237] Сеть 115В: Напряжение на шине преобразователя 3 левой, фаза А //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_voltage_conv3r_1;     //!< [СЭС-А238] Сеть 115В: Напряжение на шине преобразователя 3 правой, фаза А //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_frequency_conv1;      //!< [СЭС-А239] Сеть 115В: Частота на шине преобразователя 1 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t               sas_115_frequency_conv3;      //!< [СЭС-А241] Сеть 115В: Частота на шине преобразователя 3 //(min:320 max:482 signed:4 bits:5..19 msb:241 Гц)
   uint16_t               sas_115_converter1_voltage;   //!< [СЭС-А242] Сеть 115В: Напряжение преобразователя 1 //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_115_converter3_voltage;   //!< [СЭС-А244] Сеть 115В: Напряжение преобразователя 3 //(min:0 max:142 signed:4 bits:5..19 msb:71 В)
   uint16_t               sas_27_current_battery_rap_1; //!< [СЭС-А301] Сеть 27В: Ток аккумулятора 1, РАП1 //(min:-100 max:602 signed:4 bits:5..19 msb:301 А)
   uint16_t               sas_27_current_battery_rap_2; //!< [СЭС-А302] Сеть 27В: Ток аккумулятора 2, РАП2 //(min:-100 max:602 signed:4 bits:5..19 msb:301 А)
   uint16_t               sas_27_voltage_battery_1;     //!< [СЭС-А303] Сеть 27В: Напряжение аккумулятора 1 //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_voltage_battery_2;     //!< [СЭС-А304] Сеть 27В: Напряжение аккумулятора 2 //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_current_vsu;           //!< [СЭС-А305] Сеть 27В: Ток генератора ВСУ //(min:0 max:702 signed:4 bits:5..19 msb:351 А)
   uint16_t               sas_27_voltage_l_main1;       //!< [СЭС-А308] Сеть 27В: Напряжение шины основной 1 левой сети //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_voltage_l_main2;       //!< [СЭС-А309] Сеть 27В: Напряжение шины основной 2 левой сети //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_voltage_l_emrg1;       //!< [СЭС-А310] Сеть 27В: Напряжение шины аварийной 1 левой сети //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_voltage_r_main1;       //!< [СЭС-А311] Сеть 27В: Напряжение шины основной 1 правой сети //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_voltage_r_main2;       //!< [СЭС-А312] Сеть 27В: Напряжение шины основной 2 правой сети //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   uint16_t               sas_27_voltage_r_emrg2;       //!< [СЭС-А313] Сеть 27В: Напряжение шины аварийной 2 правой сети //(min:0 max:35 signed:4 bits:5..19 msb:17.5 В)
   skv_gs_flag_word_1_b_t skv_gs_flag_word_1_b;         //!< Слово 1 сигналов СКВ/КИСЛ/ГС/МПУ
   uint16_t               skv_temperature_pilots;       //!< [СКВ-А001] Температура в кабине экипажа //(min:-60 max:70 signed:5 bits:13..19 msb:64°С)
   uint16_t               skv_temperature_pgo;          //!< [СКВ-А002] Температура в переднем грузовом отсеке //(min:-60 max:70 signed:5 bits:13..19 msb:64°С)
   uint16_t               skv_temperature_zgo;          //!< [СКВ-А003] Температура в заднем грузовом отсеке //(min:-60 max:70 signed:5 bits:13..19 msb:64°С)
   uint16_t               skv_temperature_zto;          //!< [СКВ-А004] Температура в заднем техническом отсеке //(min:-60 max:70 signed:5 bits:13..19 msb:64°С)
   uint16_t               kisl_pressure;                //!< [КИСЛ-А001/КИСЛ-А002] Давление кислорода (4…11р - значение левого борта, 12…19р - значение правого, ЦСР = 14.81 МПа) //(min:0 max:210)
} mfci_in_sa_20_b_t;

//! Входное сообщение МФЦИ, подадрес 21 МКИО-3.1 (6.25 Гц, данные используются в кадре КПИ, УПР, ДВ/С, ТОПЛ)
typedef struct mfci_in_sa_21_b_t {
   uint16_t                 bcvm_vr;                    //!< [БЦВМ-А018] Скорость начала подъема передней стойки шасси VR //(min:0 max:390 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                 bcvm_v2;                    //!< [БЦВМ-А019] Безопасная скорость на взлете V2 //(min:0 max:400 signed:4 bits:5..19 msb:948.224 км/ч)
   uint16_t                 bcvm_landing_run_tp;        //!< [БЦВМ-А049] Потребная длина пробега при посадке с тормозным парашютом //(min:1000 max:6000 bits:4..19 lsb:1 м)
   uint16_t                 bcvm_landing_run;           //!< [БЦВМ-А050] Потребная длина пробега при посадке без тормозного парашюта //(min:1000 max:6000 bits:4..19 lsb:1 м)
   uint16_t                 bcvm_landing_runway_length; //!< [БЦВМ-А051] Длина ВПП посадки //(min:1000 max:6000 bits:4..19 lsb:1 м)
   uint16_t                 bcvm_takeoff_runway_length; //!< [БЦВМ-А052] Длина ВПП взлета //(min:1000 max:6000 bits:4..19 lsb:1 м)
   absu_flag_word_1_b_t     absu_flag_word_1_b;         //!< Слово 1 сигналов АБСУ
   absu_flag_word_2_b_t     absu_flag_word_2_b;         //!< Слово 2 сигналов АБСУ
   smk_supk_flag_word_1_b_t smk_supk_1_flag_word_1_b;   //!< Слово 1 сигналов СМК/СУПК (канал 1)
   smk_supk_flag_word_1_b_t smk_supk_2_flag_word_1_b;   //!< Слово 1 сигналов СМК/СУПК (канал 2)
   smk_supk_flag_word_2_b_t smk_supk_1_flag_word_2_b;   //!< Слово 2 сигналов СМК/СУПК (канал 1)
   smk_supk_flag_word_2_b_t smk_supk_2_flag_word_2_b;   //!< Слово 2 сигналов СМК/СУПК (канал 2)
   sur_valid_word_b_t       sur_valid_word_b;           //!< Слово достоверностей СУР
   uint16_t                 smk_flap_right;             //!< [СМК-А014] Положение правого закрылка //(min:0 max:40 signed:4 bits:5..14 msb:40°)
   uint16_t                 smk_flap_left;              //!< [СМК-А015] Положение левого закрылка //(min:0 max:40 signed:4 bits:5..14 msb:40°)
   uint16_t                 smk_slat_right;             //!< [СМК-А018] Положение правого предкрылка //(min:0 max:21 signed:4 bits:5..14 msb:40°)
   uint16_t                 smk_slat_left;              //!< [СМК-А019] Положение левого предкрылка //(min:0 max:21 signed:4 bits:5..14 msb:40°)
   uint16_t                 smk_wing_left;              //!< [СМК-А120] Положение левой консоли крыла //(min:20 max:65 signed:4 bits:5..14 msb:40°)
   uint16_t                 smk_wing_right;             //!< [СМК-А121] Положение правой консоли крыла //(min:20 max:65 signed:4 bits:5..14 msb:40°)
   uint16_t                 sur_course_balance;         //!< [СУР-А001] Сигнал балансировки по курсу //(min:-10 max:10 signed:4 bits:5..19 msb:15°)
   uint16_t                 sur_pitch_balance;          //!< [СУР-А002] Суммарный сигнал балансировки по тангажу //(min:-16.5 max:12.25 signed:4 bits:5..19 msb:15°)
   uint16_t                 sur_fin;                    //!< [СУР-А003] Положение киля //(min:-22 max:22 signed:4 bits:5..19 msb:11°)
   uint16_t                 sur_stab;                   //!< [СУР-А004] Положение стабилизатора //(min:-17 max:10 signed:4 bits:5..19 msb:8.5°)
   uint16_t                 sur_interceptor_r12;        //!< [СУР-А006] Положение секции I и II правых интерцепторов //(min:0 max:49 signed:4 bits:5..19 msb:24.5°)
   uint16_t                 sur_interceptor_r34;        //!< [СУР-А007] Положение секции III и IV правых интерцепторов //(min:0 max:49 signed:4 bits:5..19 msb:24.5°)
   uint16_t                 sur_interceptor_r56;        //!< [СУР-А008] Положение секции V и VI правых интерцепторов //(min:0 max:49 signed:4 bits:5..19 msb:24.5°)
   uint16_t                 sur_interceptor_l12;        //!< [СУР-А009] Положение секции I и II левого интерцептора //(min:0 max:49 signed:4 bits:5..19 msb:24.5°)
   uint16_t                 sur_interceptor_l34;        //!< [СУР-А010] Положение секции III и IV левого интерцептора //(min:0 max:49 signed:4 bits:5..19 msb:24.5°)
   uint16_t                 sur_interceptor_l56;        //!< [СУР-А011] Положение секции V и VI левого интерцептора //(min:0 max:м signed:4 bits:5..19 msb:24.5°)
   uint16_t                 sur_flaperon_left;          //!< [СУР-А020] Положение левого флаперона //(min:-15 max:27 signed:4 bits:5..19 msb:13.5°)
   uint16_t                 sur_flaperon_right;         //!< [СУР-А021] Положение правого флаперона //(min:-15 max:27 signed:4 bits:5..19 msb:13.5°)
   uint16_t                 sur_roll_balance;           //!< [СУР-А022] Сигнал балансировки по крену //(min:-12 max:12 signed:4 bits:5..19 msb:8°)
} mfci_in_sa_21_b_t;

//! Входное сообщение МФЦИ, подадрес 22 МКИО-3.1 (6.25 Гц, данные используются в кадрах УПР, ТОПЛ)
typedef struct mfci_in_sa_22_b_t {
   uint16_t              smk_wing;                //!< [СМК-А013] Положение трансмиссии консолей крыла //(min:20 max:65 signed:4 bits:5..14 msb:40°)
   uint16_t              smk_ruk;                 //!< [СМК-А016] Положение рукоятки управления крылом //(min:20 max:65 signed:4 bits:5..14 msb:40°)
   torm_flag_word_1_b_t  torm_flag_word_1_b;      //!< Слово 1 сигналов ТОРМ
   torm_flag_word_2_b_t  torm_flag_word_2_b;      //!< Слово 2 сигналов ТОРМ
   torm_valid_word_b_t   torm_valid_word_b;       //!< Слово достоверностей ТОРМ
   uint16_t              torm_pressure_lf_1;      //!< [ТОРМ-А401] Давление в тормозах передней пары левой тележки, осн. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_lm_1;      //!< [ТОРМ-А402] Давление в тормозах средней пары левой тележки, осн. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_lr_1;      //!< [ТОРМ-А403] Давление в тормозах задней пары левой тележки, осн. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_rf_1;      //!< [ТОРМ-А404] Давление в тормозах передней пары правой тележк, осн. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_rm_1;      //!< [ТОРМ-А405] Давление в тормозах средней пары правой тележки, осн. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_rr_1;      //!< [ТОРМ-А406] Давление в тормозах задней пары правой тележки, осн. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_lf_2;      //!< [ТОРМ-А601] Давление в тормозах передней пары левой тележки, рез. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_lm_2;      //!< [ТОРМ-А602] Давление в тормозах средней пары левой тележки, рез. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_lr_2;      //!< [ТОРМ-А603] Давление в тормозах задней пары левой тележки, рез. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_rf_2;      //!< [ТОРМ-А604] Давление в тормозах передней пары правой тележки, рез. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_rm_2;      //!< [ТОРМ-А605] Давление в тормозах средней пары правой тележки, рез. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_rr_2;      //!< [ТОРМ-А606] Давление в тормозах задней пары правой тележки, рез. //(min:0 max:210 signed:4 bits:5..19 msb:105 кгс/кв.см)
   uint16_t              torm_pressure_acc_fluid; //!< [ТОРМ-А607] Давление жидкости в гидроаккумуляторе //(min:0 max:352 signed:4 bits:5..19 msb:176 кгс/кв.см)
   uint16_t              torm_pressure_acc_nitro; //!< [ТОРМ-А608] Давление азота в гидроаккумуляторе //(min:0 max:352 signed:4 bits:5..19 msb:176 кгс/кв.см)
   topl_flag_word_1_b_t  topl_flag_word_1_b;      //!< Слово 1 сигналов ТОПЛ
   topl_flag_word_2_b_t  topl_flag_word_2_b;      //!< Слово 2 сигналов ТОПЛ
   topl_flag_word_3_b_t  topl_flag_word_3_b;      //!< Слово 3 сигналов ТОПЛ
   topl_flag_word_4_b_t  topl_flag_word_4_b;      //!< Слово 4 сигналов ТОПЛ
   topl_flag_word_5_b_t  topl_flag_word_5_b;      //!< Слово 5 сигналов ТОПЛ
   topl_flag_word_6_b_t  topl_flag_word_6_b;      //!< Слово 6 сигналов ТОПЛ
   topl_flag_word_7_b_t  topl_flag_word_7_b;      //!< Слово 7 сигналов ТОПЛ
   topl_flag_word_8_b_t  topl_flag_word_8_b;      //!< Слово 8 сигналов ТОПЛ
   topl_flag_word_9_b_t  topl_flag_word_9_b;      //!< Слово 9 сигналов ТОПЛ
   topl_flag_word_10_b_t topl_flag_word_10_b;     //!< Слово 10 сигналов ТОПЛ
   topl_flag_word_11_b_t topl_flag_word_11_b;     //!< Слово 11 сигналов ТОПЛ
   topl_flag_word_12_b_t topl_flag_word_12_b;     //!< Слово 12 сигналов ТОПЛ
   topl_flag_word_13_b_t topl_flag_word_13_b;     //!< Слово 13 сигналов ТОПЛ
} mfci_in_sa_22_b_t;

//! Входное сообщение МФЦИ, подадрес 23 МКИО-3.1 (6.25 Гц, данные используются в кадрах ТОПЛ, ВСУ)
typedef struct mfci_in_sa_23_b_t {
   topl_flag_word_14_b_t   topl_flag_word_14_b;      //!< Слово 14 сигналов ТОПЛ
   topl_flag_word_15_b_t   topl_flag_word_15_b;      //!< Слово 15 сигналов ТОПЛ
   topl_flag_word_16_b_t   topl_flag_word_16_b;      //!< Слово 16 сигналов ТОПЛ
   uint16_t                topl_fuel_selected;       //!< [ТОПЛ-А001] Значение на задатчике заправки //(min:0 max:999 signed:4 bits:5..14 msb:512 т)
   uint16_t                topl_centering_selected;  //!< [ТОПЛ-А002] Заданная центровка //(min:45 max:65 signed:4 bits:5..18 msb:64 % САХ)
   uint16_t                topl_centering;           //!< [ТОПЛ-А003] Фактическая центровка самолета //(min:45 max:65 signed:4 bits:5..18 msb:64 % САХ)
   uint16_t                topl_fuel_1l;             //!< [ТОПЛ-А005] Количество топлива в баке Б1Л //(min:0 max:18200 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_1r;             //!< [ТОПЛ-А006] Количество топлива в баке Б1П //(min:0 max:18200 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_2l;             //!< [ТОПЛ-А007] Количество топлива в баке Б2Л //(min:0 max:23500 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_2r;             //!< [ТОПЛ-А008] Количество топлива в баке Б2П //(min:0 max:23500 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_4;              //!< [ТОПЛ-А009] Количество топлива в баке Б4 //(min:0 max:23600 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_3l;             //!< [ТОПЛ-А010] Количество топлива в баке Б3Л //(min:0 max:4550 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_3r;             //!< [ТОПЛ-А011] Количество топлива в баке Б3П //(min:0 max:4550 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_5;              //!< [ТОПЛ-А012] Количество топлива в баке Б5 //(min:0 max:11600 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_6;              //!< [ТОПЛ-А013] Количество топлива в баке Б6 //(min:0 max:11000 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb1;            //!< [ТОПЛ-А014] Количество топлива в баке РБ1 //(min:0 max:4200 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb2;            //!< [ТОПЛ-А015] Количество топлива в баке РБ2 //(min:0 max:3450 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb3;            //!< [ТОПЛ-А016] Количество топлива в баке РБ3 //(min:0 max:3450 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb4;            //!< [ТОПЛ-А017] Количество топлива в баке РБ4 //(min:0 max:4200 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_pressure;       //!< [ТОПЛ-А018] Давление в приемнике топлива (заправки) //(min:0 max:12 signed:4 bits:5..16 msb:64 кгс/кв.см)
   uint16_t                topl_fuel_total_dz_start; //!< [ТОПЛ-А021] Общее запомненное количество топлива по всем бакам в момент начала заправки //(min:0 max:175000 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_3l_reserve;     //!< [ТОПЛ-А022] Запас топлива в резервном отсеке бака Б3Л //(min:0 max:5000 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_3r_reserve;     //!< [ТОПЛ-А023] Запас топлива в резервном отсеке бака Б3П //(min:0 max:5000 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb1_reserve;    //!< [ТОПЛ-А024] Запас топлива в резервном отсеке бака РБ1 //(min:0 max:850 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb2_reserve;    //!< [ТОПЛ-А025] Запас топлива в резервном отсеке бака РБ2 //(min:0 max:1350 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb3_reserve;    //!< [ТОПЛ-А026] Запас топлива в резервном отсеке бака РБ3 //(min:0 max:1350 signed:4 bits:5..19 msb:131072 кг)
   uint16_t                topl_fuel_rb4_reserve;    //!< [ТОПЛ-А027] Запас топлива в резервном отсеке бака РБ4 //(min:0 max:850 signed:4 bits:5..19 msb:131072 кг)
   vsu_flag_valid_word_b_t vsu_flag_valid_word_b;    //!< Слово сигналов и достоверностей ВСУ
   uint16_t                vsu_n;                    //!< [ВСУ-А001] Значение оборотов ротора ВСУ //(min:3 max:110 bits:5..15 msb:102.4 %)
   uint16_t                vsu_n_max_2;              //!< [ВСУ-А002] Предельное значение оборотов ротора ВСУ //(min:3 max:110 bits:5..19 msb:102.4 %)
   uint16_t                vsu_n_max_1;              //!< [ВСУ-А003] Повышенное значение оборотов ротора ВСУ //(min:3 max:110 bits:5..19 msb:102.4 %)
   uint16_t                vsu_tg;                   //!< [ВСУ-А004] Температура газа за турбиной ВСУ //(min:0 max:800 bits:7..15 msb:512°С)
} mfci_in_sa_23_b_t;

//! Входное сообщение МФЦИ, подадрес 24 МКИО-3.1 (6.25 Гц, данные используются в кадре, ВСУ, СКВ, ГС)
typedef struct mfci_in_sa_24_b_t {
   uint16_t               vsu_tg_max_2;            //!< [ВСУ-А005] Предельная температура газа за турбиной ВСУ //(min:0 max:800 bits:7..19 msb:512°С)
   uint16_t               vsu_tg_max_1;            //!< [ВСУ-А007] Повышенная температура газа за турбиной ВСУ //(min:0 max:800 bits:7..19 msb:512°С)
   uint16_t               vsu_oil_temperature;     //!< [ВСУ-А008] Температура масла в маслобаке ВСУ //(min:-50 max:150 signed:0 bits:8..15 msb:128°С)
   uint16_t               vsu_oil_temperature_max; //!< [ВСУ-А009] Повышенная температура масла в маслобаке ВСУ //(min:-50 max:150 signed:7 bits:8..19 msb:128°С)
   skv_gs_flag_word_2_b_t skv_gs_flag_word_2_b;    //!< Слово 2 сигналов СКВ/КИСЛ/ГС/МПУ
   skv_gs_flag_word_3_b_t skv_gs_flag_word_3_b;    //!< Слово 3 сигналов СКВ/КИСЛ/ГС/МПУ
   skv_gs_flag_word_4_b_t skv_gs_flag_word_4_b;    //!< Слово 4 сигналов СКВ/КИСЛ/ГС/МПУ
   skv_gs_flag_word_5_b_t skv_gs_flag_word_5_b;    //!< Слово 5 сигналов СКВ/КИСЛ/ГС/МПУ
   skv_gs_flag_word_6_b_t skv_gs_flag_word_6_b;    //!< Слово 6 сигналов СКВ/КИСЛ/ГС/МПУ
   skv_gs_flag_word_7_b_t skv_gs_flag_word_7_b;    //!< Слово 7 сигналов СКВ/КИСЛ/ГС/МПУ
   uint16_t               gs_pressure_1;           //!< [ГС-А001] Давление в ГС1 //(min:0 max:382 signed:4 bits:5..19 msb:191 кгс/кв.см)
   uint16_t               gs_pressure_2;           //!< [ГС-А002] Давление в ГС2 //(min:0 max:382 signed:4 bits:5..19 msb:191 кгс/кв.см)
   uint16_t               gs_pressure_3;           //!< [ГС-А003] Давление в ГС3 //(min:0 max:382 signed:4 bits:5..19 msb:191 кгс/кв.см)
   uint16_t               gs_pressure_4;           //!< [ГС-А004] Давление в ГС4 //(min:0 max:382 signed:4 bits:5..19 msb:191 кгс/кв.см)
   uint16_t               gs_pressure_acc_1;       //!< [ГС-А005] Давление гидроаккумулятора ГС1 //(min:0 max:352 signed:4 bits:5..19 msb:176 кгс/кв.см)
   uint16_t               gs_pressure_acc_2;       //!< [ГС-А006] Давление гидроаккумулятора ГС2 //(min:0 max:352 signed:4 bits:5..19 msb:176 кгс/кв.см)
   uint16_t               gs_pressure_acc_3;       //!< [ГС-А007] Давление гидроаккумулятора ГС3 //(min:0 max:352 signed:4 bits:5..19 msb:176 кгс/кв.см)
   uint16_t               gs_pressure_acc_4;       //!< [ГС-А008] Давление гидроаккумулятора ГС4 //(min:0 max:352 signed:4 bits:5..19 msb:176 кгс/кв.см)
   uint16_t               gs_oil_level_1;          //!< [ГС-А009] Уровень рабочей жидкости в баке ГС1 //(min:24 max:68 signed:4 bits:5..19 msb:34 л)
   uint16_t               gs_oil_level_2;          //!< [ГС-А010] Уровень рабочей жидкости в баке ГС2 //(min:24 max:68 signed:4 bits:5..19 msb:34 л)
   uint16_t               gs_oil_level_3;          //!< [ГС-А011] Уровень рабочей жидкости в баке ГС3 //(min:24 max:68 signed:4 bits:5..19 msb:34 л)
   uint16_t               gs_oil_level_4;          //!< [ГС-А012] Уровень рабочей жидкости в баке ГС4 //(min:24 max:68 signed:4 bits:5..19 msb:34 л)
   uint16_t               gs_oil_temperature_1;    //!< [ГС-А013] Температура рабочей жидкости в баке ГС1 //(min:-60 max:202 signed:4 bits:5..19 msb:101°С)
   uint16_t               gs_oil_temperature_2;    //!< [ГС-А015] Температура рабочей жидкости в баке ГС2 //(min:-60 max:202 signed:4 bits:5..19 msb:101°С)
   uint16_t               gs_oil_temperature_3;    //!< [ГС-А017] Температура рабочей жидкости в баке ГС3 //(min:-60 max:202 signed:4 bits:5..19 msb:101°С)
   uint16_t               gs_oil_temperature_4;    //!< [ГС-А019] Температура рабочей жидкости в баке ГС4 //(min:-60 max:202 signed:4 bits:5..19 msb:101°С)
   uint16_t               gs_pressure_bulb_1;      //!< [ГС-А021] Давление в баллоне наддува № 1 //(min:0 max:182 signed:4 bits:5..19 msb:91 кгс/кв.см)
   uint16_t               gs_pressure_bulb_2;      //!< [ГС-А022] Давление в баллоне наддува № 2 //(min:0 max:182 signed:4 bits:5..19 msb:91 кгс/кв.см)
   uint16_t               gs_pressure_insuff_1;    //!< [ГС-А023] Давление наддува в баке ГС1 //(min:0 max:8 signed:4 bits:5..19 msb:4 кгс/кв.см)
   uint16_t               gs_pressure_insuff_2;    //!< [ГС-А024] Давление наддува в баке ГС2 //(min:0 max:8 signed:4 bits:5..19 msb:4 кгс/кв.см)
   uint16_t               gs_pressure_insuff_3;    //!< [ГС-А025] Давление наддува в баке ГС3 //(min:0 max:8 signed:4 bits:5..19 msb:4 кгс/кв.см)
   uint16_t               gs_pressure_insuff_4;    //!< [ГС-А026] Давление наддува в баке ГС4 //(min:0 max:8 signed:4 bits:5..19 msb:4 кгс/кв.см)
} mfci_in_sa_24_b_t;

//! Входное сообщение МФЦИ, подадрес 25 МКИО-3.1 (1 Гц, передается постоянно)
typedef struct mfci_in_sa_25_b_t {
   mfci_formats_word_1_b_t    mfci_formats_1_b;                           //!< Слово 1-2 c кадрами МФЦИ 1-4
   mfci_formats_word_2_b_t    mfci_formats_2_b;                           //!< Слово 3-4 c кадрами МФЦИ 5-8
   mfci_formats_word_3_b_t    mfci_formats_3_b;                           //!< Слово 5-6 c кадрами МФЦИ 9-11
   upr_flag_word_common_1_b_t pilot_1_upr_flag_word_1_b;                  //!< Слово сигналов УПР командира корабля
   upr_flag_word_common_2_b_t pilot_1_upr_flag_word_2_b;                  //!< Слово сигналов УПР командира корабля
   upr_flag_word_common_1_b_t pilot_2_upr_flag_word_1_b;                  //!< Слово сигналов УПР помощника командира корабля
   upr_flag_word_common_2_b_t pilot_2_upr_flag_word_2_b;                  //!< Слово сигналов УПР помощника командира корабля
   upr_flag_word_common_1_b_t navigator_upr_flag_word_1_b;                //!< Слово сигналов УПР штурмана-навигатора
   upr_flag_word_common_2_b_t navigator_upr_flag_word_2_b;                //!< Слово сигналов УПР штурмана-навигатора
   upr_flag_word_common_1_b_t operator_upr_flag_word_1_b;                 //!< Слово сигналов УПР штурмана-оператора
   upr_flag_word_common_2_b_t operator_upr_flag_word_2_b;                 //!< Слово сигналов УПР штурмана-оператора
   mfci_sost_reset_b_t        mfci_sost_reset_b;                          //!< Слово с признаками отбоя сигналов СОСТ
   mfci_sign_show_b_t         mfci_sign_show_b;                           //!< Слово с признаками отображения поля СИГН
   uint16_t                   mfpu2_to_mfci_msg1[MFPU_TO_MFCI_MSG1_SIZE]; //!< Сообщение из МФПУ 2 (данные редактируемого объекта плана полета)
   uint16_t                   mfpu3_to_mfci_msg1[MFPU_TO_MFCI_MSG1_SIZE]; //!< Сообщение из МФПУ 3 (данные редактируемого объекта плана полета)
} mfci_in_sa_25_b_t;

//! Входное сообщение МФЦИ c данными кадра СВР (МКИО-3.1, 1 Гц)
typedef struct mfci_in_svr_b_t {
   uint16_t          mfci_format;     //!< Кадр МФЦИ (MFCI_FORMAT_SVR)
   svr_flag_word_b_t svr_flag_word_b; //!< Слово сигналов СВР
   uint16_t          svr_date;        //!< [СВР-А001] Поиск даты (4…10р - год, 11…14р - месяц, 15…19р - день)
   uint16_t          svr_time_high;   //!< [СВР-А002] Поиск времени, старшее слово (4…8р - час, 9…14р - мин)
   uint16_t          svr_time_low;    //!< [СВР-А002] Поиск времени, младшее слово (4…9р - сек)
   uint16_t          svr_event;       //!< [СВР-А003] Номер события записи //(min:1 max:99 bits:4..10 lsb:1)
} mfci_in_svr_b_t;

//! Входное сообщение МФЦИ c данными кадра БАСК (МКИО-3.1, 1 Гц, фрагмент 1)
typedef struct mfci_in_bask_1_b_t {
   uint16_t mfci_format;        //!< Кадр МФЦИ (MFCI_FORMAT_BASK)
   uint16_t reserve;            //!< Резерв
   uint16_t failures_count[10]; //!< [БАСК] Количество текущих отказов в текстах кнопок (БАСК п/а 1 СД 10…19) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t plan_numbers_1;     //!< [БАСК] Номер 1 полетного задания (БАСК п/а 1 СД 25) //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t plan_numbers_2;     //!< [БАСК] Номер 2 полетного задания (БАСК п/а 1 СД 26) //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t plan_numbers_3;     //!< [БАСК] Номер 3 полетного задания (БАСК п/а 1 СД 27) //(min:0 max:999 bits:4..19 lsb:1)
   uint16_t time_test_end_1;    //!< [БАСК] Слово 1 времени окончания контроля (БАСК п/а 1 СД 30)
   uint16_t time_test_end_2;    //!< [БАСК] Слово 2 времени окончания контроля (БАСК п/а 1 СД 31)
   uint16_t time_common_low;    //!< [БАСК] Время и номер (текущее, в заголовке или начала контроля), младшее слово (БАСК п/а 1 СД 32)
} mfci_in_bask_1_b_t;

//! Входное сообщение МФЦИ c данными кадра БАСК (МКИО-3.1, 1 Гц, фрагмент 2)
typedef struct mfci_in_bask_2_b_t {
   uint16_t mfci_format;       //!< Кадр МФЦИ (MFCI_FORMAT_BASK)
   uint16_t page_number;       //!< [БАСК] Текущий номер страницы и идентификатор шаблона кадра БАСК (БАСК п/а 2 СД 2)
   uint16_t pages_count;       //!< [БАСК] Общее количество страниц (БАСК п/а 2 СД 3) //(min:1 max:255 bits:4..13 lsb:1)
   uint16_t headers_id_1;      //!< [БАСК] Слово 1 текста заголовка кадра (БАСК п/а 2 СД 4)
   uint16_t headers_id_2;      //!< [БАСК] Слово 2 текста заголовка кадра (БАСК п/а 2 СД 5)
   uint16_t buttons_state_1;   //!< [БАСК] Слово 1 состояния полей кнопок (БАСК п/а 2 СД 6)
   uint16_t buttons_state_2;   //!< [БАСК] Слово 2 состояния полей кнопок (БАСК п/а 2 СД 7)
   uint16_t hull_number_1;     //!< [БАСК] Слово 1 бортового номера (БАСК п/а 2 СД 8) //(min:0 max:99999999)
   uint16_t hull_number_2;     //!< [БАСК] Слово 2 бортового номера (БАСК п/а 2 СД 9) //(min:0 max:99999999)
   uint16_t flight_1_date;     //!< [БАСК] Дата полета 1 (БАСК п/а 2 СД 10)
   uint16_t flight_1_time;     //!< [БАСК] Время и номер полета 1 (БАСК п/а 2 СД 11)
   uint16_t flight_2_date;     //!< [БАСК] Дата полета 2 (БАСК п/а 2 СД 12)
   uint16_t flight_2_time;     //!< [БАСК] Время и номер полета 2 (БАСК п/а 2 СД 13)
   uint16_t flight_3_date;     //!< [БАСК] Дата полета 3 (БАСК п/а 2 СД 14)
   uint16_t flight_3_time;     //!< [БАСК] Время и номер полета 3 (БАСК п/а 2 СД 15)
   uint16_t flight_4_date;     //!< [БАСК] Дата полета 4 (БАСК п/а 2 СД 16)
   uint16_t flight_4_time;     //!< [БАСК] Время и номер полета 4 (БАСК п/а 2 СД 17)
   uint16_t flight_5_date;     //!< [БАСК] Дата полета 5 (БАСК п/а 2 СД 18)
   uint16_t flight_5_time;     //!< [БАСК] Время и номер полета 5 (БАСК п/а 2 СД 19)
   uint16_t flight_6_date;     //!< [БАСК] Дата полета 6 (БАСК п/а 2 СД 20)
   uint16_t flight_6_time;     //!< [БАСК] Время и номер полета 6 (БАСК п/а 2 СД 21)
   uint16_t button_1_text_id;  //!< [БАСК] Идентификаторы текста кнопки 1 (БАСК п/а 2 СД 22) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_2_text_id;  //!< [БАСК] Идентификаторы текста кнопки 2 (БАСК п/а 2 СД 23) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_3_text_id;  //!< [БАСК] Идентификаторы текста кнопки 3 (БАСК п/а 2 СД 24) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_4_text_id;  //!< [БАСК] Идентификаторы текста кнопки 4 (БАСК п/а 2 СД 25) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_5_text_id;  //!< [БАСК] Идентификаторы текста кнопки 5 (БАСК п/а 2 СД 26) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_6_text_id;  //!< [БАСК] Идентификаторы текста кнопки 6 (БАСК п/а 2 СД 27) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_7_text_id;  //!< [БАСК] Идентификаторы текста кнопки 7 (БАСК п/а 2 СД 28) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_8_text_id;  //!< [БАСК] Идентификаторы текста кнопки 8 (БАСК п/а 2 СД 29) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_9_text_id;  //!< [БАСК] Идентификаторы текста кнопки 9 (БАСК п/а 2 СД 30) //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t button_10_text_id; //!< [БАСК] Идентификаторы текста кнопки 10 (БАСК п/а 2 СД 31) //(min:0 max:65535 bits:4..19 lsb:1)
} mfci_in_bask_2_b_t;

//! Входное сообщение МФЦИ c данными кадра БАСК (МКИО-3.1, 1 Гц, фрагмент 3)
typedef struct mfci_in_bask_3_b_t {
   uint16_t mfci_format;      //!< Кадр МФЦИ (MFCI_FORMAT_BASK)
   uint16_t lines_id[29];     //!< [БАСК] Идентификаторы и атрибуты текстов строк (БАСК п/а 3 СД 2…30) //(min:0 max:65535 bits:4..19
   uint16_t date_common;      //!< [БАСК] Дата (текущая, в заголовке или начала контроля, БАСК п/а 3 СД 31)
   uint16_t time_common_high; //!< [БАСК] Время и номер (текущее, в заголовке или начала контроля), старшее слово (БАСК п/а 3 СД 32)
} mfci_in_bask_3_b_t;

//! Входное сообщение МФЦИ c данными кадра МСПР (МКИО-3.1, 1 Гц, фрагмент 1)
typedef struct mfci_in_msrp_1_b_t {
   uint16_t           mfci_format;          //!< Кадр МФЦИ (MFCI_FORMAT_MSRP)
   uint16_t           reserve;              //!< Резерв
   msrp_flag_word_b_t msrp_flag_word_b;     //!< Слово сигналов МСРП
   uint16_t           message_array_number; //!< Номер фрагмента страницы отчета (номер запрошенного массива отчета, 0-нет данных) //(min:0 max:12 bits:4..19 lsb:1)
   uint16_t           message_array[28];    //!< Фрагмент страницы отчета (считанный массив отчета)
} mfci_in_msrp_1_b_t;

//! Входное сообщение МФЦИ c данными кадра МСПР (МКИО-3.1, 1 Гц, фрагмент 2)
typedef struct mfci_in_msrp_2_b_t {
   uint16_t mfci_format;          //!< Кадр МФЦИ (MFCI_FORMAT_MSRP)
   uint16_t message_array_number; //!< Номер фрагмента страницы отчета (номер запрошенного массива отчета, 0-нет данных) //(min:0 max:12 bits:4..19 lsb:1)
   uint16_t message_array[4];     //!< Фрагмент страницы отчета (считанный массив отчета)
} mfci_in_msrp_2_b_t;

//! Входное сообщение МФЦИ c данными кадра БЛОКИ (МКИО-3.1, 1 Гц, фрагмент 1)
typedef struct mfci_in_blocks_1_b_t {
   uint16_t                              mfci_format;           //!< Кадр МФЦИ (MFCI_FORMAT_BLOCKS)
   mfci_in_blocks_mkio_status_word_b_t   mkio_status_word_b;    //!< Слово состояния МКИО
   mfci_in_blocks_bis_status_word_1_b_t  bis1_status_word_1_b;  //!< Слово 1 состояния БИС 1
   mfci_in_blocks_bis_status_word_2_b_t  bis1_status_word_2_b;  //!< Слово 2 состояния БИС 1
   mfci_in_blocks_bis_status_word_3_b_t  bis1_status_word_3_b;  //!< Слово 3 состояния БИС 1
   mfci_in_blocks_bis_status_word_4_b_t  bis1_status_word_4_b;  //!< Слово 4 состояния БИС 1
   mfci_in_blocks_bis_status_word_5_b_t  bis1_status_word_5_b;  //!< Слово 5 состояния БИС 1
   mfci_in_blocks_bis_status_word_6_b_t  bis1_status_word_6_b;  //!< Слово 6 состояния БИС 1
   mfci_in_blocks_bis_status_word_7_b_t  bis1_status_word_7_b;  //!< Слово 7 состояния БИС 1
   mfci_in_blocks_bis_status_word_8_b_t  bis1_status_word_8_b;  //!< Слово 8 состояния БИС 1
   mfci_in_blocks_bis_status_word_9_b_t  bis1_status_word_9_b;  //!< Слово 9 состояния БИС 1
   mfci_in_blocks_bis_status_word_10_b_t bis1_status_word_10_b; //!< Слово 10 состояния БИС 1
   mfci_in_blocks_bis_status_word_11_b_t bis1_status_word_11_b; //!< Слово 11 состояния БИС 1
   mfci_in_blocks_bis_status_word_12_b_t bis1_status_word_12_b; //!< Слово 12 состояния БИС 1
   mfci_in_blocks_bis_status_word_13_b_t bis1_status_word_13_b; //!< Слово 13 состояния БИС 1
   mfci_in_blocks_bis_status_word_14_b_t bis1_status_word_14_b; //!< Слово 14 состояния БИС 1
   mfci_in_blocks_bis_status_word_15_b_t bis1_status_word_15_b; //!< Слово 15 состояния БИС 1
   mfci_in_blocks_bis_status_word_1_b_t  bis2_status_word_1_b;  //!< Слово 1 состояния БИС 2
   mfci_in_blocks_bis_status_word_2_b_t  bis2_status_word_2_b;  //!< Слово 2 состояния БИС 2
   mfci_in_blocks_bis_status_word_3_b_t  bis2_status_word_3_b;  //!< Слово 3 состояния БИС 2
   mfci_in_blocks_bis_status_word_4_b_t  bis2_status_word_4_b;  //!< Слово 4 состояния БИС 2
   mfci_in_blocks_bis_status_word_5_b_t  bis2_status_word_5_b;  //!< Слово 5 состояния БИС 2
   mfci_in_blocks_bis_status_word_6_b_t  bis2_status_word_6_b;  //!< Слово 6 состояния БИС 2
   mfci_in_blocks_bis_status_word_7_b_t  bis2_status_word_7_b;  //!< Слово 7 состояния БИС 2
   mfci_in_blocks_bis_status_word_8_b_t  bis2_status_word_8_b;  //!< Слово 8 состояния БИС 2
   mfci_in_blocks_bis_status_word_9_b_t  bis2_status_word_9_b;  //!< Слово 9 состояния БИС 2
   mfci_in_blocks_bis_status_word_10_b_t bis2_status_word_10_b; //!< Слово 10 состояния БИС 2
   mfci_in_blocks_bis_status_word_11_b_t bis2_status_word_11_b; //!< Слово 11 состояния БИС 2
   mfci_in_blocks_bis_status_word_12_b_t bis2_status_word_12_b; //!< Слово 12 состояния БИС 2
   mfci_in_blocks_bis_status_word_13_b_t bis2_status_word_13_b; //!< Слово 13 состояния БИС 2
   mfci_in_blocks_bis_status_word_14_b_t bis2_status_word_14_b; //!< Слово 14 состояния БИС 2
   mfci_in_blocks_bis_status_word_15_b_t bis2_status_word_15_b; //!< Слово 15 состояния БИС 2
} mfci_in_blocks_1_b_t;

//! Входное сообщение МФЦИ c данными кадра БЛОКИ (МКИО-3.1, 1 Гц, фрагмент 2)
typedef struct mfci_in_blocks_2_b_t {
   uint16_t                                mfci_format;            //!< Кадр МФЦИ (MFCI_FORMAT_BLOCKS)
   mfci_in_blocks_bis_status_word_16_b_t   bis1_status_word_16_b;  //!< Слово 16 состояния БИС 1
   mfci_in_blocks_bis_status_word_16_b_t   bis2_status_word_16_b;  //!< Слово 16 состояния БИС 2
   mfci_in_blocks_bis_status_word_17_b_t   bis1_status_word_17_b;  //!< Слово 17 состояния БИС 1
   mfci_in_blocks_bis_status_word_17_b_t   bis2_status_word_17_b;  //!< Слово 17 состояния БИС 2
   mfci_in_blocks_bcvm_status_word_1_b_t   bcvm1_status_word_1_b;  //!< Слово 1 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_2_b_t   bcvm1_status_word_2_b;  //!< Слово 2 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_3_b_t   bcvm1_status_word_3_b;  //!< Слово 3 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_4_b_t   bcvm1_status_word_4_b;  //!< Слово 4 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_5_b_t   bcvm1_status_word_5_b;  //!< Слово 5 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_6_b_t   bcvm1_status_word_6_b;  //!< Слово 6 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_7_b_t   bcvm1_status_word_7_b;  //!< Слово 7 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_8_b_t   bcvm1_status_word_8_b;  //!< Слово 8 состояния БЦВМ 1
   mfci_in_blocks_bcvm_status_word_1_b_t   bcvm2_status_word_1_b;  //!< Слово 1 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_2_b_t   bcvm2_status_word_2_b;  //!< Слово 2 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_3_b_t   bcvm2_status_word_3_b;  //!< Слово 3 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_4_b_t   bcvm2_status_word_4_b;  //!< Слово 4 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_5_b_t   bcvm2_status_word_5_b;  //!< Слово 5 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_6_b_t   bcvm2_status_word_6_b;  //!< Слово 6 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_7_b_t   bcvm2_status_word_7_b;  //!< Слово 7 состояния БЦВМ 2
   mfci_in_blocks_bcvm_status_word_8_b_t   bcvm2_status_word_8_b;  //!< Слово 8 состояния БЦВМ 2
   mfci_in_blocks_bvd_status_word_1_b_t    bvd1_status_word_1_b;   //!< Слово 1 состояния БВД 1
   mfci_in_blocks_bvd_status_word_2_b_t    bvd1_status_word_2_b;   //!< Слово 2 состояния БВД 1
   mfci_in_blocks_bvd_status_word_3_b_t    bvd1_status_word_3_b;   //!< Слово 3 состояния БВД 1
   mfci_in_blocks_bvd_status_word_1_b_t    bvd2_status_word_1_b;   //!< Слово 1 состояния БВД 2
   mfci_in_blocks_bvd_status_word_2_b_t    bvd2_status_word_2_b;   //!< Слово 2 состояния БВД 2
   mfci_in_blocks_bvd_status_word_3_b_t    bvd2_status_word_3_b;   //!< Слово 3 состояния БВД 2
   mfci_in_blocks_uks_status_word_b_t      uks_status_word_b;      //!< Слово состояния УКС
   mfci_in_blocks_bgs_status_word_1_b_t    bgs1_status_word_1_b;   //!< Слово 1 состояния БГС 1
   mfci_in_blocks_bgs_status_word_2_b_t    bgs1_status_word_2_b;   //!< Слово 2 состояния БГС 1
   mfci_in_blocks_bgs_status_word_3_b_t    bgs1_status_word_3_b;   //!< Слово 3 состояния БГС 1
} mfci_in_blocks_2_b_t;

//! Входное сообщение МФЦИ c данными кадра БЛОКИ (МКИО-3.1, 1 Гц, фрагмент 3)
typedef struct mfci_in_blocks_3_b_t {
   uint16_t                               mfci_format;           //!< Кадр МФЦИ (MFCI_FORMAT_BLOCKS)
   mfci_in_blocks_bgs_status_word_1_b_t   bgs2_status_word_1_b;  //!< Слово 1 состояния БГС 2
   mfci_in_blocks_bgs_status_word_2_b_t   bgs2_status_word_2_b;  //!< Слово 2 состояния БГС 2
   mfci_in_blocks_bgs_status_word_3_b_t   bgs2_status_word_3_b;  //!< Слово 3 состояния БГС 2
   mfci_in_blocks_kvi_status_word_1_b_t   kvi1_status_word_1_b;  //!< Слово 1 состояния КВИ 1
   mfci_in_blocks_kvi_status_word_2_b_t   kvi1_status_word_2_b;  //!< Слово 2 состояния КВИ 1
   mfci_in_blocks_kvi_status_word_3_b_t   kvi1_status_word_3_b;  //!< Слово 3 состояния КВИ 1
   mfci_in_blocks_kvi_status_word_4_b_t   kvi1_status_word_4_b;  //!< Слово 4 состояния КВИ 1
   mfci_in_blocks_kvi_status_word_5_b_t   kvi1_status_word_5_b;  //!< Слово 5 состояния КВИ 1
   mfci_in_blocks_kvi_status_word_6_b_t   kvi1_status_word_6_b;  //!< Слово 6 состояния КВИ 1
   mfci_in_blocks_kvi_status_word_1_b_t   kvi2_status_word_1_b;  //!< Слово 1 состояния КВИ 2
   mfci_in_blocks_kvi_status_word_2_b_t   kvi2_status_word_2_b;  //!< Слово 2 состояния КВИ 2
   mfci_in_blocks_kvi_status_word_3_b_t   kvi2_status_word_3_b;  //!< Слово 3 состояния КВИ 2
   mfci_in_blocks_kvi_status_word_4_b_t   kvi2_status_word_4_b;  //!< Слово 4 состояния КВИ 2
   mfci_in_blocks_kvi_status_word_5_b_t   kvi2_status_word_5_b;  //!< Слово 5 состояния КВИ 2
   mfci_in_blocks_kvi_status_word_6_b_t   kvi2_status_word_6_b;  //!< Слово 6 состояния КВИ 2
   mfci_in_blocks_boards_status_word_b_t  boards_status_word_b;  //!< Слово состояния ПУИ, МУП, 1П2М, 1П8М
   mfci_in_blocks_mfpu_status_word_b_t    mfpu_status_word_b;    //!< Слово состояния МФПУ
   mfci_in_blocks_mfci_status_word_1_b_t  mfci_status_word_1_b;  //!< Слово 1 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_2_b_t  mfci_status_word_2_b;  //!< Слово 2 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_3_b_t  mfci_status_word_3_b;  //!< Слово 3 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_4_b_t  mfci_status_word_4_b;  //!< Слово 4 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_5_b_t  mfci_status_word_5_b;  //!< Слово 5 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_6_b_t  mfci_status_word_6_b;  //!< Слово 6 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_7_b_t  mfci_status_word_7_b;  //!< Слово 7 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_8_b_t  mfci_status_word_8_b;  //!< Слово 8 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_9_b_t  mfci_status_word_9_b;  //!< Слово 9 состояния МФЦИ
   mfci_in_blocks_mfci_status_word_10_b_t mfci_status_word_10_b; //!< Слово 10 состояния МФЦИ
   mfci_in_blocks_selected_systems_1_b_t  selected_systems_1_b;  //!< Выбранные для взаимодействия системы (слово 1)
   mfci_in_blocks_selected_systems_2_b_t  selected_systems_2_b;  //!< Выбранные для взаимодействия системы (слово 2)
   mfci_in_blocks_selected_systems_3_b_t  selected_systems_3_b;  //!< Выбранные для взаимодействия системы (слово 3)
   uint16_t                               build_number;          //!< Номер сборки //(min:1 max:65535 bits:4..19 lsb:1)
} mfci_in_blocks_3_b_t;

//! Входное сообщение МФЦИ c данными кадра БЛОКИ-СЗИ (МКИО-3.1, 1 Гц, фрагмент 1)
typedef struct mfci_in_blocks_szi_1_b_t {
   uint16_t                            mfci_format;       //!< Кадр МФЦИ (MFCI_FORMAT_BLOCKS_SZI)
   mfci_in_blocks_szi_1_valid_word_b_t valid_word_b;      //!< Признаки наличия данных СЗИ (для фрагмента 1)
   mfci_in_blocks_szi_messages_b_t     bis1_messages_1_b; //!< Матрица событий СЗИ БИС 1 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bis1_messages_2_b; //!< Матрица событий СЗИ БИС 1 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bis1_messages_3_b; //!< Матрица событий СЗИ БИС 1 (слово 3)
   mfci_in_blocks_szi_messages_b_t     bis1_messages_4_b; //!< Матрица событий СЗИ БИС 1 (слово 4)
   mfci_in_blocks_szi_messages_b_t     bis1_messages_5_b; //!< Матрица событий СЗИ БИС 1 (слово 5)
   mfci_in_blocks_szi_messages_b_t     bis2_messages_1_b; //!< Матрица событий СЗИ БИС 2 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bis2_messages_2_b; //!< Матрица событий СЗИ БИС 2 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bis2_messages_3_b; //!< Матрица событий СЗИ БИС 2 (слово 3)
   mfci_in_blocks_szi_messages_b_t     bis2_messages_4_b; //!< Матрица событий СЗИ БИС 2 (слово 4)
   mfci_in_blocks_szi_messages_b_t     bis2_messages_5_b; //!< Матрица событий СЗИ БИС 2 (слово 5)
   mfci_in_blocks_szi_messages_b_t     bgs1_messages_1_b; //!< Матрица событий СЗИ БГС 1 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bgs1_messages_2_b; //!< Матрица событий СЗИ БГС 1 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bgs1_messages_3_b; //!< Матрица событий СЗИ БГС 1 (слово 3)
   mfci_in_blocks_szi_messages_b_t     bgs1_messages_4_b; //!< Матрица событий СЗИ БГС 1 (слово 4)
   mfci_in_blocks_szi_messages_b_t     bgs2_messages_1_b; //!< Матрица событий СЗИ БГС 2 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bgs2_messages_2_b; //!< Матрица событий СЗИ БГС 2 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bgs2_messages_3_b; //!< Матрица событий СЗИ БГС 2 (слово 3)
   mfci_in_blocks_szi_messages_b_t     bgs2_messages_4_b; //!< Матрица событий СЗИ БГС 2 (слово 4)
   mfci_in_blocks_szi_messages_b_t     kvi1_messages_1_b; //!< Матрица событий СЗИ КВИ 1 (слово 1)
   mfci_in_blocks_szi_messages_b_t     kvi1_messages_2_b; //!< Матрица событий СЗИ КВИ 1 (слово 2)
   mfci_in_blocks_szi_messages_b_t     kvi1_messages_3_b; //!< Матрица событий СЗИ КВИ 1 (слово 3)
   mfci_in_blocks_szi_messages_b_t     kvi1_messages_4_b; //!< Матрица событий СЗИ КВИ 1 (слово 4)
   mfci_in_blocks_szi_messages_b_t     kvi1_messages_5_b; //!< Матрица событий СЗИ КВИ 1 (слово 5)
   mfci_in_blocks_szi_messages_b_t     kvi2_messages_1_b; //!< Матрица событий СЗИ КВИ 2 (слово 1)
   mfci_in_blocks_szi_messages_b_t     kvi2_messages_2_b; //!< Матрица событий СЗИ КВИ 2 (слово 2)
   mfci_in_blocks_szi_messages_b_t     kvi2_messages_3_b; //!< Матрица событий СЗИ КВИ 2 (слово 3)
   mfci_in_blocks_szi_messages_b_t     kvi2_messages_4_b; //!< Матрица событий СЗИ КВИ 2 (слово 4)
   mfci_in_blocks_szi_messages_b_t     kvi2_messages_5_b; //!< Матрица событий СЗИ КВИ 2 (слово 5)
} mfci_in_blocks_szi_1_b_t;

//! Входное сообщение МФЦИ c данными кадра БЛОКИ-СЗИ (МКИО-3.2, 1 Гц, фрагмент 2)
typedef struct mfci_in_blocks_szi_2_b_t {
   uint16_t                            mfci_format;        //!< Кадр МФЦИ (MFCI_FORMAT_BLOCKS_SZI)
   mfci_in_blocks_szi_2_valid_word_b_t valid_word_b;       //!< Признаки наличия данных СЗИ (для фрагмента 2)
   mfci_in_blocks_szi_messages_b_t     bcvm1_messages_1_b; //!< Матрица событий СЗИ БЦВМ 1 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bcvm1_messages_2_b; //!< Матрица событий СЗИ БЦВМ 1 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bcvm1_messages_3_b; //!< Матрица событий СЗИ БЦВМ 1 (слово 3)
   mfci_in_blocks_szi_messages_b_t     bcvm1_messages_4_b; //!< Матрица событий СЗИ БЦВМ 1 (слово 4)
   mfci_in_blocks_szi_messages_b_t     bcvm1_messages_5_b; //!< Матрица событий СЗИ БЦВМ 1 (слово 5)
   mfci_in_blocks_szi_messages_b_t     bcvm2_messages_1_b; //!< Матрица событий СЗИ БЦВМ 2 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bcvm2_messages_2_b; //!< Матрица событий СЗИ БЦВМ 2 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bcvm2_messages_3_b; //!< Матрица событий СЗИ БЦВМ 2 (слово 3)
   mfci_in_blocks_szi_messages_b_t     bcvm2_messages_4_b; //!< Матрица событий СЗИ БЦВМ 2 (слово 4)
   mfci_in_blocks_szi_messages_b_t     bcvm2_messages_5_b; //!< Матрица событий СЗИ БЦВМ 2 (слово 5)
   mfci_in_blocks_szi_messages_b_t     bvd1_messages_1_b;  //!< Матрица событий СЗИ БВД 1 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bvd1_messages_2_b;  //!< Матрица событий СЗИ БВД 1 (слово 2)
   mfci_in_blocks_szi_messages_b_t     bvd2_messages_1_b;  //!< Матрица событий СЗИ БВД 2 (слово 1)
   mfci_in_blocks_szi_messages_b_t     bvd2_messages_2_b;  //!< Матрица событий СЗИ БВД 2 (слово 2)
} mfci_in_blocks_szi_2_b_t;

//! Входное сообщение МФЦИ c данными кадра ТАР (МКИО-3.1, 1 Гц)
typedef struct mfci_in_tar_b_t {
   uint16_t                        mfci_format;         //!< Кадр МФЦИ (MFCI_FORMAT_TAR)
   mfci_in_tar_status_word_b_t     status_word_b;       //!< Слово состояния
   mfci_in_tar_status_word_adc_b_t status_word_adc1_b;  //!< Слово состояния кодов АЦП-1 тарируемого параметра
   mfci_in_tar_status_word_adc_b_t status_word_adc2_b;  //!< Слово состояния кодов АЦП-2 тарируемого параметра
   uint16_t                        current_code_adc1;   //!< Текущий код АЦП-1 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        current_code_adc2;   //!< Текущий код АЦП-2 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_1_adc1;         //!< Код АЦП-1 узловой точки 1 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_1_adc2;         //!< Код АЦП-2 узловой точки 1 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_2_adc1;         //!< Код АЦП-1 узловой точки 2 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_2_adc2;         //!< Код АЦП-2 узловой точки 2 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_3_adc1;         //!< Код АЦП-1 узловой точки 3 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_3_adc2;         //!< Код АЦП-2 узловой точки 3 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_4_adc1;         //!< Код АЦП-1 узловой точки 4 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_4_adc2;         //!< Код АЦП-2 узловой точки 4 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_5_adc1;         //!< Код АЦП-1 узловой точки 5 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_5_adc2;         //!< Код АЦП-2 узловой точки 5 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_6_adc1;         //!< Код АЦП-1 узловой точки 6 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_6_adc2;         //!< Код АЦП-2 узловой точки 6 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_7_adc1;         //!< Код АЦП-1 узловой точки 7 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        code_7_adc2;         //!< Код АЦП-2 узловой точки 7 тарируемого параметра //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                        uks1_table_crc_low;  //!< Контрольная сумма таблицы тарировок УКС-1 (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t                        uks1_table_crc_high; //!< Контрольная сумма таблицы тарировок УКС-1 (младшее слово)
   uint16_t                        uks2_table_crc_low;  //!< Контрольная сумма таблицы тарировок УКС-2 (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t                        uks2_table_crc_high; //!< Контрольная сумма таблицы тарировок УКС-2 (младшее слово)
   uint16_t                        uks3_table_crc_low;  //!< Контрольная сумма таблицы тарировок УКС-3 (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t                        uks3_table_crc_high; //!< Контрольная сумма таблицы тарировок УКС-3 (младшее слово)
   uint16_t                        uks4_table_crc_low;  //!< Контрольная сумма таблицы тарировок УКС-4 (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t                        uks4_table_crc_high; //!< Контрольная сумма таблицы тарировок УКС-4 (младшее слово)
} mfci_in_tar_b_t;

//! Входное сообщение МФЦИ c данными ФОВБ (6.25 Гц, подадрес 24 МКИО-3.2)
typedef struct mfci_in_fovb_b_t {
   uint16_t             fovb_section_0_low;     //!< Элемент 0 массива передаваемых сечений вихревого следа (fovb_section_b_t, младшее слово)
   uint16_t             fovb_section_0_high;    //!< Элемент 0 массива передаваемых сечений вихревого следа (fovb_section_b_t, старшее слово)
   uint16_t             fovb_section_1_low;     //!< Элемент 1 массива передаваемых сечений вихревого следа (fovb_section_b_t, младшее слово)
   uint16_t             fovb_section_1_high;    //!< Элемент 1 массива передаваемых сечений вихревого следа (fovb_section_b_t, старшее слово)
   uint16_t             fovb_section_2_low;     //!< Элемент 2 массива передаваемых сечений вихревого следа (fovb_section_b_t, младшее слово)
   uint16_t             fovb_section_2_high;    //!< Элемент 2 массива передаваемых сечений вихревого следа (fovb_section_b_t, старшее слово)
   uint16_t             fovb_section_3_low;     //!< Элемент 3 массива передаваемых сечений вихревого следа (fovb_section_b_t, младшее слово)
   uint16_t             fovb_section_3_high;    //!< Элемент 3 массива передаваемых сечений вихревого следа (fovb_section_b_t, старшее слово)
   uint16_t             fovb_section_4_low;     //!< Элемент 4 массива передаваемых сечений вихревого следа (fovb_section_b_t, младшее слово)
   uint16_t             fovb_section_4_high;    //!< Элемент 4 массива передаваемых сечений вихревого следа (fovb_section_b_t, старшее слово)
   uint16_t             fovb_section_5_low;     //!< Элемент 5 массива передаваемых сечений вихревого следа (fovb_section_b_t, младшее слово)
   uint16_t             fovb_section_5_high;    //!< Элемент 5 массива передаваемых сечений вихревого следа (fovb_section_b_t, старшее слово)
   fovb_sections_id_b_t fovb_sections_id_b;     //!< Параметры массива передаваемых сечений вихревого следа
   uint16_t             fovb_trail_1_id_1_low;  //!< Параметры вихревого следа 1 (слово 1, fovb_trail_id_1_b_t, старшая часть)
   uint16_t             fovb_trail_1_id_1_high; //!< Параметры вихревого следа 1 (слово 1, fovb_trail_id_1_b_t, младшая часть)
   fovb_trail_id_2_b_t  fovb_trail_1_id_2_b;    //!< Параметры вихревого следа 1 (слово 2)
   uint16_t             fovb_trail_2_id_1_low;  //!< Параметры вихревого следа 2 (слово 1, fovb_trail_id_1_b_t, старшая часть)
   uint16_t             fovb_trail_2_id_1_high; //!< Параметры вихревого следа 2 (слово 1, fovb_trail_id_1_b_t, младшая часть)
   fovb_trail_id_2_b_t  fovb_trail_2_id_2_b;    //!< Параметры вихревого следа 2 (слово 2)
   uint16_t             fovb_trail_3_id_1_low;  //!< Параметры вихревого следа 3 (слово 1, fovb_trail_id_1_b_t, старшая часть)
   uint16_t             fovb_trail_3_id_1_high; //!< Параметры вихревого следа 3 (слово 1, fovb_trail_id_1_b_t, младшая часть)
   fovb_trail_id_2_b_t  fovb_trail_3_id_2_b;    //!< Параметры вихревого следа 3 (слово 2)
   uint16_t             fovb_trail_4_id_1_low;  //!< Параметры вихревого следа 4 (слово 1, fovb_trail_id_1_b_t, старшая часть)
   uint16_t             fovb_trail_4_id_1_high; //!< Параметры вихревого следа 4 (слово 1, fovb_trail_id_1_b_t, младшая часть)
   fovb_trail_id_2_b_t  fovb_trail_4_id_2_b;    //!< Параметры вихревого следа 4 (слово 2)
   uint16_t             fovb_trail_5_id_1_low;  //!< Параметры вихревого следа 5 (слово 1, fovb_trail_id_1_b_t, старшая часть)
   uint16_t             fovb_trail_5_id_1_high; //!< Параметры вихревого следа 5 (слово 1, fovb_trail_id_1_b_t, младшая часть)
   fovb_trail_id_2_b_t  fovb_trail_5_id_2_b;    //!< Параметры вихревого следа 5 (слово 2)
   uint16_t             fovb_speed_min;         //!< [ФОВБ-А001] Рекомендуемая приборная скорость минимальная //(min:0 max:1023 bits:10..19 lsb:1 км/ч)
   uint16_t             fovb_speed_max;         //!< [ФОВБ-А002] Рекомендуемая приборная скорость максимальная //(min:0 max:1023 bits:10..19 lsb:1 км/ч)
   fovb_rates_b_t       fovb_rates_b;           //!< [ФОВБ-А003…ФОВБ-А004] Слово рекомендуемых вертикальных скоростей ФОВБ
   fovb_valid_word_b_t  fovb_valid_word_b;      //!< Слово достоверностей ФОВБ
} mfci_in_fovb_b_t;

//! Входное сообщение МФЦИ с траекторией выхода на активный участок маршрута или маневра, подадрес 29 МКИО-3.1 (6.25 Гц)
typedef struct mfci_in_active_path_b_t {
   mfci_active_path_legs_id_1_b_t legs_id_1_b;      //!< Слово-идентификатор 1 участков траектории выхода на активный участок маршрута
   mfci_active_path_legs_id_2_b_t legs_id_2_b;      //!< Слово-идентификатор 2 участков траектории выхода на активный участок маршрута
   uint16_t                       point_1_lat_high; //!< Широта точки 1 участка траектории, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                       point_1_lat_low;  //!< Широта точки 1 участка траектории, младшее слово
   uint16_t                       point_1_lon_high; //!< Долгота точки 1 участка траектории, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                       point_1_lon_low;  //!< Долгота точки 1 участка траектории, младшее слово
   uint16_t                       point_2_lat_high; //!< Широта точки 2 участка траектории, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                       point_2_lat_low;  //!< Широта точки 2 участка траектории, младшее слово
   uint16_t                       point_2_lon_high; //!< Долгота точки 2 участка траектории, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                       point_2_lon_low;  //!< Долгота точки 2 участка траектории, младшее слово
   uint16_t                       point_3_lat_high; //!< Широта точки 3 участка траектории, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                       point_3_lat_low;  //!< Широта точки 3 участка траектории, младшее слово
   uint16_t                       point_3_lon_high; //!< Долгота точки 3 участка траектории, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                       point_3_lon_low;  //!< Долгота точки 3 участка траектории, младшее слово
   uint16_t                       point_4_lat_high; //!< Широта точки 4 участка траектории, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                       point_4_lat_low;  //!< Широта точки 4 участка траектории, младшее слово
   uint16_t                       point_4_lon_high; //!< Долгота точки 4 участка траектории, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                       point_4_lon_low;  //!< Долгота точки 4 участка траектории, младшее слово
   uint16_t                       point_5_lat_high; //!< Широта точки 5 участка траектории, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                       point_5_lat_low;  //!< Широта точки 5 участка траектории, младшее слово
   uint16_t                       point_5_lon_high; //!< Долгота точки 5 участка траектории, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                       point_5_lon_low;  //!< Долгота точки 5 участка траектории, младшее слово
   uint16_t                       leg_1_radius;     //!< Радиус дуги разворота участка 1 траектории (0-прямой участок) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t                       leg_2_radius;     //!< Радиус дуги разворота участка 2 траектории (0-прямой участок) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t                       leg_3_radius;     //!< Радиус дуги разворота участка 3 траектории (0-прямой участок) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t                       leg_4_radius;     //!< Радиус дуги разворота участка 4 траектории (0-прямой участок) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t                       leg_5_radius;     //!< Радиус дуги разворота участка 5 траектории (0-прямой участок) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t                       leg_1_subtense;   //!< Стягивающий угол дуги участка 1 траектории //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                       leg_2_subtense;   //!< Стягивающий угол дуги участка 2 траектории //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                       leg_3_subtense;   //!< Стягивающий угол дуги участка 3 траектории //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                       leg_4_subtense;   //!< Стягивающий угол дуги участка 4 траектории //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                       leg_5_subtense;   //!< Стягивающий угол дуги участка 5 траектории //(min:0 max:360 bits:4..19 msb:180°)
} mfci_in_active_path_b_t;

//! Входное сообщение МФЦИ с фрагментом плана полета, подадрес 30 МКИО-3.1 (6.25 Гц)
typedef struct mfci_in_flight_plan_b_t {
   mfci_leg_id_1_b_t          leg_id_1_b;               //!< Слово-идентификатор 1 точки участка траекторий
   mfci_leg_id_2_b_t          leg_id_2_b;               //!< Слово-идентификатор 2 точки участка траекторий
   uint16_t                   leg_lat_high;             //!< Широта точки участка траекторий, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                   leg_lat_low;              //!< Широта точки участка траекторий, младшее слово
   uint16_t                   leg_lon_high;             //!< Долгота точки участка траекторий, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                   leg_lon_low;              //!< Долгота точки участка траекторий, младшее слово
   uint16_t                   leg_radius;               //!< Радиус дуги разворота следующего участка траекторий (0-прямой участок) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t                   leg_subtense_distance;    //!< Стягивающий угол дуги следующего участка траекторий для дуговых участков //(min:0 max:360 bits:4..19 msb:180°) / Длина следующего участка траекторий для прямых участков //(min:0 max:65535 bits:4..19 lsb:1 км)
   mfci_point_id_1_b_t        point_id_1_b;             //!< Слово-идентификатор 1 точки маршрута или траекторий
   mfci_point_id_2_b_t        point_id_2_b;             //!< Слово-идентификатор 2 точки маршрута или траекторий
   mfci_point_id_3_b_t        point_id_3_b;             //!< Слово-идентификатор 3 точки маршрута или траекторий
   mfci_point_id_4_b_t        point_id_4_b;             //!< Слово-идентификатор 4 точки маршрута или траекторий
   mfci_point_id_5_b_t        point_id_5_b;             //!< Слово-идентификатор 5 точки маршрута или траекторий
   mfci_text_word_b_t         point_name_1_b;           //!< Название точки маршрута или траекторий (символы 1-2)
   mfci_text_word_b_t         point_name_2_b;           //!< Название точки маршрута или траекторий (символы 3-4)
   mfci_text_word_b_t         point_name_3_b;           //!< Название точки маршрута или траекторий (символ 5), название дополнительной точки (символ 1)
   mfci_text_word_b_t         point_name_4_b;           //!< Название дополнительной точки (символы 2-3)
   mfci_text_word_b_t         point_name_5_b;           //!< Название дополнительной точки (символы 4-5)
   uint16_t                   point_lat_high;           //!< Широта точки маршрута или траекторий, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                   point_lat_low;            //!< Широта точки маршрута или траекторий, младшее слово
   uint16_t                   point_lon_high;           //!< Долгота точки маршрута или траекторий, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                   point_lon_low;            //!< Долгота точки маршрута или траекторий, младшее слово
   uint16_t                   point_orientation;        //!< Ориентация точки маршрута или траекторий (для ВПП, ПРС и РПУ) //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                   point_param;              //!< Параметр точки маршрута или траекторий (ЧКК для РСБН, ЦМР 0.01 МГц/0.1 кГц, длина в метрах для торца ВПП, высота для ППМ/препятствий/рубежа набора/рубежа снижения)
   mfci_single_point_id_1_b_t single_point_id_1_b;      //!< Слово-идентификатор 1 дополнительной точки
   mfci_single_point_id_2_b_t single_point_id_2_b;      //!< Слово-идентификатор 2 дополнительной точки
   uint16_t                   single_point_lat_high;    //!< Широта дополнительной точки, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                   single_point_lat_low;     //!< Широта дополнительной точки, младшее слово
   uint16_t                   single_point_lon_high;    //!< Долгота дополнительной точки, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                   single_point_lon_low;     //!< Долгота дополнительной точки, младшее слово
   uint16_t                   single_point_orientation; //!< Ориентация точки маршрута или траекторий (для ВПП, ПРС и РПУ) //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                   single_point_param;       //!< Параметр дополнительной точки (ЧКК для РСБН, частота ЦМР 0.01 МГц/0.1 кГц, длина в метрах для торца ВПП, высота для препятствий/рубежа набора/рубежа снижения, скорость для рубежа разгона/торможения, радиус для зон ЦМР 0.1 км)
} mfci_in_flight_plan_b_t;

//! Данные инициализации исполняемой/предлагаемой траектории БП-504/506 (из раздела 1 АУР)
typedef struct mfci_in_suo_50x_path_init_b_t {
   mfci_in_suo_50x_path_flag_word_1_b_t flag_word_1_b;            //!< Слово 1 сигналов инициализации траектории
   mfci_in_suo_50x_path_flag_word_2_b_t flag_word_2_b;            //!< Слово 2 сигналов инициализации траектории
   uint16_t                             rzp_start_point_distance; //!< [БП-504/506-А124.11/А125.11] Расстояние до передней границы РЗП ("А") //(min:-20200 max:20200 signed:4 bits:5..19 lsb:1 км)
   uint16_t                             ready_point_distance;     //!< [БП-504/506-А124.12/А125.12] Расстояние до рубежа готовности изделий //(min:0 max:20200 bits:4..19 lsb:1 км)
   uint16_t                             speed_correction_rzp;     //!< [БП-504/506-А104] Рекомендуемое изменение воздушной скорости для выхода в РЗП/ОРЗП для ТРК РЗП (только для предлагаемой ТРК) //(min:-999 max:999 signed:4 bits:5..19 lsb:1 км/ч)
   uint16_t                             redundant_time_rzp;       //!< [БП-504/506-А106] Избыток времени при выходе в РЗП/ОРЗП для ТРК РЗП (только для предлагаемой ТРК) //(min:-3599 max:3599 signed:4 bits:5..19 lsb:1 с)
} mfci_in_suo_50x_path_init_b_t;

//! Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 1 АУР), подадрес 1 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_1_b_t {
   uint16_t                     counter;                  //!< Счетчик контроля достоверности данных //(min:0 max:65535 bits:4..19 lsb:1)
   uint16_t                     header_revision;          //!< Ревизия заголовочника (MFCI_IO_REVISION)
   uint16_t                     suo_variant;              //!< Вариант подвеса (SUO_VARIANT_50X)
   bp_50x_aur1_flag_word_1_b_t  bp_50x_flag_word_1_b;     //!< Слово 1 сигналов БП-504/506
   bp_50x_aur1_flag_word_2_b_t  bp_50x_flag_word_2_b;     //!< Слово 2 сигналов БП-504/506
   bp_50x_aur1_flag_word_3_b_t  bp_50x_flag_word_3_b;     //!< Слово 3 сигналов БП-504/506
   bp_50x_aur1_flag_word_4_b_t  bp_50x_flag_word_4_b;     //!< Слово 4 сигналов БП-504/506
   bp_50x_aur1_flag_word_5_b_t  bp_50x_flag_word_5_b;     //!< Слово 5 сигналов БП-504/506
   bp_50x_aur1_flag_word_6_b_t  bp_50x_flag_word_6_b;     //!< Слово 6 сигналов БП-504/506
   bp_50x_aur1_flag_word_7_b_t  bp_50x_flag_word_7_b;     //!< Слово 7 сигналов БП-504/506
   bp_50x_aur1_flag_word_8_b_t  bp_50x_flag_word_8_b;     //!< Слово 8 сигналов БП-504/506
   bp_50x_aur1_flag_word_9_b_t  bp_50x_flag_word_9_b;     //!< Слово 9 сигналов БП-504/506
   bp_50x_aur1_flag_word_10_b_t bp_50x_flag_word_10_b;    //!< Слово 10 сигналов БП-504/506
   bp_50x_aur1_flag_word_11_b_t bp_50x_flag_word_11_b;    //!< Слово 11 сигналов БП-504/506
   bp_50x_aur1_flag_word_12_b_t bp_50x_flag_word_12_b;    //!< Слово 12 сигналов БП-504/506
   bp_50x_aur1_flag_word_13_b_t bp_50x_flag_word_13_b;    //!< Слово 13 сигналов БП-504/506
   bp_50x_aur1_flag_word_14_b_t bp_50x_flag_word_14_b;    //!< Слово 14 сигналов БП-504/506
   bp_50x_aur1_flag_word_15_b_t bp_50x_flag_word_15_b;    //!< Слово 15 сигналов БП-504/506
   bp_50x_aur1_flag_word_16_b_t bp_50x_flag_word_16_b;    //!< Слово 16 сигналов БП-504/506
   bp_50x_aur1_flag_word_17_b_t bp_50x_flag_word_17_b;    //!< Слово 17 сигналов БП-504/506
   bp_50x_aur1_flag_word_18_b_t bp_50x_flag_word_18_b;    //!< Слово 18 сигналов БП-504/506
   uint16_t                     bp_prepare_time_rem;      //!< [БП-504/506-А006] Оставшееся время до прохода передней границы РЗП/ОРЗП //(min:0 max:35999 bits:4..19 lsb:1 с)
   uint16_t                     bp_route_number_high;     //!< [БП-504/506-А013] Номер боевого задания, старшее слово //(min:1 max:9999999 bits:4..19 lsb:1)
   uint16_t                     bp_route_number_low;      //!< [БП-504/506-А013] Номер боевого задания, младшее слово
   uint16_t                     bp_speed_correction;      //!< [БП-504/506-А018] Рекомендуемое изменение воздушной скорости для выхода в РЗП/ОРЗП //(min:-999 max:999 signed:4 bits:5..19 lsb:1 км/ч)
   uint16_t                     bp_redundant_time;        //!< [БП-504/506-А022] Избыток времени при выходе на рубеж пуска //(min:-3599 max:3599 signed:4 bits:5..19 lsb:1 с)
   uint16_t                     bp_track_angle;           //!< [БП-504/506-А030.1] Заданный путевой угол //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                     bp_course;                //!< [БП-504/506-А030.2] Заданный курс //(min:0 max:360 bits:4..19 msb:180°)
   uint16_t                     bp_asu_route_number_high; //!< [БП-504/506-А068.1] Номер БЗ к подсказкам зоны 3 стр. 1 "Назначь БЗ", "Отмени БЗ, старшее слово //(min:1 max:9999999 bits:4..19 lsb:1)
   uint16_t                     bp_asu_route_number_low;  //!< [БП-504/506-А068.1] Номер БЗ к подсказкам зоны 3 стр. 1 "Назначь БЗ", "Отмени БЗ, младшее слово
   uint16_t                     bp_unit_delta_z;          //!< [БП-504/506-А134] Линейное боковое уклонение изделия от линии заданного пути //(min:-99.9 max:99.9 signed:4 bits:5..19 lsb:0.1 км)
} mfci_in_suo_50x_1_b_t;

//! Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 1 АУР), подадрес 2 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_2_b_t {
   mfci_in_suo_50x_path_init_b_t bp_path_init_b;              //!< Данные инициализации исполняемой траектории
   mfci_in_suo_50x_path_init_b_t bp_proposed_path_init_b;     //!< Данные инициализации предлагаемой траектории
   uint16_t                      bp_rzp_start_point_lat_high; //!< [БП-504/506-А051.1] Широта начальной точки оси РЗП/ОРЗП ("A"), старшее слово //(min:-324000 max:324000 signed:4 bits:5..19 lsb:0.001")
   uint16_t                      bp_rzp_start_point_lat_low;  //!< [БП-504/506-А051.1] Широта начальной точки оси РЗП/ОРЗП ("A"), младшее слово
   uint16_t                      bp_rzp_start_point_lon_high; //!< [БП-504/506-А051.2] Долгота начальной точки оси РЗП/ОРЗП ("A"), старшее слово //(min:-648000 max:648000 signed:4 bits:5..19 lsb:0.001")
   uint16_t                      bp_rzp_start_point_lon_low;  //!< [БП-504/506-А051.2] Долгота начальной точки оси РЗП/ОРЗП ("A"), младшее слово
   uint16_t                      bp_rzp_end_point_lat_high;   //!< [БП-504/506-А052.1] Широта конечной точки оси РЗП/ОРЗП ("B"), старшее слово //(min:-324000 max:324000 signed:4 bits:5..19 lsb:0.001")
   uint16_t                      bp_rzp_end_point_lat_low;    //!< [БП-504/506-А052.1] Широта конечной точки оси РЗП/ОРЗП ("B"), младшее слово
   uint16_t                      bp_rzp_end_point_lon_high;   //!< [БП-504/506-А052.2] Долгота конечной точки оси РЗП/ОРЗП ("B"), старшее слово //(min:-648000 max:648000 signed:4 bits:5..19 lsb:0.001")
   uint16_t                      bp_rzp_end_point_lon_low;    //!< [БП-504/506-А052.2] Долгота конечной точки оси РЗП/ОРЗП ("B"), младшее слово
   uint16_t                      bp_rzp_width;                //!< [БП-504/506-А112] Ширина РЗП/ОРЗП //(min:1000 max:50000 bits:4..19 lsb:1 м)
   uint16_t                      bp_message_1l_time_rem_high; //!< [БП-504/506-А054.2] Оставшееся время для строки 1 левой, старшее слово //(min:0 max:86399 bits:4..19 lsb:1 с)
   uint16_t                      bp_message_1l_time_rem_low;  //!< [БП-504/506-А054.2] Оставшееся время для строки 1 левой, младшее слово
   uint16_t                      bp_message_1m_time_rem;      //!< [БП-504/506-А055.2] Оставшееся время для строки 1 по центру //(min:0 max:35999 bits:4..19 lsb:1 с)
   uint16_t                      bp_align_value_units;        //!< [БП-504/506-А061.2] Время выставки изделий //(min:0 max:1440 bits:4..19 lsb:1 с)
   uint16_t                      bp_signal_alt_up;            //!< [БП-504/506-А068.4] Высота к подсказке зоны 3 стр. 1 "Увеличь высоту" //(min:300 max:3500 bits:4..19 lsb:1 м)
   uint16_t                      bp_signal_alt_down;          //!< [БП-504/506-А068.5] Высота к подсказке зоны 3 стр. 1 "Уменьши высоту" //(min:5000 max:13000 bits:4..19 lsb:1 м)
} mfci_in_suo_50x_2_b_t;

//! Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 2 АУР), подадрес 3 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_3_b_t {
   bp_50x_aur2_flag_word_1_b_t bp_50x_flag_word_1_b;           //!< Слово 1 сигналов БП-504/506
   bp_50x_aur2_flag_word_2_b_t bp_50x_flag_word_2_b;           //!< Слово 2 сигналов БП-504/506
   bp_50x_aur2_flag_word_3_b_t bp_50x_flag_word_3_b;           //!< Слово 3 сигналов БП-504/506
   uint16_t                    bp_first_waypoint_x_high;       //!< [БП-504/506-А200.3] Координата x ППМ № 1 для головного изделия на проекции, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t                    bp_first_waypoint_x_low;        //!< [БП-504/506-А200.3] Координата x ППМ № 1 для головного изделия на проекции, младшее слово
   uint16_t                    bp_first_waypoint_y_high;       //!< [БП-504/506-А200.3] Координата y ППМ № 1 для головного изделия на проекции, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t                    bp_first_waypoint_y_low;        //!< [БП-504/506-А200.3] Координата y ППМ № 1 для головного изделия на проекции, младшее слово
   uint16_t                    bp_cursor_point_mfpu_x_high;    //!< [БП-504/506-А215.1.1] Координата x курсора для перемещения центра ОРЗП по данным МФПУ на проекции, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t                    bp_cursor_point_mfpu_x_low;     //!< [БП-504/506-А215.1.1] Координата x курсора для перемещения центра ОРЗП по данным МФПУ на проекции, младшее слово
   uint16_t                    bp_cursor_point_mfpu_y_high;    //!< [БП-504/506-А215.1.2] Координата y курсора для перемещения центра ОРЗП по данным МФПУ на проекции, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t                    bp_cursor_point_mfpu_y_low;     //!< [БП-504/506-А215.1.2] Координата y курсора для перемещения центра ОРЗП по данным МФПУ на проекции, младшее слово
   uint16_t                    bp_rzp_center_x_high;           //!< [БП-504/506-А215.2.1] Координата x центра программной РЗП на проекции, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t                    bp_rzp_center_x_low;            //!< [БП-504/506-А215.2.1] Координата x центра программной РЗП на проекции, младшее слово
   uint16_t                    bp_rzp_center_y_high;           //!< [БП-504/506-А215.2.2] Координата y центра программной РЗП на проекции, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t                    bp_rzp_center_y_low;            //!< [БП-504/506-А215.2.2] Координата y центра программной РЗП на проекции, младшее слово
   uint16_t                    bp_prepare_end_point_dist_high; //!< [БП-504/506-А216.2] Удаленность рубежа передней границы РЗП от ППМ маршрута ФПО НО, старшее слово //(min:0 max:9999 bits:4..19 msb:500 км)
   uint16_t                    bp_prepare_end_point_dist_low;  //!< [БП-504/506-А216.2] Удаленность рубежа передней границы РЗП от ППМ маршрута ФПО НО, младшее слово
   uint16_t                    bp_orzp_shift_x;                //!< [БП-504/506-А219] Продольное отклонение ОРЗП от РЗП //(min:-9999 max:9999 signed:4 bits:5..19 lsb:1 км)
   uint16_t                    bp_orzp_shift_z;                //!< [БП-504/506-А221] Боковое отклонение ОРЗП от РЗП //(min:-9999 max:9999 signed:4 bits:5..19 lsb:1 км)
} mfci_in_suo_50x_3_b_t;

//! Входное сообщение МФЦИ c данными траектории кадра СУО-504/506 (из раздела 1 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_path_b_t {
   uint16_t          sa_type;        //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_PATH/MFCI_IN_SUO_50X_SA_PROPOSED_PATH)
   bp_path_id_b_t    id_b;           //!< Слово-идентификатор передаваемой группы участков траектории БП-504/506
   mfci_bp_coord_b_t points_b[5];    //!< [БП-504/506-А124/А125.2] Фрагмент массива координат точек траектории, начиная с элемента с индексом (id_b.start_number - 1)
   uint16_t          radiuses[5];    //!< [БП-504/506-А124/А125.4] Фрагмент массива радиусов разворота на участках траектории, начиная с элемента с индексом (id_b.start_number - 1) //(min:0 max:100 bits:4..19 msb:50 км)
   uint16_t          arc_lengths[5]; //!< [БП-504/506-А124/А125.5] Фрагмент массива угловых размеров дуг траектории, начиная с элемента с индексом (id_b.start_number - 1) //(min:0 max:360 bits:4..19 msb:180°)
} mfci_in_suo_50x_path_b_t;

//! Входное сообщение МФЦИ c данными траектории в режиме автономного полета кадра СУО-504/506 (из раздела 1 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_trk_ap_b_t {
   uint16_t                             sa_type;                   //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_TRK_AP)
   mfci_in_suo_50x_trk_ap_flag_word_b_t flag_word_b;               //!< Слово сигналов траектории в режиме автономного полета
   uint16_t                             bp_waypoint_distance_high; //!< [БП-504/506-А138] Расстояние до очередного ППМ, старшее слово //(min:0 max:15000000 bits:4..19 lsb:1 м)
   uint16_t                             bp_waypoint_distance_low;  //!< [БП-504/506-А138] Расстояние до очередного ППМ, младшее слово
   uint16_t                             bp_delta_z;                //!< [БП-504/506-А140] Линейное боковое уклонение от линии заданного пути //(min:-99.9 max:99.9 signed:4 bits:5..19 lsb:0.1 км)
} mfci_in_suo_50x_trk_ap_b_t;

//! Входное сообщение МФЦИ c данными инициализации РВП СУО-504/506 (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_rvp_init_b_t {
   uint16_t sa_type; //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_RVP_INIT)
   uint16_t reserve; //!< Резерв
   float    csr;     //!< [БП-504/506-А208.4] Цена старшего разряда координат точек РВП на осях проекции (рад) //(min:0 max:1.570796326795)
} mfci_in_suo_50x_rvp_init_b_t;

//! Входное сообщение МФЦИ c данными инициализации страницы 3 кадра СУО-504/506 (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_page_3_init_b_t {
   uint16_t sa_type;         //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_PAGE_3_INIT)
   uint16_t reserve;         //!< Резерв
   uint16_t m_g_to_gx_1;     //!< [БП-504/506-А200.1] Матрица поворота в косую проекцию для РВП, строка 1, столбец 1 //(min:-1 max:1 signed:4 bits:5..19 msb:0.5)
   uint16_t m_g_to_gx_2;     //!< [БП-504/506-А200.1] Матрица поворота в косую проекцию для РВП, строка 2, столбец 1 //(min:-1 max:1 signed:4 bits:5..19 msb:0.5)
   uint16_t m_g_to_gx_3;     //!< [БП-504/506-А200.1] Матрица поворота в косую проекцию для РВП, строка 1, столбец 2 //(min:-1 max:1 signed:4 bits:5..19 msb:0.5)
   uint16_t m_g_to_gx_4;     //!< [БП-504/506-А200.1] Матрица поворота в косую проекцию для РВП, строка 2, столбец 2 //(min:-1 max:1 signed:4 bits:5..19 msb:0.5)
   uint16_t proj_c_lat_high; //!< [БП-504/506-А200.2] Широта центра гномонической проекции для РВП, старшее слово (ЦСР пи/2 рад) //(min:-1.570796326795 max:1.570796326795 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t proj_c_lat_low;  //!< [БП-504/506-А200.2] Широта центра гномонической проекции для РВП, младшее слово
   uint16_t proj_c_lon_high; //!< [БП-504/506-А200.2] Долгота центра гномонической проекции для РВП, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t proj_c_lon_low;  //!< [БП-504/506-А200.2] Долгота центра гномонической проекции для РВП, младшее слово
} mfci_in_suo_50x_page_3_init_b_t;

//! Входное сообщение МФЦИ c данными точек РВП кадра СУО-504/506 (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_rvp_points_b_t {
   uint16_t              sa_type;      //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_RVP_POINTS)
   uint16_t              start_number; //!< Номер первого элемента в массиве точек РВП points_b //(min:1 max:1500 bits:4..19 lsb:1)
   mfci_bp_rvp_point_b_t points_b[15]; //!< [БП-504/506-А208.1] Фрагмент массива точек РВП, начиная с элемента с индексом (start_number - 1)
} mfci_in_suo_50x_rvp_points_b_t;

//! Входное сообщение МФЦИ c данными описаний полигонов РВП (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_rvp_polygons_b_t {
   uint16_t                sa_type;        //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_RVP_POLYGONS)
   uint16_t                start_number;   //!< Номер первого элемента в массиве описаний полигонов РВП polygons_b //(min:1 max:375 bits:4..19 lsb:1)
   mfci_bp_rvp_polygon_b_t polygons_b[30]; //!< [БП-504/506-А208.2/3] Фрагмент массива описаний полигонов РВП, начиная с элемента с индексом (start_number - 1)
} mfci_in_suo_50x_rvp_polygons_b_t;

//! Входное сообщение МФЦИ c данными точек контура ОСП (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_osp_outer_points_b_t {
   uint16_t                     sa_type;         //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_OSP_OUTER_POINTS)
   uint16_t                     start_number;    //!< Номер первого элемента в массиве точек контура ОСП points_b //(min:1 max:135 bits:4..19 lsb:1)
   bp_50x_osp_units_count_1_b_t units_count_1_b; //!< [БП-504/506-А117.3] Слово 1 количества АСП в точках контура ОСП
   bp_50x_osp_units_count_2_b_t units_count_2_b; //!< [БП-504/506-А117.3] Слово 2 количества АСП в точках контура ОСП
   mfci_bp_coord_b_t            points_b[7];     //!< [БП-504/506-А117.1] Фрагмент массива точек контура ОСП, начиная с элемента с индексом (start_number - 1)
} mfci_in_suo_50x_osp_outer_points_b_t;

//! Входное сообщение МФЦИ c данными точек рубежа начала пусков ОСП (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_osp_inner_points_b_t {
   uint16_t          sa_type;      //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_OSP_INNER_POINTS)
   uint16_t          start_number; //!< Номер первого элемента в массиве точек рубежа начала пусков ОСП points_b //(min:1 max:45 bits:4..19 lsb:1)
   uint16_t          reserve_1;    //!< Резерв
   uint16_t          reserve_2;    //!< Резерв
   mfci_bp_coord_b_t points_b[7];  //!< [БП-504/506-А117.2] Фрагмент массива точек рубежа начала пусков ОСП, начиная с элемента с индексом (start_number - 1)
} mfci_in_suo_50x_osp_inner_points_b_t;

//! Входное сообщение МФЦИ c данными точек запретных и опасных зон (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_areas_points_b_t {
   uint16_t          sa_type;      //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_AREAS_POINTS)
   uint16_t          start_number; //!< Номер первого элемента в массиве точек запретных и опасных зон points_b //(min:1 max:256 bits:4..19 lsb:1)
   uint16_t          reserve_1;    //!< Резерв
   uint16_t          reserve_2;    //!< Резерв
   mfci_bp_coord_b_t points_b[7];  //!< [БП-504/506-А129.1] Координаты точек запретных и опасных зон
} mfci_in_suo_50x_areas_points_b_t;

//! Входное сообщение МФЦИ c данными описаний полигонов запретных и опасных зон (из раздела 2 АУР), МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_areas_b_t {
   uint16_t         sa_type;      //!< Идентификатор подадреса (MFCI_IN_SUO_50X_SA_AREAS)
   uint16_t         start_number; //!< Номер первого элемента в массиве описаний запретных и опасных зон areas_b //(min:1 max:85 bits:4..19 lsb:1)
   mfci_bp_area_b_t areas_b[30];  //!< [БП-504/506-А129.2/Д129] Фрагмент массива описаний запретных или опасных зон, начиная с элемента с индексом (start_number - 1)
} mfci_in_suo_50x_areas_b_t;

//! Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 1/2 АУР), подадрес 4-20 МКИО-3.2 (12.5 Гц)
typedef union mfci_in_suo_50x_4_20_b_t {
   mfci_in_suo_50x_path_b_t             path_b;             //!< Данные исполняемой или предлагаемой траектории (из раздела 1 АУР)
   mfci_in_suo_50x_trk_ap_b_t           trk_ap_b;           //!< Данные траектории в режиме автономного полета (из раздела 1 АУР)
   mfci_in_suo_50x_rvp_init_b_t         rvp_init_b;         //!< Данные инициализации РВП (из раздела 2 АУР)
   mfci_in_suo_50x_rvp_points_b_t       rvp_points_b;       //!< Данные точек РВП (из раздела 2 АУР)
   mfci_in_suo_50x_rvp_polygons_b_t     rvp_polygons_b;     //!< Данные описаний полигонов РВП (из раздела 2 АУР)
   mfci_in_suo_50x_osp_outer_points_b_t osp_outer_points_b; //!< Данные точек контура ОСП (из раздела 2 АУР)
   mfci_in_suo_50x_osp_inner_points_b_t osp_inner_points_b; //!< Данные точек рубежа начала пусков ОСП (из раздела 2 АУР)
   mfci_in_suo_50x_areas_points_b_t     areas_points_b;     //!< Данные точек запретных и опасных зон (из раздела 2 АУР)
   mfci_in_suo_50x_areas_b_t            areas_b;            //!< Данные описаний полигонов запретных и опасных зон (из раздела 2 АУР)
   mfci_in_suo_50x_page_3_init_b_t      page_3_init_b;      //!< Данные инициализации страницы 3 кадра СУО-504/506 (из раздела 2 АУР)
} mfci_in_suo_50x_4_20_b_t;

//! Входное сообщение МФЦИ c данными о ТИ и перемещении центра ОРЗП в кадре СУО-504/506 (для передачи из МФЦИ в БГС)
typedef struct mfci_soi_ti_cursor_b_t {
   uint16_t soi_ti_x_high;                //!< [СОИ] Координата x точки интереса, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t soi_ti_x_low;                 //!< [СОИ] Координата x точки интереса, младшее слово
   uint16_t soi_ti_y_high;                //!< [СОИ] Координата y точки интереса, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t soi_ti_y_low;                 //!< [СОИ] Координата y точки интереса, младшее слово
   uint16_t soi_cursor_point_mfci_x_high; //!< [СОИ] Координата x курсора для перемещения центра ОРЗП по кнопкам МФЦИ, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t soi_cursor_point_mfci_x_low;  //!< [СОИ] Координата x курсора для перемещения центра ОРЗП по кнопкам МФЦИ, младшее слово
   uint16_t soi_cursor_point_mfci_y_high; //!< [СОИ] Координата y курсора для перемещения центра ОРЗП по кнопкам МФЦИ, старшее слово (ЦСР пи/2 рад) //(min:-3.14159265359 max:3.14159265359 signed:4 bits:5..19 msb:1.570796326795 рад)
   uint16_t soi_cursor_point_mfci_y_low;  //!< [СОИ] Координата y курсора для перемещения центра ОРЗП по кнопкам МФЦИ, младшее слово
} mfci_soi_ti_cursor_b_t;

//! Входное сообщение БГС c данными кадра СУО-504/506 (из МФЦИ), подадрес 21 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_21_b_t {
   mfci_soi_ti_cursor_b_t mfci_1_4_ti_cursor_b[4]; //!< [СОИ] Данные о ТИ и перемещении центра ОРЗП от МФЦИ №№ 1-4 в БГС
} mfci_in_suo_50x_21_b_t;

//! Входное сообщение БГС c данными кадра СУО-504/506 (из МФЦИ), подадрес 22 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_22_b_t {
   mfci_soi_ti_cursor_b_t mfci_5_8_ti_cursor_b[4]; //!< [СОИ] Данные о ТИ и перемещении центра ОРЗП от МФЦИ №№ 5-8 в БГС
} mfci_in_suo_50x_22_b_t;

//! Входное сообщение БГС c данными кадра СУО-504/506 (из МФЦИ), подадрес 23 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_50x_23_b_t {
   mfci_soi_ti_cursor_b_t mfci_9_11_ti_cursor_b[3]; //!< [СОИ] Данные о ТИ и перемещении центра ОРЗП от МФЦИ №№ 9-11 в БГС
} mfci_in_suo_50x_23_b_t;

//! Входное сообщение МФЦИ c данными кадра СУО-ИИПЭ, подадрес 26 МКИО-3.2 (12.5 Гц)
typedef struct mfci_in_suo_iipa_b_t {
   uint16_t reserve; //!< Резерв
} mfci_in_suo_iipa_b_t;

//! Входное сообщение МФЦИ, подадрес 27-29 МКИО-3.2 (6.25 Гц, c данными кадра АСУ)
typedef struct mfci_in_asu_b_t {
   asu_header_word_1_b_t    asu_header_word_1_b;                  //!< Заголовок сообщения АСУ (слово 1)
   asu_header_word_2_b_t    asu_header_word_2_b;                  //!< Заголовок сообщения АСУ (слово 2)
   asu_header_word_3_b_t    asu_header_word_3_b;                  //!< Заголовок сообщения АСУ (слово 3)
   asu_header_word_4_b_t    asu_header_word_4_b;                  //!< Заголовок сообщения АСУ (слово 4)
   asu_header_word_5_b_t    asu_header_word_5_b;                  //!< Заголовок сообщения АСУ (слово 5)
   asu_header_word_6_b_t    asu_header_word_6_b;                  //!< Заголовок сообщения АСУ (слово 6)
   asu_header_word_7_in_b_t asu_header_word_7_b;                  //!< Заголовок сообщения АСУ (слово 7)
   asu_header_word_8_b_t    asu_header_word_8_b;                  //!< Заголовок сообщения АСУ (слово 8)
   uint16_t                 asu_segment[ASU_SEGMENT_WORDS_COUNT]; //!< Cегмент команды из АСУ в СОИ/МФЦИ
} mfci_in_asu_b_t;

//! Входное сообщение МФЦИ, подадрес 30 МКИО-3.2 (1 Гц, c данными кадра АСУ и 19-ДА)
typedef struct mfci_in_asu_u19_b_t {
   uint16_t            mfpu_to_mfci_msg2[MFPU_TO_MFCI_MSG2_SIZE]; //!< Сообщение из активного МФПУ (данные АСУ)
   u19_flag_word_1_b_t u19_flag_word_1_b;                         //!< Слово 1 сигналов 19-ДА
   u19_flag_word_2_b_t u19_flag_word_2_b;                         //!< Слово 2 сигналов 19-ДА
   u19_flag_word_3_b_t u19_flag_word_3_b;                         //!< Слово 3 сигналов 19-ДА
} mfci_in_asu_u19_b_t;

//! Слова сигналов УПР МФЦИ (1 Гц, для передачи в БГС по SpaceWire и в адресных подадресах 1-3 МКИО-3.1)
typedef struct mfci_in_upr_flag_words_b_t {
   upr_flag_word_common_1_b_t common_1_b; //!< Слово 1 сигналов УПР (общее для всех кадров)
   upr_flag_word_common_2_b_t common_2_b; //!< Слово 2 сигналов УПР (общее для всех кадров)
   upr_flag_word_common_3_b_t common_3_b; //!< Слово 3 сигналов УПР (общее для всех кадров)
   upr_flag_word_common_4_b_t common_4_b; //!< Слово 4 сигналов УПР (общее для всех кадров)
   upr_flag_word_format_b_t   format_1_b; //!< Слово 1 сигналов УПР для индицируемого кадра
   upr_flag_word_format_b_t   format_2_b; //!< Слово 2 сигналов УПР для индицируемого кадра
   upr_flag_word_format_b_t   format_3_b; //!< Слово 3 сигналов УПР для индицируемого кадра
   upr_flag_word_format_b_t   format_4_b; //!< Слово 4 сигналов УПР для индицируемого кадра
} mfci_in_upr_flag_words_b_t;

//! Данные из МФЦИ в БГС (1 Гц, для передачи в БГС по SpaceWire)
typedef struct mfci_to_bgs_sw_b_t {
   mfci_in_upr_flag_words_b_t upr_flag_words_b[MFCI_COUNT]; //!< Слова сигналов УПР МФЦИ
   uint16_t                   mup1_latitude_high;           //!< Географическая широта курсора МУП 1, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                   mup1_latitude_low;            //!< Географическая широта курсора МУП 1, младшее слово
   uint16_t                   mup1_longitude_high;          //!< Географическая долгота курсора МУП 1, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                   mup1_longitude_low;           //!< Географическая долгота курсора МУП 1, младшее слово
   uint16_t                   mup2_latitude_high;           //!< Географическая широта курсора МУП 2, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t                   mup2_latitude_low;            //!< Географическая широта курсора МУП 2, младшее слово
   uint16_t                   mup2_longitude_high;          //!< Географическая долгота курсора МУП 2, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t                   mup2_longitude_low;           //!< Географическая долгота курсора МУП 2, младшее слово
} mfci_to_bgs_sw_b_t;

//! Данные из МФЦИ в БГС (1 Гц, для передачи в БГС в адресных подадресах 1-3 МКИО-3.1)
typedef struct mfci_to_bgs_mkio_b_t {
   uint16_t sa1_b[32]; //!< Данные из МФЦИ в БГС (подадрес 1)
   uint16_t sa2_b[32]; //!< Данные из МФЦИ в БГС (подадрес 2)
   uint16_t sa3_b[32]; //!< Данные из МФЦИ в БГС (подадрес 3)
} mfci_to_bgs_mkio_b_t;

//! Данные из МФЦИ в БГС (1 Гц, для передачи в БГС по SpaceWire и в адресных подадресах 1-3 МКИО-3.1)
typedef union mfci_to_bgs_b_t {
   mfci_to_bgs_sw_b_t sw_b;     //!< Данные из МФЦИ в БГС (для передачи в БГС по SpaceWire)
   mfci_to_bgs_mkio_b_t mkio_b; //!< Данные из МФЦИ в БГС (для передачи в адресных подадресах 1-3)
} mfci_to_bgs_b_t;

//! Данные контрольных сумм (1 Гц, только для передачи по SpaceWire)
typedef struct mfci_in_blocks_crc_sw_b_t {
   uint16_t                    crc_start_index;              //!< Индекс первого элемента в массиве crc_b //(min:0 max:59 bits:4..19 lsb:1)
   uint16_t                    crc_count;                    //!< Общее количество контрольных сумм для передачи crc_b //(min:0 max:60 bits:4..19 lsb:1)
   mfci_in_blocks_crc_unit_b_t crc_b[CRC_PO_PER_MESSAGE_IN]; //!< Версии и контрольные суммы ПО модулей
} mfci_in_blocks_crc_sw_b_t;

//! Входное сообщение МФЦИ c данными контрольных сумм (МКИО-3.1, 1 Гц, фрагмент 1-3)
typedef struct mfci_in_blocks_crc_mkio_b_t {
   uint16_t                         mfci_format;     //!< Кадр МФЦИ (MFCI_FORMAT_BLOCKS_CRC)
   uint16_t                         reserve;         //!< Резерв
   mfci_in_blocks_crc_mkio_id_1_b_t id_1_b;          //!< Слово 1 идентификации данных о сборке ПО модуля/системы
   mfci_in_blocks_crc_mkio_id_2_b_t id_2_b;          //!< Слово 2 идентификации данных о сборке ПО модуля/системы
   uint16_t                         crc_start_index; //!< Индекс передаваемого элемента контрольных сумм (индекс модуля) //(min:0 max:59 bits:4..19 lsb:1)
   uint16_t                         crc_count;       //!< Общее количество контрольных сумм для передачи crc_b //(min:0 max:60 bits:4..19 lsb:1)
   mfci_in_blocks_crc_unit_b_t      crc_b;           //!< Версии и контрольные суммы ПО модуля
} mfci_in_blocks_crc_mkio_b_t;

//! Входные данные МФЦИ на частоте 25 Гц от БИС (подадреса 1-6 МКИО-3.1)
typedef struct mfci_in_25hz_bis_b_t {
   uint32_t         counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_sa_1_b_t sa_1_b;  //!< Входное сообщение МФЦИ, подадрес 1 МКИО-3.1
   mfci_in_sa_2_b_t sa_2_b;  //!< Входное сообщение МФЦИ, подадрес 2 МКИО-3.1
   mfci_in_sa_3_b_t sa_3_b;  //!< Входное сообщение МФЦИ, подадрес 3 МКИО-3.1
   mfci_in_sa_4_b_t sa_4_b;  //!< Входное сообщение МФЦИ, подадрес 4 МКИО-3.1
   mfci_in_sa_5_b_t sa_5_b;  //!< Входное сообщение МФЦИ, подадрес 5 МКИО-3.1
   mfci_in_sa_6_b_t sa_6_b;  //!< Входное сообщение МФЦИ, подадрес 6 МКИО-3.1
} mfci_in_25hz_bis_b_t;

//! Входные данные МФЦИ на частоте 12.5 Гц от БИС (подадреса 7-18 МКИО-3.1)
typedef struct mfci_in_12hz_bis_b_t {
   uint32_t          counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_sa_7_b_t  sa_7_b;  //!< Входное сообщение МФЦИ, подадрес 7 МКИО-3.1
   mfci_in_sa_8_b_t  sa_8_b;  //!< Входное сообщение МФЦИ, подадрес 8 МКИО-3.1
   mfci_in_sa_9_b_t  sa_9_b;  //!< Входное сообщение МФЦИ, подадрес 9 МКИО-3.1
   mfci_in_sa_10_b_t sa_10_b; //!< Входное сообщение МФЦИ, подадрес 10 МКИО-3.1
   mfci_in_sa_11_b_t sa_11_b; //!< Входное сообщение МФЦИ, подадрес 11 МКИО-3.1
   mfci_in_sa_12_b_t sa_12_b; //!< Входное сообщение МФЦИ, подадрес 12 МКИО-3.1
   mfci_in_sa_13_b_t sa_13_b; //!< Входное сообщение МФЦИ, подадрес 13 МКИО-3.1
   mfci_in_sa_14_b_t sa_14_b; //!< Входное сообщение МФЦИ, подадрес 14 МКИО-3.1
   mfci_in_sa_15_b_t sa_15_b; //!< Входное сообщение МФЦИ, подадрес 15 МКИО-3.1
   mfci_in_sa_16_b_t sa_16_b; //!< Входное сообщение МФЦИ, подадрес 16 МКИО-3.1
   mfci_in_sa_17_b_t sa_17_b; //!< Входное сообщение МФЦИ, подадрес 17 МКИО-3.1
   mfci_in_sa_18_b_t sa_18_b; //!< Входное сообщение МФЦИ, подадрес 18 МКИО-3.1
} mfci_in_12hz_bis_b_t;

//! Входные данные МФЦИ на частоте 12.5 Гц от БЦВМ (подадреса 1-22, 26 МКИО-3.2)
typedef struct mfci_in_12hz_bcvm_b_t {
   uint32_t                 counter;            //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_suo_50x_1_b_t    suo_50x_1_b;        //!< Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 1 АУР), подадрес 1 МКИО 3.2
   mfci_in_suo_50x_2_b_t    suo_50x_2_b;        //!< Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 1 АУР), подадрес 2 МКИО 3.2
   mfci_in_suo_50x_3_b_t    suo_50x_3_b;        //!< Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 2 АУР), подадрес 3 МКИО 3.2
   mfci_in_suo_50x_4_20_b_t suo_50x_4_20_b[17]; //!< Входное сообщение МФЦИ c данными кадра СУО-504/506 (из раздела 1/2 АУР), подадрес 4-20 МКИО 3.2
   mfci_in_suo_50x_21_b_t   suo_50x_21_b;       //!< Входное сообщение БГС c данными кадра СУО-504/506 (из МФЦИ), подадрес 21 МКИО 3.2
   mfci_in_suo_50x_22_b_t   suo_50x_22_b;       //!< Входное сообщение БГС c данными кадра СУО-504/506 (из МФЦИ), подадрес 22 МКИО 3.2
   mfci_in_suo_50x_23_b_t   suo_50x_23_b;       //!< Входное сообщение БГС c данными кадра СУО-504/506 (из МФЦИ), подадрес 23 МКИО 3.2
   mfci_in_suo_iipa_b_t     suo_iipa_b;         //!< Входное сообщение МФЦИ c данными кадра СУО-ИИПЭ, подадрес 26 МКИО 3.2
} mfci_in_12hz_bcvm_b_t;

//! Входные данные МФЦИ на частоте 6.25 Гц от БИС (подадреса 19-24, 29-30 МКИО-3.1)
typedef struct mfci_in_6hz_bis_b_t {
   uint32_t                counter;       //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_sa_19_b_t       sa_19_b;       //!< Входное сообщение МФЦИ, подадрес 19 МКИО-3.1
   mfci_in_sa_20_b_t       sa_20_b;       //!< Входное сообщение МФЦИ, подадрес 20 МКИО-3.1
   mfci_in_sa_21_b_t       sa_21_b;       //!< Входное сообщение МФЦИ, подадрес 21 МКИО-3.1
   mfci_in_sa_22_b_t       sa_22_b;       //!< Входное сообщение МФЦИ, подадрес 22 МКИО-3.1
   mfci_in_sa_23_b_t       sa_23_b;       //!< Входное сообщение МФЦИ, подадрес 23 МКИО-3.1
   mfci_in_sa_24_b_t       sa_24_b;       //!< Входное сообщение МФЦИ, подадрес 24 МКИО-3.1
   mfci_in_active_path_b_t active_path_b; //!< Входное сообщение МФЦИ с траекторией выхода на активный участок маршрута (подадрес 29 МКИО-3.1)
   mfci_in_flight_plan_b_t flight_plan_b; //!< Входное сообщение МФЦИ с планом полета (подадрес 30 МКИО-3.1)
} mfci_in_6hz_bis_b_t;

//! Входные данные МФЦИ на частоте 6.25 Гц от БЦВМ (подадреса 24, 27-29 МКИО-3.2)
typedef struct mfci_in_6hz_bcvm_b_t {
   uint32_t         counter;             //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_fovb_b_t fovb_b;              //!< Входное сообщение МФЦИ c данными ФОВБ (подадрес 24 МКИО-3.2)
   mfci_in_asu_b_t  asu_b[ASU_SA_COUNT]; //!< Входное сообщение МФЦИ с данными АСУ (подадреса 27-29 МКИО-3.2)
} mfci_in_6hz_bcvm_b_t;

//! Входные данные МФЦИ на частоте 1 Гц от БИС (подадреса 25-28 МКИО-3.1, адресные подадреса 1-3, данные из МФЦИ в БГС)
typedef struct mfci_in_1hz_bis_b_t {
   uint32_t                 counter;        //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_sa_25_b_t        sa_25_b;        //!< Входные данные МФЦИ (подадрес 25 по МКИО-3.1)
   mfci_in_svr_b_t          svr_b;          //!< Входное сообщение МФЦИ c данными кадра СВР (подадрес 26 МКИО-3.1)
   mfci_in_bask_1_b_t       bask_1_b;       //!< Входное сообщение МФЦИ c данными кадра БАСК (фрагмент 1, подадрес 26 МКИО-3.1)
   mfci_in_bask_2_b_t       bask_2_b;       //!< Входное сообщение МФЦИ c данными кадра БАСК (фрагмент 2, подадрес 27 МКИО-3.1)
   mfci_in_bask_3_b_t       bask_3_b;       //!< Входное сообщение МФЦИ c данными кадра БАСК (фрагмент 3, подадрес 28 МКИО-3.1)
   mfci_in_msrp_1_b_t       msrp_1_b;       //!< Входное сообщение МФЦИ c данными кадра МСПР (фрагмент 1, подадрес 26 МКИО-3.1)
   mfci_in_msrp_2_b_t       msrp_2_b;       //!< Входное сообщение МФЦИ c данными кадра МСПР (фрагмент 2, подадрес 27 МКИО-3.1)
   mfci_in_blocks_1_b_t     blocks_1_b;     //!< Входное сообщение МФЦИ c данными кадра БЛОКИ (фрагмент 1, подадрес 26 МКИО-3.1)
   mfci_in_blocks_2_b_t     blocks_2_b;     //!< Входное сообщение МФЦИ c данными кадра БЛОКИ (фрагмент 2, подадрес 27 МКИО-3.1)
   mfci_in_blocks_3_b_t     blocks_3_b;     //!< Входное сообщение МФЦИ c данными кадра БЛОКИ (фрагмент 3, подадрес 28 МКИО-3.1)
   mfci_in_blocks_szi_1_b_t blocks_szi_1_b; //!< Входное сообщение МФЦИ c данными кадра БЛОКИ-СЗИ (фрагмент 1, подадрес 26 МКИО-3.1)
   mfci_in_tar_b_t          tar_b;          //!< Входное сообщение МФЦИ c данными кадра ТАР (подадрес 26 МКИО-3.1)
   mfci_to_bgs_b_t          mfci_to_bgs_b;  //!< Данные из МФЦИ в БГС (для передачи в БГС по SpaceWire и в адресных подадресах 1-3 МКИО-3.1)
} mfci_in_1hz_bis_b_t;

//! Входные данные МФЦИ на частоте 1 Гц от БЦВМ (подадреса 25, 30 МКИО-3.2)
typedef struct mfci_in_1hz_bcvm_b_t {
   uint32_t                 counter;        //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_blocks_szi_2_b_t blocks_szi_2_b; //!< Входное сообщение МФЦИ c данными кадра БЛОКИ-СЗИ (фрагмент 2, подадрес 25 МКИО-3.2)
   mfci_in_asu_u19_b_t      asu_u19_b;      //!< Входные сообщение МФЦИ с данными АСУ и 19-ДА (подадрес 30 МКИО-3.2)
} mfci_in_1hz_bcvm_b_t;

//! Входные данные МФЦИ на частоте 25 Гц
typedef struct mfci_in_25hz_b_t {
   uint32_t             counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_25hz_bis_b_t bis_b;   //!< Входные данные МФЦИ на частоте 25 Гц от БИС (подадреса 1-6 МКИО-3.1)
} mfci_in_25hz_b_t;

//! Входные данные МФЦИ на частоте 12.5 Гц
typedef struct mfci_in_12hz_b_t {
   uint32_t              counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_12hz_bis_b_t  bis_b;   //!< Входные данные МФЦИ на частоте 12.5 Гц от БИС (подадреса 7-18 МКИО-3.1)
   mfci_in_12hz_bcvm_b_t bcvm_b;  //!< Входные данные МФЦИ на частоте 12.5 Гц от БЦВМ (подадреса 1-23, 26 МКИО-3.2)
} mfci_in_12hz_b_t;

//! Входные данные МФЦИ на частоте 6.25 Гц
typedef struct mfci_in_6hz_b_t {
   uint32_t             counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_6hz_bis_b_t  bis_b;   //!< Входные данные МФЦИ на частоте 6.25 Гц от БИС (подадреса 19-24, 29-30 МКИО-3.1)
   mfci_in_6hz_bcvm_b_t bcvm_b;  //!< Входные данные МФЦИ на частоте 6.25 Гц от БЦВМ (подадреса 24, 27-29 МКИО-3.2)
} mfci_in_6hz_b_t;

//! Входные данные МФЦИ на частоте 1 Гц
typedef struct mfci_in_1hz_b_t {
   uint32_t             counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_1hz_bis_b_t  bis_b;   //!< Входные данные МФЦИ на частоте 1 Гц от БИС (подадреса 25-28 МКИО-3.1, слова сигналов УПР)
   mfci_in_1hz_bcvm_b_t bcvm_b;  //!< Входные данные МФЦИ на частоте 1 Гц от БЦВМ (подадреса 25, 30 МКИО-3.2)
} mfci_in_1hz_b_t;

//! Входные данные МФЦИ
typedef struct mfci_in_b_t {
   uint32_t                    counter;                    //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_25hz_b_t            mfci_in_25hz_b;             //!< Входные данные МФЦИ на частоте 25 Гц
   mfci_in_12hz_b_t            mfci_in_12hz_b;             //!< Входные данные МФЦИ на частоте 12.5 Гц
   mfci_in_6hz_b_t             mfci_in_6hz_b;              //!< Входные данные МФЦИ на частоте 6.25 Гц
   mfci_in_1hz_b_t             mfci_in_1hz_b;              //!< Входные данные МФЦИ на частоте 1 Гц
   mfci_in_blocks_crc_mkio_b_t blocks_crc_b[CRC_SA_COUNT]; //!< Входное сообщение МФЦИ c данными кадра БЛОКИ-КС (фрагмент 1-3, подадрес 26-28 МКИО-3.1)
} mfci_in_b_t;

//! Входные данные МГ-100 БГС на частоте 25 Гц
typedef struct bgs_in_25hz_b_t {
   uint32_t         counter;        //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_25hz_b_t mfci_in_25hz_b; //!< Входные данные МФЦИ на частоте 25 Гц
   mfci_in_12hz_b_t mfci_in_12hz_b; //!< Входные данные МФЦИ на частоте 12.5 Гц
   mfci_in_6hz_b_t  mfci_in_6hz_b;  //!< Входные данные МФЦИ на частоте 6.25 Гц
} bgs_in_25hz_b_t;

//! Входные данные МГ-100 БГС на частоте 12.5 Гц
typedef struct bgs_in_12hz_b_t {
   uint32_t        counter;       //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_1hz_b_t mfci_in_1hz_b; //!< Входные данные МФЦИ на частоте 1 Гц
} bgs_in_12hz_b_t;

//! Входные данные МГ-100 БГС на частоте 12.5 Гц
typedef struct bgs_in_crc_b_t {
   uint32_t                  counter;                     //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_in_blocks_crc_sw_b_t blocks_crc_b[BGS_CPU_COUNT]; //!< Данные контрольных сумм (только для передачи по SpaceWire)
} bgs_in_crc_b_t;

//! Выходные данные МГ-100 БГС
typedef struct bgs_out_queuing_b_t {
   uint8_t                     bgs_cpu_la;                        //!< Логический номер процессора, с которого прислали данные к/с //(min:0 max:255)
   mfci_in_blocks_crc_unit_b_t out_crc_b[CRC_PO_PER_MESSAGE_OUT]; //!< Данные контрольных сумм (только для передачи по SpaceWire)
} bgs_out_queuing_b_t;

//! Выходные данные МФЦИ (подадрес 1 МКИО-3.1/3.2, состояние и управляющие сигналы)
typedef struct mfci_out_sa1_b_t {
   mfci_status_word_1_b_t     status_word_1_b;          //!< Слово 1 состояния
   mfci_status_word_2_b_t     status_word_2_b;          //!< Слово 2 состояния
   mfci_status_word_3_b_t     status_word_3_b;          //!< Слово 3 состояния
   upr_flag_word_common_1_b_t upr_flag_word_common_1_b; //!< Слово 1 сигналов УПР (общее для всех кадров МФЦИ)
   upr_flag_word_common_2_b_t upr_flag_word_common_2_b; //!< Слово 2 сигналов УПР (общее для всех кадров МФЦИ)
   upr_flag_word_common_3_b_t upr_flag_word_common_3_b; //!< Слово 3 сигналов УПР (общее для всех кадров МФЦИ)
   upr_flag_word_common_4_b_t upr_flag_word_common_4_b; //!< Слово 4 сигналов УПР (общее для всех кадров МФЦИ)
   upr_flag_word_format_b_t   upr_flag_word_format_1_b; //!< Слово 1 сигналов УПР для индицируемого кадра
   upr_flag_word_format_b_t   upr_flag_word_format_2_b; //!< Слово 2 сигналов УПР для индицируемого кадра
   upr_flag_word_format_b_t   upr_flag_word_format_3_b; //!< Слово 3 сигналов УПР для индицируемого кадра
   upr_flag_word_format_b_t   upr_flag_word_format_4_b; //!< Слово 4 сигналов УПР для индицируемого кадра
} mfci_out_sa1_b_t;

//! Выходные данные МФЦИ (подадрес 2 МКИО-3.1, версии и контрольные суммы ПО)
typedef struct mfci_out_sa2_b_t {
   uint16_t         mv_fpo_revision;       //!< ФПО МB: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t mv_fpo_version_b;      //!< ФПО МB: Версия и подверсия
   mfci_date_b_t    mv_fpo_date_b;         //!< ФПО МB: Дата сборки
   uint16_t         mv_fpo_crc_high;       //!< ФПО МB: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         mv_fpo_crc_low;        //!< ФПО МB: Контрольная сумма (младшее слово)
   uint16_t         mv_poos_revision;      //!< ПО-ОС МВ: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t mv_poos_version_b;     //!< ПО-ОС МВ: Версия и подверсия
   mfci_date_b_t    mv_poos_date_b;        //!< ПО-ОС МВ: Дата сборки
   uint16_t         mv_poos_crc_high;      //!< ПО-ОС МВ: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         mv_poos_crc_low;       //!< ПО-ОС МВ: Контрольная сумма (младшее слово)
   uint16_t         mg24_fonts_revision;   //!< Шрифты МГ24: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t mg24_fonts_version_b;  //!< Шрифты МГ24: Версия и подверсия
   mfci_date_b_t    mg24_fonts_date_b;     //!< Шрифты МГ24: Дата сборки
   uint16_t         mg24_fonts_crc_high;   //!< Шрифты МГ24: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         mg24_fonts_crc_low;    //!< Шрифты МГ24: Контрольная сумма (младшее слово)
   uint16_t         mg24_bpo_revision;     //!< БПО МГ24: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t mg24_bpo_version_b;    //!< БПО МГ24: Версия и подверсия
   mfci_date_b_t    mg24_bpo_date_b;       //!< БПО МГ24: Дата сборки
   uint16_t         mg24_bpo_crc_high;     //!< БПО МГ24: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         mg24_bpo_crc_low;      //!< БПО МГ24: Контрольная сумма (младшее слово)
   uint16_t         mg428_fonts_revision;  //!< Шрифты МГ428: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t mg428_fonts_version_b; //!< Шрифты МГ428: Версия и подверсия
   mfci_date_b_t    mg428_fonts_date_b;    //!< Шрифты МГ428: Дата сборки
   uint16_t         mg428_fonts_crc_high;  //!< Шрифты МГ428: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         mg428_fonts_crc_low;   //!< Шрифты МГ428: Контрольная сумма (младшее слово)
   uint16_t         mg428_bpo_revision;    //!< БПО МГ428: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t mg428_bpo_version_b;   //!< БПО МГ428: Версия и подверсия
   mfci_date_b_t    mg428_bpo_date_b;      //!< БПО МГ428: Дата сборки
   uint16_t         mg428_bpo_crc_high;    //!< БПО МГ428: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         mg428_bpo_crc_low;     //!< БПО МГ428: Контрольная сумма (младшее слово)
} mfci_out_sa2_b_t;

//! Выходные данные МФЦИ (подадрес 3 МКИО-3.1, версии и контрольные суммы ПО)
typedef struct mfci_out_sa3_b_t {
   uint16_t         config_revision;         //!< Конфигурация: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t config_version_b;        //!< Конфигурация: Версия и подверсия
   mfci_date_b_t    config_date_b;           //!< Конфигурация: Дата сборки
   uint16_t         config_crc_high;         //!< Конфигурация: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         config_crc_low;          //!< Конфигурация: Контрольная сумма (младшее слово)
   uint16_t         signals_table_revision;  //!< Таблица данных сигнализации: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t signals_table_version_b; //!< Таблица данных сигнализации: Версия и подверсия
   mfci_date_b_t    signals_table_date_b;    //!< Таблица данных сигнализации: Дата сборки
   uint16_t         signals_table_crc_high;  //!< Таблица данных сигнализации: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         signals_table_crc_low;   //!< Таблица данных сигнализации: Контрольная сумма (младшее слово)
   uint16_t         kkd_table_revision;      //!< Таблица данных ККД: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t kkd_table_version_b;     //!< Таблица данных ККД: Версия и подверсия
   mfci_date_b_t    kkd_table_date_b;        //!< Таблица данных ККД: Дата сборки
   uint16_t         kkd_table_crc_high;      //!< Таблица данных ККД: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         kkd_table_crc_low;       //!< Таблица данных ККД: Контрольная сумма (младшее слово)
   uint16_t         rla_table_revision;      //!< Таблица данных РЛЭ: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t rla_table_version_b;     //!< Таблица данных РЛЭ: Версия и подверсия
   mfci_date_b_t    rla_table_date_b;        //!< Таблица данных РЛЭ: Дата сборки
   uint16_t         rla_table_crc_high;      //!< Таблица данных РЛЭ: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         rla_table_crc_low;       //!< Таблица данных РЛЭ: Контрольная сумма (младшее слово)
   uint16_t         bask_table_revision;     //!< Таблица данных шаблонов БАСК: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t bask_table_version_b;    //!< Таблица данных шаблонов БАСК: Версия и подверсия
   mfci_date_b_t    bask_table_date_b;       //!< Таблица данных шаблонов БАСК: Дата сборки
   uint16_t         bask_table_crc_high;     //!< Таблица данных шаблонов БАСК: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         bask_table_crc_low;      //!< Таблица данных шаблонов БАСК: Контрольная сумма (младшее слово)
   uint16_t         load_table_revision;     //!< Таблица загрузки: Редакция //(min:1 max:99 bits:4..19 lsb:1)
   mfci_version_b_t load_table_version_b;    //!< Таблица загрузки: Версия и подверсия
   mfci_date_b_t    load_table_date_b;       //!< Таблица загрузки: Дата сборки
   uint16_t         load_table_crc_high;     //!< Таблица загрузки: Контрольная сумма (старшее слово) //(min:0 max:4294967295 bits:4..19 lsb:1)
   uint16_t         load_table_crc_low;      //!< Таблица загрузки: Контрольная сумма (младшее слово)
} mfci_out_sa3_b_t;

//! Выходные данные МФЦИ (подадрес 4 МКИО-3.2, команды из МФЦИ в АСУ)
typedef struct mfci_out_sa4_b_t {
   asu_header_word_1_b_t     asu_header_word_1_b;                  //!< Заголовок сообщения АСУ (слово 1)
   asu_header_word_2_b_t     asu_header_word_2_b;                  //!< Заголовок сообщения АСУ (слово 2)
   asu_header_word_3_b_t     asu_header_word_3_b;                  //!< Заголовок сообщения АСУ (слово 3)
   asu_header_word_4_b_t     asu_header_word_4_b;                  //!< Заголовок сообщения АСУ (слово 4)
   asu_header_word_5_b_t     asu_header_word_5_b;                  //!< Заголовок сообщения АСУ (слово 5)
   asu_header_word_6_b_t     asu_header_word_6_b;                  //!< Заголовок сообщения АСУ (слово 6)
   asu_header_word_7_out_b_t asu_header_word_7_b;                  //!< Заголовок сообщения АСУ (слово 7)
   asu_header_word_8_b_t     asu_header_word_8_b;                  //!< Заголовок сообщения АСУ (слово 8)
   uint16_t                  asu_segment[ASU_SEGMENT_WORDS_COUNT]; //!< Cегмент команды из СОИ/МФЦИ в АСУ
} mfci_out_sa4_b_t;

//! Выходные данные МФЦИ (подадрес 5 МКИО-3.1, координаты курсора МУП)
typedef struct mfci_out_sa5_b_t {
   uint16_t mup_format;         //!< Кадр, для которого определены координаты курсора МУП (mfci_format_t, MFCI_FORMAT_ND - координаты не определены) //(min:0 max:33 bits:4..19 lsb:1)
   uint16_t mup_latitude_high;  //!< Географическая широта курсора МУП, старшее слово //(min:-90 max:90 signed:4 bits:5..19 msb:45°)
   uint16_t mup_latitude_low;   //!< Географическая широта курсора МУП, младшее слово
   uint16_t mup_longitude_high; //!< Географическая долгота курсора МУП, старшее слово //(min:-180 max:180 signed:4 bits:5..19 msb:90°)
   uint16_t mup_longitude_low;  //!< Географическая долгота курсора МУП, младшее слово
} mfci_out_sa5_b_t;

//! Выходные данные МФЦИ (подадрес 6 МКИО-3.2, команды из МФЦИ в МФПУ)
typedef struct mfci_out_sa6_b_t {
   uint16_t asu_template_text[32]; //!< Текст шаблона донесения из МФЦИ в МФПУ в байтах (фрагмент 1)
} mfci_out_sa6_b_t;

//! Выходные данные МФЦИ (подадрес 7 МКИО-3.2, команды из МФЦИ в МФПУ)
typedef struct mfci_out_sa7_b_t {
   uint16_t asu_template_text[32]; //!< Текст шаблона донесения из МФЦИ в МФПУ в байтах (фрагмент 2)
} mfci_out_sa7_b_t;

//! Выходные данные МФЦИ (подадрес 8 МКИО-3.2, данные ТИ и курсора СУО-504/506 из МФЦИ в БГС)
typedef struct mfci_out_sa8_b_t {
   mfci_soi_ti_cursor_b_t ti_cursor_b; //!< Данными о ТИ и перемещении центра ОРЗП в кадре СУО-504/506 (для передачи в БГС)
} mfci_out_sa8_b_t;

//! Выходные данные МФЦИ для БИС (МКИО-3.1)
typedef struct mfci_out_bis_b_t {
   uint32_t         counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_out_sa1_b_t sa1_b;   //!< Выходные данные МФЦИ (подадрес 1 МКИО-3.1, состояние и управляющие сигналы)
   mfci_out_sa5_b_t sa5_b;   //!< Выходные данные МФЦИ (подадрес 5 МКИО-3.1, координаты курсора МУП)
} mfci_out_bis_b_t;

//! Выходные данные МФЦИ для БИС (версии и контрольные суммы ПО, МКИО-3.1)
typedef struct mfci_out_crc_b_t {
   uint32_t         counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_out_sa2_b_t sa2_b;   //!< Выходные данные МФЦИ (подадрес 2 МКИО-3.1, версии и контрольные суммы ПО)
   mfci_out_sa3_b_t sa3_b;   //!< Выходные данные МФЦИ (подадрес 3 МКИО-3.1, версии и контрольные суммы ПО)
} mfci_out_crc_b_t;

//! Выходные данные МФЦИ для БЦВМ (МКИО-3.2)
typedef struct mfci_out_bcvm_b_t {
   uint32_t         counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_out_sa1_b_t sa1_b;   //!< Выходные данные МФЦИ (подадрес 1 МКИО-3.2, состояние и управляющие сигналы)
   mfci_out_sa4_b_t sa4_b;   //!< Выходные данные МФЦИ (подадрес 4 МКИО-3.2, команды из МФЦИ в АСУ)
   mfci_out_sa6_b_t sa6_b;   //!< Выходные данные МФЦИ (подадрес 6 МКИО-3.2, команды из МФЦИ в МФПУ)
   mfci_out_sa7_b_t sa7_b;   //!< Выходные данные МФЦИ (подадрес 7 МКИО-3.2, команды из МФЦИ в МФПУ)
   mfci_out_sa8_b_t sa8_b;   //!< Выходные данные МФЦИ (подадрес 8 МКИО-3.2, ТИ и курсор СУО-504/506, передается из МФЦИ в БГС)
} mfci_out_bcvm_b_t;

//! Выходные данные МФЦИ
typedef struct mfci_out_b_t {
   uint32_t          counter; //!< Счетчик контроля достоверности данных //(min:0 max:4294967295)
   mfci_out_bis_b_t  bis_b;   //!< Выходные данные МФЦИ для БИС (МКИО-3.1)
   mfci_out_crc_b_t  crc_b;   //!< Выходные данные МФЦИ для БИС (версии и контрольные суммы ПО, МКИО-3.1)
   mfci_out_bcvm_b_t bcvm_b;  //!< Выходные данные МФЦИ для БЦВМ (МКИО-3.2)
} mfci_out_b_t;

//! Данные МФЦИ
typedef struct mfci_b_t {
   mfci_in_b_t  mfci_in_b;  //!< Входные данные МФЦИ
   mfci_out_b_t mfci_out_b; //!< Выходные данные МФЦИ
} mfci_b_t;
