/*
 * Mock include file to test building with STM32Cube
 */

#define FLASH_FLAG_EOP 0
#define FLASH_FLAG_OPERR 0
#define FLASH_FLAG_WRPERR 0
#define FLASH_FLAG_PGAERR 0
#define FLASH_FLAG_PGPERR 0
#define FLASH_FLAG_PGSERR 0
#define FLASH_TYPEERASE_SECTORS 0
#define FLASH_TYPEPROGRAM_WORD 0
#define FLASH_VOLTAGE_RANGE_3 0

#define HAL_OK 0

typedef struct {
    uint32_t TypeErase;
    uint32_t VoltageRange;
    uint32_t NbSectors;
    uint32_t Sector;
} FLASH_EraseInitTypeDef;

typedef uint32_t HAL_StatusTypeDef;

void __HAL_FLASH_CLEAR_FLAG(uint32_t flags);
void HAL_FLASH_Lock(void);
void HAL_FLASH_Program(uint32_t s, uint32_t a, uint32_t d);
void HAL_FLASH_Unlock(void);
uint32_t HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *s, uint32_t *e);
