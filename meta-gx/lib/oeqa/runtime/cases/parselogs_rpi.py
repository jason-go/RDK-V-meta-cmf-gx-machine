from oeqa.runtime.cases.parselogs import *

rpi_errors = [
    'bcmgenet fd580000.genet: failed to get enet-eee clock',
    'bcmgenet fd580000.genet: failed to get enet-wol clock',
    'bcmgenet fd580000.genet: failed to get enet clock',
    'bcmgenet fd580000.ethernet: failed to get enet-eee clock',
    'bcmgenet fd580000.ethernet: failed to get enet-wol clock',
    'bcmgenet fd580000.ethernet: failed to get enet clock',
]

ignore_errors['sirius'] = rpi_errors + common_errors

class ParseLogsTestRpi(ParseLogsTest):
    pass
