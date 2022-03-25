#ifndef MAP_H
#define MAP_H

#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/mappoint.h"

namespace myslam {
class Map {
 public:
  // ��������һ������
  typedef shared_ptr<Map> Ptr;
  // map �����д洢������������ģ��� unordered_map ������������ġ�
  // unordered_map ������ map
  // ����һ�����Լ�ֵ�ԣ�pair���ͣ�����ʽ�洢���ݣ��洢�ĸ�����ֵ�Եļ�������ͬ�Ҳ������޸ġ�
  // std::unordered_map<std::string, std::string> umap{
  //    {"Python�̳�","http://python/"},
  //    {"Java�̳�","http:/java/"},
  //    {"Linux�̳�","http://linux/"} };
  unordered_map<unsigned long, MapPoint::Ptr> map_points_;  // all landmarks
  unordered_map<unsigned long, Frame::Ptr> keyframes_;      // all key-frames

  Map() {}

  void insertKeyFrame(Frame::Ptr frame);
  void insertMapPoint(MapPoint::Ptr map_point);
};
}  // namespace myslam

#endif  // MAP_H
