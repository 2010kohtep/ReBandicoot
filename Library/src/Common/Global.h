#pragma once

extern unsigned char *GameInst;

extern bool *pbPlayerGodMode;
extern bool *pbEnemiesUndying;
extern bool *pbShowEntityNames;

extern bool *pbDisplayHealth;
extern bool *pbPhysicsProperties;

#define bPlayerGodMode   (*pbPlayerGodMode)
#define bEnemiesUndying  (*pbEnemiesUndying)
#define bShowEntityNames (*pbShowEntityNames)

#define bDisplayHealth     (*pbDisplayHealth)
#define bPhysicsProperties (*pbPhysicsProperties)