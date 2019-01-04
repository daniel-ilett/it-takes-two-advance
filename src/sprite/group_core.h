// Core group sprite data.

#ifndef GROUP_CORE_H
#define GROUP_CORE_H

const u16 tx_EarthData[] = {
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800, 0x3800, 0x3838,
                    0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838,
                    0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038,
                    0x3800, 0x0F0F, 0x0F0F, 0x0F0F, 0x0F0F, 0x0F0F, 0x0F0F, 0x0038, 0x0F00, 0x2A2A,
                    0x2A2A, 0x2A2A, 0x2A2A, 0x2A2A, 0x2A2A, 0x000F, 0x0F00, 0x0F2A, 0x2A2A, 0x2A2A,
                    0x2A0F, 0x0F2A, 0x2A2A, 0x000F, 0x0F00, 0x0F2A, 0x2A0F, 0x2A0F, 0x0F2A, 0x2A2A,
                    0x0F0F, 0x0038, 0x3800, 0x2A0F, 0x2A2A, 0x2A0F, 0x0F2A, 0x2A2A, 0x380F, 0x0038,
                    0x3800, 0x2A0F, 0x0F2A, 0x2A2A, 0x0F0F, 0x0F2A, 0x380F, 0x0038, 0x3800, 0x0F38,
                    0x380F, 0x0F0F, 0x0F38, 0x380F, 0x3838, 0x0038, 0x3800, 0x0F38, 0x3838, 0x0F38,
                    0x3838, 0x380F, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038,
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800,};

const u16 tx_FireData[] = {
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800, 0x3800, 0x3838,
                    0x3838, 0x1538, 0x3815, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x2915,
                    0x3815, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x1538, 0x1529, 0x3838, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x1538, 0x2929, 0x3815, 0x3838, 0x3838, 0x0038,
                    0x3800, 0x3838, 0x3838, 0x2915, 0x1529, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838,
                    0x3815, 0x1538, 0x2929, 0x3815, 0x3838, 0x0038, 0x3800, 0x3838, 0x1538, 0x3838,
                    0x2915, 0x3815, 0x3838, 0x0038, 0x3800, 0x3838, 0x1515, 0x1538, 0x2915, 0x1529,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x2915, 0x1515, 0x2915, 0x1529, 0x3838, 0x0038,
                    0x3800, 0x1538, 0x2929, 0x2915, 0x2929, 0x3815, 0x3838, 0x0038, 0x3800, 0x1538,
                    0x2929, 0x2929, 0x2929, 0x3815, 0x3815, 0x0038, 0x3800, 0x3838, 0x2915, 0x2929,
                    0x2929, 0x1529, 0x3838, 0x0038, 0x3800, 0x3838, 0x1538, 0x2915, 0x1529, 0x3815,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x1538, 0x3815, 0x3838, 0x3838, 0x0038,
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800,};

const u16 tx_WaterData[] = {
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800, 0x3800, 0x3838,
                    0x3838, 0x1238, 0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x2612,
                    0x3812, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x2612, 0x3812, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x2612, 0x3812, 0x3838, 0x3838, 0x0038,
                    0x3800, 0x3838, 0x1238, 0x2626, 0x1226, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838,
                    0x1238, 0x2626, 0x1226, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x2612, 0x2626,
                    0x2626, 0x3812, 0x3838, 0x0038, 0x3800, 0x3838, 0x2612, 0x2626, 0x2626, 0x3812,
                    0x3838, 0x0038, 0x3800, 0x1238, 0x2626, 0x2626, 0x2626, 0x1226, 0x3838, 0x0038,
                    0x3800, 0x1238, 0x2626, 0x2626, 0x1226, 0x1226, 0x3838, 0x0038, 0x3800, 0x1238,
                    0x2626, 0x2626, 0x2612, 0x1226, 0x3838, 0x0038, 0x3800, 0x3838, 0x2612, 0x2626,
                    0x2626, 0x3812, 0x3838, 0x0038, 0x3800, 0x3838, 0x1238, 0x2626, 0x1226, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x1212, 0x3812, 0x3838, 0x3838, 0x0038,
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800,};

const u16 tx_AirData[] = {
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800, 0x3800, 0x3838,
                    0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838,
                    0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x2626, 0x3838, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x2638, 0x3838, 0x2626, 0x3838, 0x2638, 0x0038,
                    0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x2626, 0x3826, 0x0038, 0x3800, 0x2638,
                    0x2626, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3826, 0x3838, 0x3826,
                    0x3838, 0x3838, 0x3838, 0x0038, 0x2600, 0x3838, 0x3838, 0x2638, 0x3826, 0x3838,
                    0x3838, 0x0026, 0x3800, 0x3838, 0x3838, 0x3838, 0x2638, 0x3838, 0x2638, 0x0038,
                    0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x2626, 0x3826, 0x0038, 0x3800, 0x2638,
                    0x2626, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038, 0x3800, 0x3826, 0x3838, 0x2626,
                    0x3838, 0x3826, 0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838, 0x2626, 0x3838,
                    0x3838, 0x0038, 0x3800, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x3838, 0x0038,
                    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3800,};

#endif