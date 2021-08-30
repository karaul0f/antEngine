#include "AudioPlayer.h"

namespace Audio
{
//-----------------------------------------------------------------
void AudioPlayer::Init()
{
	SetVolume(m_volumeLevel.GetFloatValue("Volume.Level"));
}
//-----------------------------------------------------------------
void AudioPlayer::PlaySound(Resources::Sound& sound)
{
	if (m_sounds.count(sound.GetFilePath()) == 0)
	{
		m_sounds[sound.GetFilePath()] = &sound.GetSound();
	}
	m_sounds[sound.GetFilePath()]->play();
}
//-----------------------------------------------------------------
void AudioPlayer::PlayMusic(Resources::Music& music, bool repeat = false)
{
	if (m_musics.count(music.GetFilePath()) == 0)
	{
		m_musics[music.GetFilePath()] = &music.GetMusic();
	}
	m_musics[music.GetFilePath()]->setLoop(repeat);
	m_musics[music.GetFilePath()]->play();
}
//-----------------------------------------------------------------
void AudioPlayer::StopAllSounds()
{
	for (auto& sound : m_sounds)
		sound.second->stop();
	
	for (auto& music : m_musics)
		music.second->stop();
}
//-----------------------------------------------------------------
void AudioPlayer::SetVolume(float volume)
{
	m_volumeLevel.SetFloatValue("Volume.Level", volume);
	sf::Listener::setGlobalVolume(m_volumeLevel.GetFloatValue("Volume.Level"));
}
//-----------------------------------------------------------------
float AudioPlayer::GetVolume()
{
	return m_volumeLevel.GetFloatValue("Volume.Level");
}
//-----------------------------------------------------------------
AudioPlayer::~AudioPlayer()
{
	m_volumeLevel.WriteChangesToINIFile();
}
//-----------------------------------------------------------------
}
