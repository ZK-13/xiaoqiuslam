#include "myslam/config.h"

/**
 * һ�������������ռ� ͷ�ļ���Դ���ļ���Ҫ���������ռ���
 * Ŀ����Ϊ�˸��������������
 */
namespace myslam {
/**
 * @brief �������Ǹ��ӳ������� ���� ���� ������������Ŀ�е�����
 * һ�ж���Ϊ�˱��� ���� ��ȡ�����ĺ���

 * @param filename
 * myslam::Config::setParameterFile ( argv[1] );������ô�����
 */
void Config::setParameterFile(const std::string& filename) {
  // �ж�����ָ������Ƿ���ڣ������ڲŻᴴ��һ�� config_ ����
  // ֻҪ�� new ��������ص�ָ�� p ����һ�� shared_ptr �����йܡ�
  if (config_ == nullptr) config_ = shared_ptr<Config>(new Config);
  // ��ĳ�Ա���� ���� �����Ƕ�ȡ�ļ�
  config_->file_ = cv::FileStorage(filename.c_str(), cv::FileStorage::READ);
  if (config_->file_.isOpened() == false) {
    std::cerr << "parameter file " << filename << " does not exist."
              << std::endl;
    config_->file_.release();
    return;
  }
}



// ������������
Config::~Config() {
  if (file_.isOpened()) file_.release();
}


// ���徲̬ȫ������ָ����� config_ ���Ǹ�����ʼֵ����˼
shared_ptr<Config> Config::config_ = nullptr;

}  // namespace myslam
