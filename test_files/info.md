rst:0xc (SW_CPU_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:1184
load:0x40078000,len:13232
load:0x40080400,len:3028
entry 0x400805e4
[D] I2SStream.h : 55 - bool audio_tools::I2SStream::begin(audio_tools::I2SConfig)
[D] I2SESP32.h : 47 - bool audio_tools::I2SDriverESP32::begin(audio_tools::I2SConfigESP32)
[D] I2SESP32.h : 161 - bool audio_tools::I2SDriverESP32::begin(audio_tools::I2SConfigESP32, int, int)
[I] AudioTypes.h : 104 - sample_rate: 44100
[I] AudioTypes.h : 105 - channels: 2
[I] AudioTypes.h : 106 - bits_per_sample: 16
[I] I2SConfigESP32.h : 90 - rx/tx mode: TX_MODE
[I] I2SConfigESP32.h : 91 - port_no: 0
[I] I2SConfigESP32.h : 92 - is_master: Master
[I] I2SConfigESP32.h : 93 - sample rate: 44100
[I] I2SConfigESP32.h : 94 - bits per sample: 16
[I] I2SConfigESP32.h : 95 - number of channels: 2
[I] I2SConfigESP32.h : 96 - signal_type: Digital
[I] I2SConfigESP32.h : 98 - i2s_format: I2S_STD_FORMAT
[I] I2SConfigESP32.h : 100 - auto_clear: true
[I] I2SConfigESP32.h : 102 - use_apll: true
[I] I2SConfigESP32.h : 107 - buffer_count:6
[I] I2SConfigESP32.h : 108 - buffer_size:512
[I] I2SConfigESP32.h : 113 - pin_bck: 27
[I] I2SConfigESP32.h : 115 - pin_ws: 32
[I] I2SConfigESP32.h : 117 - pin_data: 33
[D] I2SESP32.h : 193 - i2s_driver_install
[D] I2SESP32.h : 210 - i2s_set_pin
[D] I2SESP32.h : 221 - i2s_zero_dma_buffer
[D] I2SESP32.h : 225 - begin - started
[I] AudioEncoded.h : 269 - virtual void audio_tools::EncodedAudioOutput::setNotifyAudioChange(audio_tools::AudioInfoSupport&)
[D] CodecMP3Helix.h : 122 - virtual void audio_tools::MP3DecoderHelix::setNotifyAudioChange(audio_tools::AudioInfoSupport&)
[D] AudioEncoded.h : 329 - virtual bool audio_tools::EncodedAudioOutput::begin()
[D] AudioEncoded.h : 331 - virtual bool audio_tools::EncodedAudioOutput::begin()
[D] AudioEncoded.h : 28 - virtual void audio_tools::AudioDecoder::setAudioInfo(audio_tools::AudioInfo)
[D] CodecMP3Helix.h : 77 - virtual void audio_tools::MP3DecoderHelix::begin()
[D] MetaDataFilter.h : 30 - void audio_tools::MetaDataFilter<Decoder>::begin() [with Decoder = libhelix::MP3DecoderHelix]
[I] URLStream.h : 86 - virtual bool audio_tools::URLStream::begin(const char*, const char*, MethodID, const char*, const char*): http://stream.srg-ssr.ch/m/rsj/mp3_128
[D] URLStream.h : 302 - bool audio_tools::URLStream::preProcess(const char*, const char*)
[D] StrExt.h : 166 - grow(38)
[D] Url.h : 60 - setUrl http://stream.srg-ssr.ch/m/rsj/mp3_128
[D] StrExt.h : 166 - grow(38)
[I] Url.h : 74 - Url::parse
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(24)
[I] Url.h : 112 - url->http://stream.srg-ssr.ch/m/rsj/mp3_128
[I] Url.h : 113 - host->stream.srg-ssr.ch
[I] Url.h : 114 - protocol->http
[I] Url.h : 115 - path->/m/rsj/mp3_128
[I] Url.h : 116 - port->80
[I] URLStream.h : 417 - void audio_tools::URLStream::login()
.
[I] URLStream.h : 392 - WiFiClient
[D] URLStream.h : 350 - int audio_tools::URLStream::process(MethodID, audio_tools::Url&, const char*, T, int) [with T = const char*]
[D] HttpRequest.h : 222 - virtual bool audio_tools::HttpRequest::processBegin(MethodID, audio_tools::Url&, const char*, int)
[I] HttpRequest.h : 233 - process connecting to host stream.srg-ssr.ch port 80
[I] HttpRequest.h : 350 - connected 1 timeout 60000
[I] HttpRequest.h : 244 - Free heap: 183228
[D] HttpHeader.h : 414 - HttpRequestHeader::setValues - path: /m/rsj/mp3_128
[D] HttpHeader.h : 106 - HttpHeader::put Host stream.srg-ssr.ch
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Host' : 'stream.srg-ssr.ch'
[D] StrExt.h : 166 - grow(17)
[D] HttpHeader.h : 106 - HttpHeader::put Connection keep-alive
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Connection' : 'keep-alive'
[D] StrExt.h : 166 - grow(10)
[D] HttpHeader.h : 125 - HttpHeader::put - value ignored because it is null for User-Agent
[D] HttpHeader.h : 106 - HttpHeader::put Accept-Encoding identity
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Accept-Encoding' : 'identity'
[D] StrExt.h : 166 - grow(8)
[D] HttpHeader.h : 106 - HttpHeader::put Accept */*
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Accept' : '*/*'
[D] StrExt.h : 166 - grow(3)
[D] HttpHeader.h : 125 - HttpHeader::put - value ignored because it is null for Content-Type
[I] HttpHeader.h : 280 - HttpHeader::write
[D] HttpHeader.h : 423 - HttpRequestHeader::write1stLine
[I] HttpHeader.h : 438 - -> GET /m/rsj/mp3_128 HTTP/1.1
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Host
[I] HttpHeader.h : 206 -  -> Host: stream.srg-ssr.ch
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Connection
[I] HttpHeader.h : 206 -  -> Connection: keep-alive 
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Accept-Encoding
[I] HttpHeader.h : 206 -  -> Accept-Encoding: identity
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Accept
[I] HttpHeader.h : 206 -  -> Accept: */*
[I] HttpHeader.h : 357 -  -> <CR LF>
[I] HttpRequest.h : 299 - Request written ... waiting for reply
[D] HttpHeader.h : 235 - HttpHeader::read
[I] HttpHeader.h : 248 - Waiting for data...
[I] HttpHeader.h : 257 - Data available: 5648
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> HTTP/1.1 200 OK
[D] HttpHeader.h : 509 - HttpReplyHeader::parse1stLine: HTTP/1.1 200 OK
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Content-Type: audio/mpeg
[D] HttpHeader.h : 148 - HttpHeader::put -> Content-Type: audio/mpeg
[D] HttpHeader.h : 106 - HttpHeader::put Content-Type audio/mpeg
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Content-Type' : 'audio/mpeg'
[D] StrExt.h : 166 - grow(10)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Date: Sat, 02 Mar 2024 03:43:39 GMT
[D] HttpHeader.h : 148 - HttpHeader::put -> Date: Sat, 02 Mar 2024 03:43:39 GMT
[D] HttpHeader.h : 106 - HttpHeader::put Date Sat, 02 Mar 2024 03:43:39 GMT
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Date' : 'Sat, 02 Mar 2024 03:43:39 GMT'
[D] StrExt.h : 166 - grow(29)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-br:128
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-br:128
[D] HttpHeader.h : 106 - HttpHeader::put icy-br 128
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-br' : '128'
[D] StrExt.h : 166 - grow(3)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> ice-audio-info: bitrate=128
[D] HttpHeader.h : 148 - HttpHeader::put -> ice-audio-info: bitrate=128
[D] HttpHeader.h : 106 - HttpHeader::put ice-audio-info bitrate=128
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'ice-audio-info' : 'bitrate=128'
[D] StrExt.h : 166 - grow(11)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-br:128
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-br:128
[D] HttpHeader.h : 106 - HttpHeader::put icy-br 128
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-br' : '128'
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-description:SwissJazz_MP3@128Kbps
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-description:SwissJazz_MP3@128Kbps
[D] HttpHeader.h : 106 - HttpHeader::put icy-description SwissJazz_MP3@128Kbps
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-description' : 'SwissJazz_MP3@128Kbps'
[D] StrExt.h : 166 - grow(21)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-genre:Entertainment
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-genre:Entertainment
[D] HttpHeader.h : 106 - HttpHeader::put icy-genre Entertainment
[D] StrExt.h : 166 - grow(9)
[D] StrExt.h : 166 - grow(9)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(9)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-genre' : 'Entertainment'
[D] StrExt.h : 166 - grow(13)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-mimetype:audio/mpeg
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-mimetype:audio/mpeg
[D] HttpHeader.h : 106 - HttpHeader::put icy-mimetype audio/mpeg
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-mimetype' : 'audio/mpeg'
[D] StrExt.h : 166 - grow(10)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-name:/SwissJazz_Room1
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-name:/SwissJazz_Room1
[D] HttpHeader.h : 106 - HttpHeader::put icy-name /SwissJazz_Room1
[D] StrExt.h : 166 - grow(8)
[D] StrExt.h : 166 - grow(8)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(8)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-name' : '/SwissJazz_Room1'
[D] StrExt.h : 166 - grow(16)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-pub:0
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-pub:0
[D] HttpHeader.h : 106 - HttpHeader::put icy-pub 0
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-pub' : '0'
[D] StrExt.h : 166 - grow(1)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> icy-url:www.srgssr.ch
[D] HttpHeader.h : 148 - HttpHeader::put -> icy-url:www.srgssr.ch
[D] HttpHeader.h : 106 - HttpHeader::put icy-url www.srgssr.ch
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'icy-url' : 'www.srgssr.ch'
[D] StrExt.h : 166 - grow(13)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Server: Icecast 2.4.0-kh10
[D] HttpHeader.h : 148 - HttpHeader::put -> Server: Icecast 2.4.0-kh10
[D] HttpHeader.h : 106 - HttpHeader::put Server Icecast 2.4.0-kh10
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Server' : 'Icecast 2.4.0-kh10'
[D] StrExt.h : 166 - grow(18)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Cache-Control: no-cache, no-store
[D] HttpHeader.h : 148 - HttpHeader::put -> Cache-Control: no-cache, no-store
[D] HttpHeader.h : 106 - HttpHeader::put Cache-Control no-cache, no-store
[D] StrExt.h : 166 - grow(13)
[D] StrExt.h : 166 - grow(13)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(13)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Cache-Control' : 'no-cache, no-store'
[D] StrExt.h : 166 - grow(18)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Access-Control-Allow-Origin: *
[D] HttpHeader.h : 148 - HttpHeader::put -> Access-Control-Allow-Origin: *
[D] HttpHeader.h : 106 - HttpHeader::put Access-Control-Allow-Origin *
[D] StrExt.h : 166 - grow(27)
[D] StrExt.h : 166 - grow(27)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(27)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Access-Control-Allow-Origin' : '*'
[D] StrExt.h : 166 - grow(1)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Access-Control-Allow-Headers: Origin, Accept, X-Requested-With, Content-Type
[D] HttpHeader.h : 148 - HttpHeader::put -> Access-Control-Allow-Headers: Origin, Accept, X-Requested-With, Content-Type
[D] HttpHeader.h : 106 - HttpHeader::put Access-Control-Allow-Headers Origin, Accept, X-Requested-With, Content-Type
[D] StrExt.h : 166 - grow(28)
[D] StrExt.h : 166 - grow(28)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(28)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Access-Control-Allow-Headers' : 'Origin, Accept, X-Requested-With, Content-Type'
[D] StrExt.h : 166 - grow(46)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Access-Control-Allow-Methods: GET, OPTIONS, HEAD
[D] HttpHeader.h : 148 - HttpHeader::put -> Access-Control-Allow-Methods: GET, OPTIONS, HEAD
[D] HttpHeader.h : 106 - HttpHeader::put Access-Control-Allow-Methods GET, OPTIONS, HEAD
[D] StrExt.h : 166 - grow(28)
[D] StrExt.h : 166 - grow(28)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(28)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Access-Control-Allow-Methods' : 'GET, OPTIONS, HEAD'
[D] StrExt.h : 166 - grow(18)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Connection: Close
[D] HttpHeader.h : 148 - HttpHeader::put -> Connection: Close
[D] HttpHeader.h : 106 - HttpHeader::put Connection Close
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Connection' : 'Close'
[D] StrExt.h : 166 - grow(5)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Expires: Mon, 26 Jul 1997 05:00:00 GMT
[D] HttpHeader.h : 148 - HttpHeader::put -> Expires: Mon, 26 Jul 1997 05:00:00 GMT
[D] HttpHeader.h : 106 - HttpHeader::put Expires Mon, 26 Jul 1997 05:00:00 GMT
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Expires' : 'Mon, 26 Jul 1997 05:00:00 GMT'
[D] StrExt.h : 166 - grow(29)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> 
[I] HttpRequest.h : 175 - no CONTENT_LENGTH found in reply
[I] URLStream.h : 94 - size: 0
[D] URLStream.h : 248 - virtual bool audio_tools::URLStream::waitForData(int)
[D] URLStream.h : 262 - available: 6493
[I] URLStream.h : 101 - ==> http status: 200
[D] StreamCopy.h : 97 - copy
[D] URLStream.h : 140 - available: 6493
[D] StreamCopy.h : 177 - available: 6493
[D] HttpRequest.h : 120 - virtual int audio_tools::HttpRequest::read(uint8_t*, int)
[D] URLStream.h : 152 - readBytes 1024 -> 1024
[D] StreamCopy.h : 332 - write: 1024
[D] AudioEncoded.h : 366 - EncodedAudioOutput::write: 1024
[D] CodecMP3Helix.h : 106 - virtual size_t audio_tools::MP3DecoderHelix::write(const void*, size_t): 1024
[D] AudioEncoded.h : 382 - EncodedAudioOutput::write: 1024 -> 1024
[D] StreamCopy.h : 338 - write: 1024 -> 1024
[I] StreamCopy.h : 143 - StreamCopy::copy  1024 -> 1024 -> 1024 bytes - in 1 hops
[D] StreamCopy.h : 97 - copy
[D] URLStream.h : 140 - available: 5469
[D] StreamCopy.h : 177 - available: 5469
[D] HttpRequest.h : 120 - virtual int audio_tools::HttpRequest::read(uint8_t*, int)
[D] URLStream.h : 152 - readBytes 1024 -> 1024
[D] StreamCopy.h : 332 - write: 1024
[D] AudioEncoded.h : 366 - EncodedAudioOutput::write: 1024
[D] CodecMP3Helix.h : 106 - virtual size_t audio_tools::MP3DecoderHelix::write(const void*, size_t): 1024
[D] I2SStream.h : 88 - I2SStream::write: 4608
[D] I2SESP32.h : 85 - size_t audio_tools::I2SDriverESP32::writeBytes(const void*, size_t)
[D] I2SESP32.h : 92 - i2s_write 4608 -> 4608 bytes
[D] I2SStream.h : 88 - I2SStream::write: 4608
[D] I2SESP32.h : 85 - size_t audio_tools::I2SDriverESP32::writeBytes(const void*, size_t)
[D] I2SESP32.h : 92 - i2s_write 4608 -> 4608 bytes
[D] AudioEncoded.h : 382 - EncodedAudioOutput::write: 1024 -> 1024
[D] StreamCopy.h : 338 - write: 1024 -> 1024
[I] StreamCopy.h : 143 - StreamCopy::copy  1024 -> 1024 -> 1024 bytes - in 1 hops
[D] StreamCopy.h : 97 - copy
[D] URLStream.h : 140 - available: 4445
[D] StreamCopy.h : 177 - available: 4445
[D] HttpRequest.h : 120 - virtual int audio_tools::HttpRequest::read(uint8_t*, int)
[D] URLStream.h : 152 - readBytes 1024 -> 1024
[D] StreamCopy.h : 332 - write: 1024
[D] AudioEncoded.h : 366 - EncodedAudioOutput::write: 1024
[D] CodecMP3Helix.h : 106 - virtual size_t audio_tools::MP3DecoderHelix::write(const void*, size_t): 1024
[D] I2SStream.h : 88 - I2SStream::write: 4608
[D] I2SESP32.h : 85 - size_t audio_tools::I2SDriverESP32::writeBytes(const void*, size_t)
[D] I2SESP32.h : 92 - i2s_write 4608 -> 4608 bytes
[D] I2SStream.h : 88 - I2SStream::write: 4608
[D] I2SESP32.h : 85 - size_t audio_tools::I2SDriverESP32::writeBytes(const void*, size_t)
[D] I2SESP32.h : 92 - i2s_write 4608 -> 4608 bytes
[D] AudioEncoded.h : 382 - EncodedAudioOutput::write: 1024 -> 1024
[D] StreamCopy.h : 338 - write: 1024 -> 1024
[I] StreamCopy.h : 143 - StreamCopy::copy  1024 -> 1024 -> 1024 bytes - in 1 hops
[D] StreamCopy.h : 97 - copy
[D] URLStream.h : 140 - available: 3421
[D] StreamCopy.h : 177 - available: 3421
[D] HttpRequest.h : 120 - virtual int audio_tools::HttpRequest::read(uint8_t*, int)
[D] URLStream.h : 152 - readBytes 1024 -> 1024
[D] StreamCopy.h : 332 - write: 1024
[D] AudioEncoded.h : 366 - EncodedAudioOutput::write: 1024
[D] CodecMP3Helix.h : 106 - virtual size_t audio_tools::MP3DecoderHelix::write(const void*, size_t): 1024
[D] I2SStream.h : 88 - I2SStream::write: 4608