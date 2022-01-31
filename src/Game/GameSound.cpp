#include "GameSound.h"
#include "System/Timer.h"
#include "Sound/SoundData.h"
#include "Sound/SoundPlayer.h"
#include "Sound/SoundList.h"

namespace GameSound
{
    void Initialize(uint8_t pin)
    {
        SoundList::Initialize();

        SoundPlayer::Initialize(pin);
    }

    void Update()
    {
        SoundPlayer::Update();
    }

    void OnPlay(SoundEnum soundEnum)
    {
        const auto& soundData = SoundList::GetSound(soundEnum);

        SoundPlayer::OnPlay(soundData);
    }
}