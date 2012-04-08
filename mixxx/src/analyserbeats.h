/* Beat Tracking test via vamp-plugins
 * analyserbeats.h
 *
 *  Created on: 16/mar/2011
 *      Author: Vittorio Colao
 */

#ifndef ANALYSERBEATS_H_
#define ANALYSERBEATS_H_

#include "analyser.h"
#include "configobject.h"
#include "vamp/vampanalyser.h"

class AnalyserBeats: public Analyser {
  public:
    AnalyserBeats(ConfigObject<ConfigValue> *_config);
    virtual ~AnalyserBeats();

    void initialise(TrackPointer tio, int sampleRate, int totalSamples);
    void process(const CSAMPLE *pIn, const int iLen);
    void finalise(TrackPointer tio);

  private:
    QVector<double> correctedBeats(QVector<double> rawbeats);
    bool m_bShouldAnalyze;

    bool m_bPreferencesBeatDetectionEnabled;
    bool m_bPreferencesReanalyzeOldBpm;
    bool m_bPreferencesFixedTempo;
    bool m_bPreferencesOffsetCorrection;

    ConfigObject<ConfigValue> *m_pConfigAVT;
    VampAnalyser* m_pVamp;
    int m_iSampleRate, m_iTotalSamples;
    int m_iMinBpm, m_iMaxBpm;
    QString m_sSubver;
};

#endif /* ANALYSERVAMPTEST_H_ */
