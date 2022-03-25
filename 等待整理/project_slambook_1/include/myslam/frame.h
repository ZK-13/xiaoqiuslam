#ifndef FRAME_H
#define FRAME_H

#include "myslam/camera.h"
#include "myslam/common_include.h"

namespace myslam {

// forward declare ��Ϊ�ڵ�ǰ���õ���������������Ҫ���ǰ������
class MapPoint;
class Frame {
 public:
  // ʵ�Σ� ���û��ͳ�����ߺ�����֮�䴫�ݲ����Ľӿ�
  // �βΣ� ����ͺ���֮��������ݵĽӿ�
  // ��Ĳ����� �������֮��������ݵĽӿ�
  // �����ռ�Ĳ����� �����ռ�֮��Ĳ�������
  // �����ļ�֮��Ĳ������ݣ� ͷ�ļ�
  // ����ļ�֮������Ĵ��ݣ� ͷ�ļ�
  // �ܽ�һ�¾��������ϱ����������� ������ ���� �����ռ����� static ����C�������������

  // ��ͨ�ֲ������洢�ڽ��� [ջ�ռ�]��ʹ����ϻ������ͷš�
  // ��̬�ֲ�����ʹ��static���η����壬��ʹ������ʱδ����ֵ��������Ҳ�������ʼ��Ϊ0��
  // �Ҿ�̬�ֲ������洢�ڽ��̵�[ȫ��������]����ʹ�������أ�����ֵҲ�ᱣ�ֲ��䡣
  // ������ȫ�������������ڴ�ռ䣻�������Զ������ʼ��
  // ��������Ϊ�ֲ������򣬵��������ĺ�������ʱ������������֮����
  typedef std::shared_ptr<Frame> Ptr;
  unsigned long id_;    // id of this frame
  double time_stamp_;   // when it is recorded
  SE3 T_c_w_;           // transform from world to camera
  Camera::Ptr camera_;  // Pinhole RGBD Camera model
  Mat color_, depth_;   // color and depth image
  // std::vector<cv::KeyPoint>      keypoints_;  // key points in image
  // std::vector<MapPoint*>         map_points_; // associated map points
  bool is_key_frame_;  // whether a key-frame
 public:  // data members
  Frame();
  Frame(long id, double time_stamp = 0, SE3 T_c_w = SE3(),
        Camera::Ptr camera = nullptr, Mat color = Mat(), Mat depth = Mat());
  ~Frame();

  // factory function
  static Frame::Ptr createFrame();

  // find the depth in depth map
  double findDepth(const cv::KeyPoint& kp);

  // Get Camera Center
  Vector3d getCamCenter() const;

  void setPose(const SE3& T_c_w);
  // check if a point is in this frame
  bool isInFrame(const Vector3d& pt_world);
};

}  // namespace myslam

#endif
