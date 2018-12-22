// Separate function definitions from pong.c.
#ifndef PONG_H
#define PONG_H

void InitialiseSprites(void);
void CopyOAM(void);
void MoveSprite(OAMEntry* sp, int x, int y);
void MoveBall(void);

#endif
