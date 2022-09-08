/*!
 * @file module_mfpu.h
 * @brief Библиотека модуля МФПУ для тренажера объекта 70М
 * @author Илья Кулаков
 * @copyright АО ОКБ "Электроавтоматика", НИЦ-1
 * @details
 * #### Номер ВИДК
 *    нет
 * #### Комментарии
 *    нет
 */
#pragma once
#ifndef MODULE_MFPU_API
#if defined(_WIN32) && defined(MODULE_MFPU_EXPORTS)
#define MODULE_MFPU_API __declspec(dllexport)
#elif defined(_WIN32)
#define MODULE_MFPU_API __declspec(dllimport)
#elif defined(__GNUC__) && defined(MODULE_MFPU_EXPORTS)
#define MODULE_MFPU_API __attribute__((visibility("default")))
#else
#define MODULE_MFPU_API
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

//! Данные инициализации модуля МФПУ
typedef struct module_mfpu_init_data_t {
   unsigned int number;           //!< Номер МФПУ (1…3)
   unsigned int monitor_number;   //!< Номер монитора для вывода (нумерация с нуля)
   const char *font_filename;     //!< Путь к файлу со шрифтом МФПУ
   const char *shm_in_data_id;    //!< Идентификатор разделяемой памяти с входными данными
   const char *shm_out_data_id;   //!< Идентификатор разделяемой памяти с выходными данными
   const char *shm_in_buttons_id; //!< Идентификатор разделяемой памяти с кодом нажатой кнопки
   const char *shm_out_fires_id;  //!< Идентификатор разделяемой памяти с сигнальными огнями
} module_mfpu_init_data_t;

/*!
 * Запускает и инициализирует модуль МФПУ
 * @param init_data Данные инициализации
 * @return Результат выполнения (0 - успешно)
 */
MODULE_MFPU_API int module_mfpu_create(const module_mfpu_init_data_t *init_data);

/*!
 * Останавливает модуль МФПУ
 * @return Результат выполнения (0 - успешно)
 */
MODULE_MFPU_API int module_mfpu_destroy(void);

/*!
 * Обновляет состояние модуля МФПУ
 * @return Результат выполнения (0 - успешно)
 */
MODULE_MFPU_API int module_mfpu_update(void);

#ifdef __cplusplus
}
#endif
