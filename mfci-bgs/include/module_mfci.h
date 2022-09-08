/*!
 * @file module_mfci.h
 * @brief Библиотека модуля МФЦИ/БГС для имитаторов и тренажеров объктов 45.03М, 70М и 70М-506
 * @author Игорь Рогов
 * @author Илья Кулаков
 * @copyright АО ОКБ "Электроавтоматика", НИЦ-1
 * @details
 * #### Номер ВИДК
 *    нет
 * #### Комментарии
 *    нет
 */
#pragma once
#ifndef MODULE_MFCI_API
#if defined(_WIN32) && defined(MODULE_MFCI_EXPORTS)
#define MODULE_MFCI_API __declspec(dllexport)
#elif defined(_WIN32)
#define MODULE_MFCI_API __declspec(dllimport)
#elif defined(__GNUC__) && defined(MODULE_MFCI_EXPORTS)
#define MODULE_MFCI_API __attribute__((visibility("default")))
#else
#define MODULE_MFCI_API
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

//! Режим обмена данных модуля МФЦИ/БГС
typedef enum module_mfci_mode_t {
   MODULE_MFCI_MODE_EA,   //!< Режим обмена данных через UDP (для стенда ЭА)
   MODULE_MFCI_MODE_MIEA, //!< Режим обмена данных через UDP (для стенда МИЭА)
   MODULE_MFCI_MODE_TU,   //!< Режим обмена данных напрямую через module_mfci_set_sa, module_mfci_get_sa (для филиала Ту)
   MODULE_MFCI_MODE_ESVO  //!< Режим обмена данных через разделяемую память (для тренажера ЭСВО)
} module_mfci_mode_t;

//! Данные инициализации модуля МФЦИ/БГС
typedef struct module_mfci_init_data_t {
   module_mfci_mode_t mode;       //!< Режим обмена данных
   unsigned int number;           //!< Номер МФЦИ (1…11)
   const char *font_filename;     //!< Путь к файлу со шрифтом МФЦИ (только для режима MODULE_MFCI_MODE_ESVO)
   const char *shm_in_data_id;    //!< Идентификатор разделяемой памяти с входными данными (только для режима MODULE_MFCI_MODE_ESVO)
   const char *shm_out_data_id;   //!< Идентификатор разделяемой памяти с выходными данными (только для режима MODULE_MFCI_MODE_ESVO)
   const char *shm_in_buttons_id; //!< Идентификатор разделяемой памяти с кодом нажатой кнопки (только для режима MODULE_MFCI_MODE_ESVO)
} module_mfci_init_data_t;

/*!
 * Запускает и инициализирует модуль МФЦИ/БГС
 * @param init_data Данные инициализации
 * @return Результат выполнения (0 - успешно)
 */
MODULE_MFCI_API int module_mfci_create(const module_mfci_init_data_t *init_data);

/*!
 * Останавливает модуль МФЦИ/БГС
 * @return Результат выполнения (0 - успешно)
 */
MODULE_MFCI_API int module_mfci_destroy(void);

/*!
 * Обновляет состояние модуля МФЦИ/БГС
 * @return Результат выполнения (0 - успешно)
 */
MODULE_MFCI_API int module_mfci_update(void);

/*!
 * Записывает данные подадреса в модуль МФЦИ/БГС
 * @param[in] channel_number Номер канала
 * @param[in] sa_number Номер подадреса
 * @param[in] sa Слова данных подадреса
 * @param[in] words_count Количество слов данных подадреса
 * @return Результат выполнения (0 - успешно)
 * @note Только для режима MODULE_MFCI_MODE_TU
 */
MODULE_MFCI_API int module_mfci_set_sa(const unsigned int channel_number, const unsigned int sa_number, const unsigned short *sa, const unsigned int words_count);

/*!
 * Читает данные подадреса из модуля МФЦИ/БГС
 * @param[in] channel_number Номер канала
 * @param[in] sa_number Номер подадреса
 * @param[out] sa Слова данных подадреса
 * @param[in] words_count Количество слов данных подадреса
 * @return Результат выполнения (0 - успешно)
 * @note Только для режима MODULE_MFCI_MODE_TU
 */
MODULE_MFCI_API int module_mfci_get_sa(const unsigned int channel_number, const unsigned int sa_number, unsigned short *sa, const unsigned int words_count);

#ifdef __cplusplus
}
#endif
