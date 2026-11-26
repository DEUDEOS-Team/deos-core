#ifndef DEOS_FAULT_H
#define DEOS_FAULT_H

#include <stdint.h>
#include <stdbool.h>
#include <deos/deos_icd.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Global wire-level fault IDs (deos_fault_id_t), severities
 * (deos_fault_severity_t), states (deos_fault_state_t), and string helpers
 * live exclusively in deos_protocol (<deos/deos_icd.h>, <deos/deos_frame.h>).
 */

/*
 * Fault Record Structure (Runtime)
 */
typedef struct
{
    uint16_t fault_id;
    uint8_t severity;
    uint8_t state;
    uint16_t occurrence_count;
    uint32_t last_occurrence_ms;
} deos_fault_record_t;

int deos_fault_raise_for_node(deos_node_id_t local_node, uint16_t fault_id, deos_fault_severity_t severity);
int deos_fault_set_inactive_for_node(deos_node_id_t local_node, uint16_t fault_id);
int deos_fault_latch_for_node(deos_node_id_t local_node, uint16_t fault_id);
int deos_fault_clear_for_node(deos_node_id_t local_node, uint16_t fault_id);
int deos_fault_clear_all_for_node(deos_node_id_t local_node);
bool deos_fault_is_active_for_node(deos_node_id_t local_node, uint16_t fault_id);

/*
 * Primary local node convenience wrappers
 */
int deos_fault_raise(uint16_t fault_id, deos_fault_severity_t severity);
int deos_fault_set_inactive(uint16_t fault_id);
int deos_fault_latch(uint16_t fault_id);
int deos_fault_clear(uint16_t fault_id);
int deos_fault_clear_all(void);
bool deos_fault_is_active(uint16_t fault_id);

#ifdef __cplusplus
}
#endif

#endif /* DEOS_FAULT_H */
