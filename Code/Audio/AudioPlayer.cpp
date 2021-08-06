#include "AudioPlayer.h"

namespace Audio
{
//-----------------------------------------------------------------
void AudioPlayer::Init()
{

}
//-----------------------------------------------------------------
void AudioPlayer::PlaySound(Resources::Sound& sound)
{
	MapSound::iterator lb = m_sounds.find(sound.GetFilePath());
	if (lb != m_sounds.end() || m_sounds.size() == 0)
	{
		m_sounds[sound.GetFilePath()] = &sound.GetSound();
	}
	m_sounds[sound.GetFilePath()]->play();
}
//-----------------------------------------------------------------
void AudioPlayer::PlayMusic(Resources::Music& music, bool repeat = false)
{
	MapMusic::iterator lb = m_musics.find(music.GetFilePath());
	if (lb != m_musics.end() || m_musics.size() == 0)
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
void AudioPlayer::SetMusicVolume(float volume)
{
	sf::Listener::setGlobalVolume(volume);
}
//-----------------------------------------------------------------
void AudioPlayer::SetSoundVolume(float volume)
{
	sf::Listener::setGlobalVolume(volume);
}
//-----------------------------------------------------------------
}
