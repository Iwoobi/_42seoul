apt-get update
apt-get install -y sudo
# 패키지 관리자가 https를 이용할 수 있도록 설정
sudo apt-get install -y apt-transport-https
# ssl 통신이 가능하도록 CA(Certificate Authorities)로부터 인증서를 획득
sudo apt-get install -y ca-certificates
# 다양한 프로토콜을 지원하는 데이터 송수신 패키지
sudo apt-get install -y curl
# Repository를 추가 및 삭제할 수 있도록 설정하는 패키지
sudo apt-get install -y software-properties-common
sudo apt-get install -y git
sudo apt-get install -y make
sudo apt-get install -y vim
sudo apt-get install -y systemd
sudo apt-get install fonts-nanum
sudo apt-get install ibus ibus-hangul
# google 다운로드
# firefox는 자체적으로 http를 자동으로 https로 바꿈
 wget -O /tmp/google-chrome-stable_current_amd64.deb https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo apt install /tmp/google-chrome-stable_current_amd64.deb -y

# wordpress 다운로드
# wget -O /tmp/wordpress.tar.gz http://wordpress.org/latest.tar.gz
# sudo tar -xvzf /tmp/wordpress.tar.gz -C /home/chanhyle/data/

# 도커 컴포즈 3설치
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg lsb-release
sudo mkdir -p /etc/apt/keyrings
# 도커 패키지 신뢰성 추가
# 4 : download.docker.com에 IPv6로 접근 불가 -> IPv4로 강제.
# f - http의 요청 헤더의 Content-Type을 multipart/form-data로 설정
# s - silent로 진행과정 및 오류 생략
# S - SSL 이용
# L - curl의 결과가 Redirection이더라도, 해당 URL로 작업을 이어감
# 파이프 이후의 apt-key는 다운로드 받은 패키지를 인증된 패키지로 인식 시키기 위해 키 리스트에 패키지를 추가
# (apt는 기본적으로 인증된 패키지들을 키 리스트로 관리)
sudo curl -4fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
# ForceIPv4=true : download.docker.com에 IPv6로 접근 불가 -> IPv4로 강제.
sudo apt-get -o Acquire::ForceIPv4=true update -y
sudo apt-get install -o Acquire::ForceIPv4=true docker-ce docker-ce-cli containerd.io docker-compose-plugin
